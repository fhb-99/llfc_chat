#include "register.h"
#include "ui_register.h"
#include "global.h"
#include "httpmgr.h"
#include "clickedlabel.h"

Register::Register(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Register)
{
    ui->setupUi(this);

    ui->err_tip->setProperty("state", "normal");
    repolish(ui->err_tip);

    // 连接HTTP响应信号
    auto httpMgr = HttpMgr::getInstance();
    if(httpMgr && httpMgr.get()) {
        connect(httpMgr.get(), &HttpMgr::sig_reg_mod_finish,
                this, &Register::slot_req_mod_finish);
    } else {
        qDebug() << "HttpMgr 单例对象未正确初始化";
    }

    initHttpHandlers();

    // 判断输入框内数据是否合法
    connect(ui->reg_username, &QLineEdit::editingFinished, this, [this](){
        checkUser();
    });
    connect(ui->reg_password, &QLineEdit::editingFinished, this, [this](){
        checkPasswd();
    });
    connect(ui->reg_passwd_again, &QLineEdit::editingFinished, this, [this](){
        checkConfirm();
    });
    connect(ui->reg_emial, &QLineEdit::editingFinished, this, [this](){
        checkEmail();
    });
    connect(ui->reg_verify, &QLineEdit::editingFinished, this, [this](){
        checkVarifyCode();
    });

    // 设置眼睛来决定密码样式
    // 设置鼠标光标进入之后的样式
    ui->pass_visible->setCursor(Qt::PointingHandCursor);
    ui->confirm_visible->setCursor(Qt::PointingHandCursor);

    // 默认密码不可见
    ui->pass_visible->SetState("unvisible","unvisible_hover","","visible",
                               "visible_hover","");

    ui->confirm_visible->SetState("unvisible","unvisible_hover","","visible",
                                  "visible_hover","");

    ui->reg_password->setEchoMode(QLineEdit::Password);
    ui->reg_passwd_again->setEchoMode(QLineEdit::Password);

    connect(ui->pass_visible, &ClickedLabel::Clicked, this, [&](){
        // 设置密码样式
        auto tmp = ui->pass_visible->GetCurState();
        if(tmp == ClickLbState::Normal)
        {
            ui->reg_password->setEchoMode(QLineEdit::Password);
        }
        else
        {
            ui->reg_password->setEchoMode(QLineEdit::Normal);
        }

    });
    connect(ui->confirm_visible, &ClickedLabel::Clicked, this, [&](){
        // 设置密码样式
        auto tmp = ui->confirm_visible->GetCurState();
        if(tmp == ClickLbState::Normal)
        {
            ui->reg_passwd_again->setEchoMode(QLineEdit::Password);
        }
        else
        {
            ui->reg_passwd_again->setEchoMode(QLineEdit::Normal);
        }
    });
}

Register::~Register()
{
    qDebug() << "Register is destruct ";
    delete ui;
}

