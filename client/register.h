#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include "global.h"

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_get_verify_clicked();
    void slot_req_mod_finish(ReqId id, QString res, ErrorCodes err);

    void on_yes_btn_clicked();

    void on_no_btn_clicked();

private:
    void initHttpHandlers();
    void showTip(QString str, bool b_ok);
    QMap<ReqId, std::function<void(const QJsonObject&)>> m_handlers;
    Ui::Register *ui;

    // 显示输入框内的数据是否符合规则
    QMap<TipErr, QString> m_tip_errs;
    void addTipErr(TipErr err, QString tp);
    void delTipErr(TipErr err, QString tp = "");

    bool checkUser();
    bool checkPasswd();
    bool checkEmail();
    bool checkConfirm();
    bool checkVarifyCode();

signals:
    // 发送给注册成功界面信号
    void sigRegisterYes();
    // 通知主界面，取消注册
    void sigSwitchLogin();
};

#endif // REGISTER_H
