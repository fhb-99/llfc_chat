#ifndef LOGIN_H
#define LOGIN_H
/******************************************************************************
 *
 * @file       login.h
 * @brief      登录界面 Function
 *
 * @author     cjh
 * @date       2025/10/19
 * @history
 *****************************************************************************/
#include <QDialog>
#include "global.h"

namespace Ui {
class Dialog;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private:
    Ui::Dialog *ui;

    int _Id;
    QString _token;

    // 初始化登陆界面图片
    void initHead();
    // 检验输入框内数据是否合法
    bool checkUser();
    bool checkPasswd();

    // 处理http回包数据
    void initHttpHandlers();
    QMap<ReqId, std::function<void(const QJsonObject&)>> m_handlers;
signals:
    // 切换界面的信号
    void sigSwitchReset();
    void switchRegistr();

    // 给tcp发送登录请求-长连接
    void sig_tcp_connect(ServerInfo si);

private slots:
    void slot_login_mod_finish(ReqId id, QString res, ErrorCodes err);
    void slot_tcp_con_finish(bool flag);
    void slot_login_failed(int);

    void on_forget_pass_clicked();
    void on_login_clicked();

};

#endif // LOGIN_H