void Register::on_get_verify_clicked()
{
    auto email = ui->reg_emial->text();
    QRegularExpression regex(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
    bool match = regex.match(email).hasMatch();
    if(match)
    {
        // 发送http验证码
        QJsonObject json_obj;
        json_obj["email"] = email;
        auto httpMgr = HttpMgr::getInstance();
        if(httpMgr && httpMgr.get()) {
            httpMgr->PostHttpReq(QUrl(gate_url_prefix+"/get_varifycode"),
                                json_obj, ReqId::ID_DET_VERIFY_CODE, Modules::REGISTERMOD);
        } else {
            qDebug() << "HttpMgr 单例对象未正确初始化";
        }
    }
    else
    {
        showTip(tr("邮箱地址不正确"), false);
    }
}

void Register::slot_req_mod_finish(ReqId id, QString res, ErrorCodes err)
{
    if(err != ErrorCodes::SUCCESS)
    {
        showTip(tr("网络请求错误"), false);
        return;
    }

    // 解析json 字符串， res 转换为QByteArray
    QJsonDocument jsonDoc = QJsonDocument::fromJson(res.toUtf8());
    if(jsonDoc.isNull())
    {
        showTip(tr("json解析失败"), false);
        return;
    }

    //json解析错误
    if(!jsonDoc.isObject())
    {
        showTip(tr("json解析错误"),false);
        return;
    }

    m_handlers[id](jsonDoc.object());
    return;
}

void Register::initHttpHandlers()
{
    // 注册获取验证码回包的逻辑
    m_handlers.insert(ReqId::ID_DET_VERIFY_CODE, [this](const QJsonObject& jsonObj){
        int error = jsonObj["error"].toInt();
        if(error != ErrorCodes::SUCCESS)
        {
            showTip(tr("参数错误"), false);
            qDebug() << "参数错误";
            return;
        }

        auto email = jsonObj["emial"].toString();
        showTip(tr("验证码已发送至邮箱，注意查收"), true);
        qDebug() << "email is : " << email;
    });

    // 注册注册用户回包的逻辑
    m_handlers.insert(ReqId::ID_REG_USER, [this](const QJsonObject& jsonObj){
        int error = jsonObj["error"].toInt();
        if(error != ErrorCodes::SUCCESS)
        {
            showTip(tr("注册失败"), false);
            qDebug() << "注册失败，错误代码:" << error;
            return;
        }

        auto email = jsonObj["email"].toString();
        showTip(tr("用户注册成功"), true);
        qDebug() << "注册成功";
        qDebug()<< "email is " << email;
        // 发送给main窗口，来显示注册成功窗口
        emit sigRegisterYes();
    });
}

void Register::showTip(QString str, bool b_ok)
{
    if(b_ok)
    {
        ui->err_tip->setProperty("state", "normal");
    }
    else
    {
        ui->err_tip->setProperty("state", "err");
    }
    ui->err_tip->setText(str);
    repolish(ui->err_tip);
}

void Register::addTipErr(TipErr err, QString tp)
{
    m_tip_errs[err] = tp;
    showTip(tp, false);
}

void Register::delTipErr(TipErr err, QString tp)
{
    m_tip_errs.remove(err);
    // 先移除，再判断是否为空
    if(m_tip_errs.empty())
    {
        ui->err_tip->clear();
        return;
    }

    showTip(m_tip_errs.first(), false);
}

bool Register::checkUser()
{
    if(ui->reg_username->text() == "")
    {
        addTipErr(TipErr::TIP_USER_ERR, "用户名不能为空");
        return false;
    }
    delTipErr(TipErr::TIP_USER_ERR);
    return true;
}

bool Register::checkPasswd()
{
    if(ui->reg_password->text() == "")
    {
        addTipErr(TipErr::TIP_PWD_ERR, "密码不能为空");
        return false;
    }

    if(ui->reg_password->text().length() < 6 || ui->reg_password->text().length() > 15)
    {
        addTipErr(TipErr::TIP_PWD_ERR, "密码长度应为6~15位");
        return false;
    }

    // 创建一个正则表达式对象，按照上述密码要求
    // 这个正则表达式解释：
    // ^[a-zA-Z0-9!@#$%^&*]{6,15}$ 密码长度至少6，可以是字母、数字和特定的特殊字符
    QRegularExpression regExp("^[a-zA-Z0-9!@#$%^&*]{6,15}$");
    bool match = regExp.match(ui->reg_password->text()).hasMatch();
    if(!match){
        //提示字符非法
        addTipErr(TipErr::TIP_PWD_ERR, tr("不能包含非法字符"));
        return false;;
    }

    delTipErr(TipErr::TIP_PWD_ERR);
    return true;
}

bool Register::checkEmail()
{
    //验证邮箱的地址正则表达式
    auto email = ui->reg_emial->text();
    // 邮箱地址的正则表达式
    QRegularExpression regex(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
    bool match = regex.match(email).hasMatch(); // 执行正则表达式匹配
    if(!match){
        //提示邮箱不正确
        addTipErr(TipErr::TIP_EMAIL_ERR, tr("邮箱地址不正确"));
        return false;
    }

    delTipErr(TipErr::TIP_EMAIL_ERR);
    return true;
}

bool Register::checkConfirm()
{
    if(ui->reg_password->text() != ui->reg_passwd_again->text())
    {
        addTipErr(TipErr::TIP_PWD_CONFIRM, "密码不一致");
        return false;
    }

    if(ui->reg_passwd_again->text() == "")
    {
        addTipErr(TipErr::TIP_PWD_CONFIRM, tr("确认密码不能为空"));
        return false;
    }
    delTipErr(TipErr::TIP_PWD_CONFIRM);
    return true;
}

bool Register::checkVarifyCode()
{
    auto pass = ui->reg_verify->text();
    if(pass.isEmpty()){
        addTipErr(TipErr::TIP_VARIFY_ERR, tr("验证码不能为空"));
        return false;
    }

    delTipErr(TipErr::TIP_VARIFY_ERR);
    return true;
}


void Register::on_yes_btn_clicked()
{
    bool flag1 = checkUser();
    bool flag2 = checkEmail();
    bool flag3 = checkPasswd();
    bool flag4 = checkConfirm();
    bool flag5 = checkVarifyCode();
    if(flag1 && flag2 && flag3 && flag4 && flag5)
    {
        QJsonObject json_obj;
        json_obj["user"] = ui->reg_username->text();
        json_obj["email"] = ui->reg_emial->text();
        json_obj["passwd"] = xorString(ui->reg_password->text());
        json_obj["confirm"] = xorString(ui->reg_passwd_again->text());
        json_obj["varifycode"] = ui->reg_verify->text();
        auto httpMgr = HttpMgr::getInstance();
        if(httpMgr && httpMgr.get()) {
            httpMgr->PostHttpReq(QUrl(gate_url_prefix+"/user_register"),
                                json_obj, ReqId::ID_REG_USER, Modules::REGISTERMOD);
        } else {
            qDebug() << "HttpMgr 单例对象未正确初始化";
        }
    }
    else
    {
        return;
    }
}


void Register::on_no_btn_clicked()
{
    // 发送信号通知主界面，取消注册
    emit sigSwitchLogin();
}
