#include "tcpmgr.h"
#include "usermgr.h"

TcpMgr::TcpMgr(QObject *parent)
    : QObject{parent}, _host(""), _port(0), _b_recv_pending(false),
    _message_id(0), _message_len(0)
{
    QObject::connect(&_socket, &QTcpSocket::connected, [&](){
        qDebug() << "connect to server succeed";
        // 发送信号
        emit sig_con_success(true);
    });
    
    QObject::connect(&_socket, &QTcpSocket::readyRead, [&](){
        // 判断有数据可读时，将所有数据推入到缓冲区
        _buffer.append(_socket.readAll());
        QDataStream stream(&_buffer, QIODevice::ReadOnly);
        stream.setVersion(QDataStream::Qt_6_10);
        while(true)
        {
            // 先解析头部
            if(!_b_recv_pending)
            {
                // 检测缓冲区的数据是否可以满足解析一个数据头（数据id + 数据len）
                if(_buffer.size() < static_cast<int>(sizeof(quint16) * 2))
                {
                    // 长度不满足
                    return;
                }
                // 预读取数据id和len,但不从缓冲区移除
                stream >> _message_id >> _message_len;
                qDebug() << "message id : " << _message_id << ", " << "message len : " << _message_len;
            }

            // 判断消息体长度是否满足
            _buffer = _buffer.mid(sizeof(quint16) * 2);
            if(_buffer.size() < _message_len)
            {
                _b_recv_pending = true;
                return;
            }

            _b_recv_pending = false;
            // 读出消息体中的数据
            QByteArray data = _buffer.mid(0, _message_len);
            qDebug() << "data is : " << data;

            // 将读出的数据从缓冲区移除
            _buffer = _buffer.mid(_message_len);
            HandlerMsg(ReqId(_message_id), _message_len, data);
        }
    });


    //5.15 之后版本
    QObject::connect(&_socket, QOverload<QAbstractSocket::SocketError>::of(&QTcpSocket::errorOccurred), [&](QAbstractSocket::SocketError socketError) {
        Q_UNUSED(socketError)
        qDebug() << "Error:" << _socket.errorString();
    });

    // 处理错误（适用于Qt 5.15之前的版本）
    // QObject::connect(&_socket, static_cast<void (QTcpSocket::*)(QTcpSocket::SocketError)>(&QTcpSocket::error),
    //                  [&](QTcpSocket::SocketError socketError) {
    //                      qDebug() << "Error:" << _socket.errorString() ;
    //                      switch (socketError) {
    //                      case QTcpSocket::ConnectionRefusedError:
    //                          qDebug() << "Connection Refused!";
    //                          emit sig_con_success(false);
    //                          break;
    //                      case QTcpSocket::RemoteHostClosedError:
    //                          qDebug() << "Remote Host Closed Connection!";
    //                          break;
    //                      case QTcpSocket::HostNotFoundError:
    //                          qDebug() << "Host Not Found!";
    //                          emit sig_con_success(false);
    //                          break;
    //                      case QTcpSocket::SocketTimeoutError:
    //                          qDebug() << "Connection Timeout!";
    //                          emit sig_con_success(false);
    //                          break;
    //                      case QTcpSocket::NetworkError:
    //                          qDebug() << "Network Error!";
    //                          break;
    //                      default:
    //                          qDebug() << "Other Error!";
    //                          break;
    //                      }
    //                  });

    // 处理连接断开
    QObject::connect(&_socket, &QTcpSocket::disconnected, [&]() {
        qDebug() << "Disconnected from server.";
    });

    // 当登录成功时，在login中的tcpmgr实例对象发送信号，用户可以进行通信
    QObject::connect(this, &TcpMgr::sig_send_data, this, &TcpMgr::slot_send_data);

    InitHandlers();
}

void TcpMgr::HandlerMsg(ReqId reqid, int len, QByteArray data)
{
    auto tmp = m_handlers.find(reqid);
    if(tmp == m_handlers.end())
    {
        qDebug()<< "not found id ["<< reqid << "] to handle";
        return ;
    }
    m_handlers[reqid](reqid, len, data);
    // tmp.value()(reqid, len, data);
}

void TcpMgr::InitHandlers()
{
    m_handlers.insert(ReqId::ID_CHAT_LOGIN_RSP, [this](ReqId reqid, int len, QByteArray data){
        qDebug() << "handler id is : " << reqid << "data is : " << data;
        // 将QByteArray转为QJsonDocument
        QJsonDocument json_doc = QJsonDocument::fromJson(data);
        if(json_doc.isNull())
        {
            qDebug() << "Failed to create QJsonDocument";
            return;
        }

        QJsonObject json_obj = json_doc.object();

        if(!json_obj.contains("error"))
        {
            int err = ErrorCodes::ERR_JSON;
            qDebug() << "Login failed, error is Json Parse Error " << err;
            emit sig_login_failed(err);
            return;
        }

        int error = json_obj["error"].toInt();
        if(error != ErrorCodes::SUCCESS)
            {
            qDebug() << "Login Failed , error is " << error;
            emit sig_login_failed(error);
            return;
        }

        // 成功解析
        UserMgr::getInstance()->setId(json_obj["id"].toInt());
        UserMgr::getInstance()->setName(json_obj["name"].toString());
        UserMgr::getInstance()->setToken(json_obj["token"].toString());
        // 发送切换主界面
        emit sig_switch_chat();
    });
}

void TcpMgr::slot_tcp_connect(ServerInfo si)
{
    qDebug()<< "receive tcp connect signal";
    // 尝试连接到服务器
    qDebug() << "Connecting to server...";
    _host = si.Host;
    _port = static_cast<uint16_t>(si.Port.toUInt());
    _socket.connectToHost(si.Host, _port);
}

void TcpMgr::slot_send_data(ReqId reqid, QString data)
{
    uint16_t id = reqid;

    // 将要发送的数据data转为utf-8编码的字节数组
    QByteArray dataarray = data.toUtf8();

    // 计算长度（使用网络字节序转换）
    quint16 len = static_cast<quint16>(data.size());

    // 创建一个QByteArray用于存储要发送的所有数据
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);

    // 设置数据流使用网络字节序
    out.setByteOrder(QDataStream::BigEndian);

    // 写入ID和长度
    out << id << len;

    // 添加字符串数据
    block.append(dataarray);

    // 发送数据
    _socket.write(block);

}
