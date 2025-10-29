#ifndef TCPMGR_H
#define TCPMGR_H

#include <QObject>
#include <QTcpSocket>
#include "global.h"
#include "singleton.h"

class TcpMgr : public QObject, public Singleton<TcpMgr>,
               public std::enable_shared_from_this<TcpMgr>
{
    Q_OBJECT
public:
    explicit TcpMgr(QObject *parent = nullptr);

private:
    QTcpSocket _socket;
    QString _host;
    uint16_t _port;
    // false：表示当前没有待处理的消息，需要解析新的消息头部
    // true：表示已经解析了消息头部，正在等待消息体数据
    bool _b_recv_pending;
    quint16 _message_id;
    quint16 _message_len;
    QByteArray _buffer;

public slots:
    void slot_tcp_connect(ServerInfo si);
    void slot_send_data(ReqId reqid, QString array);

signals:
    void sig_con_success(bool flag);
    void sig_send_data(ReqId reqid, QString array);
};

#endif // TCPMGR_H
