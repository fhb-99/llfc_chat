#include "login.h"
#include "ui_login.h"
#include "httpmgr.h"
#include "tcpmgr.h"
#include <QPainter>
#include <QPainterPath>

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);


    // 在登陆界面点击注册时，发射信号给主界面来切换注册界面
    connect(ui->reg_user, &QPushButton::clicked, this, &Login::switchRegistr);
    
    // 连接忘记密码按钮
    connect(ui->forget_pass, &QPushButton::clicked, this, &Login::on_forget_pass_clicked);

    // 显示头像
    initHead();

    // 连接信号槽，来接受http请求完成回包
    connect(HttpMgr::getInstance().get(), &HttpMgr::sig_login_mod_finish, this, &Login::slot_login_mod_finish);

    // 发送tcp连接请求
    connect(this, &Login::sig_tcp_connect, TcpMgr::getInstance().get(), &TcpMgr::slot_tcp_connect);
    // 接受tcp连接成功信号
    connect(TcpMgr::getInstance().get(), &TcpMgr::sig_con_success, this, &Login::slot_tcp_con_finish);

}

Login::~Login()
{
    qDebug() << "Login is destruct ";
    delete ui;
}

void Login::initHead()
{
    // 加载图片
    QPixmap originalPixmap(":/image/head_1.jpg");
    // 设置图片自动缩放
    qDebug()<< originalPixmap.size() << ui->label->size();
    originalPixmap = originalPixmap.scaled(ui->label->size(),
                                           Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);

    // 创建一个和原始图片相同大小的QPixmap，用于绘制圆角图片
    QPixmap roundedPixmap(originalPixmap.size());
    roundedPixmap.fill(Qt::transparent); // 用透明色填充

    QPainter painter(&roundedPixmap);
    painter.setRenderHint(QPainter::Antialiasing); // 设置抗锯齿，使圆角更平滑
    painter.setRenderHint(QPainter::SmoothPixmapTransform);

    // 使用QPainterPath设置圆角
    QPainterPath path;
    path.addRoundedRect(0, 0, originalPixmap.width(), originalPixmap.height(), 10, 10); // 最后两个参数分别是x和y方向的圆角半径
    painter.setClipPath(path);

    // 将原始图片绘制到roundedPixmap上
    painter.drawPixmap(0, 0, originalPixmap);

    // 设置绘制好的圆角图片到QLabel上
    ui->label->setPixmap(roundedPixmap);
}

bool Login::checkUser()
{
    auto username = ui->user_name->text();
    if(username.isEmpty())
    {
        qDebug() << "user name is null";
        return false;
    }
    return true;
}

bool Login::checkPasswd()
{
    auto passwd = ui->password->text();
    if(passwd.length() < 6 || passwd.length() > 15)
    {
        qDebug() << "password length is invalid";
        return false;
    }
    return true;
}

void Login::initHttpHandlers()
{
    // 注册回包逻辑
    m_handlers.insert(ReqId::ID_LOGIN_USER, [&](const QJsonObject& jsonObj){
        int error = jsonObj["error"].toInt();
        if(error != ErrorCodes::SUCCESS)
        {
            qDebug() << "http fialed";
            return;
        }
        auto user = jsonObj["user"].toString();
        qDebug() << "登录成功";
        qDebug() << "user name is : " << user;

        // 发送信号通知tcpMgr发送长链接
        ServerInfo si;
        si.Id = jsonObj["id"].toInt();
        si.Host = jsonObj["host"].toString();
        si.Port = jsonObj["port"].toString();
        si.Token = jsonObj["token"].toString();

        _Id = si.Id;
        _token = si.Token;
        qDebug()<< "user is " << user << " uid is " << si.Id <<" host is "
                 << si.Host << " Port is " << si.Port << " Token is " << si.Token;
        emit sig_tcp_connect(si);
    });
}

void Login::slot_login_mod_finish(ReqId id, QString res, ErrorCodes err)
{
    if(err != ErrorCodes::SUCCESS)
    {
        qDebug() << "login failed";
        return;
    }

    // 解析 JSON 字符串,res需转化为QByteArray
    QJsonDocument jsonDoc = QJsonDocument::fromJson(res.toUtf8());
    //json解析错误
    if(jsonDoc.isNull()){
        qDebug() << "json data error";
        return;
    }

    //json解析错误
    if(!jsonDoc.isObject()){
        qDebug() << "json data error";
        return;
    }
    // 执行处理http请求回包的回调函数
    m_handlers[id](jsonDoc.object());
    return;
}

void Login::slot_tcp_con_finish(bool flag)
{
    if(flag == true)
    {
        qDebug() << "聊天服务连接成功，正在登录...";
        QJsonObject jsonObj;
        jsonObj["id"] = _Id;
        jsonObj["token"] = _token;

        QJsonDocument doc(jsonObj);
        QString jsonString = doc.toJson(QJsonDocument::Indented);

        //发送tcp请求给chat server
        TcpMgr::getInstance()->sig_send_data(ReqId::ID_CHAT_LOGIN, jsonString);

    }else{
        qDebug() << "异常。。。";
    }
}


void Login::on_forget_pass_clicked()
{
    // 忘记密码，切换忘记密码界面
    qDebug() << "忘记密码按钮被点击";
    emit sigSwitchReset();
}

void Login::on_login_clicked()
{
    qDebug() << "login is clicked";
    if(!checkUser() || !checkPasswd())
    {
        return;
    }
    auto user = ui->user_name->text();
    auto passwd = ui->password->text();

    // 发送http请求
    QJsonObject json_obj;
    json_obj["user"] = user;
    json_obj["passwd"] = xorString(passwd);
    HttpMgr::getInstance()->PostHttpReq(QUrl(gate_url_prefix+"/user_login"),
                                        json_obj, ReqId::ID_LOGIN_USER, Modules::LOGINMOD);

}

