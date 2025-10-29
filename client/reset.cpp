#include "reset.h"
#include "ui_Reset.h"
#include "global.h"
#include "httpmgr.h"

Reset::Reset(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reset)
{
    ui->setupUi(this);
    
    // 设置密码输入框为密码模式
    ui->reg_passwd->setEchoMode(QLineEdit::Password);
    
    // 手动连接信号和槽
    connect(ui->getVarifyCode, &QPushButton::clicked, this, &Reset::on_getVarifyC_clicked);
    connect(ui->yes_btn, &QPushButton::clicked, this, &Reset::on_yes_btn_clicked);
    connect(ui->no_btn, &QPushButton::clicked, this, &Reset::on_no_btn_clicked);
    
    // 连接HTTP响应信号
    auto httpMgr = HttpMgr::getInstance();
    if(httpMgr && httpMgr.get()) {
        connect(httpMgr.get(), &HttpMgr::sig_reset_mod_finish,
                this, &Reset::slot_req_mod_finish);
    } else {
        qDebug() << "HttpMgr 单例对象未正确初始化";
    }
    
    initHttpHandlers();
}

Reset::~Reset()
{
    delete ui;
}

void Reset::on_getVarifyC_clicked()
{
    auto email = ui->reg_email->text();
    QRegularExpression regex(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
    bool match = regex.match(email).hasMatch();
    if(match)
    {
        // 发送http验证码请求
        QJsonObject json_obj;
        json_obj["email"] = email;
        auto httpMgr = HttpMgr::getInstance();
        if(httpMgr && httpMgr.get()) {
            httpMgr->PostHttpReq(QUrl(gate_url_prefix+"/get_varifycode"),
                                json_obj, ReqId::ID_DET_VERIFY_CODE, Modules::RESETMOD);
        } else {
            qDebug() << "HttpMgr 单例对象未正确初始化";
        }
    }
    else
    {
        showTip(tr("邮箱地址不正确"), false);
    }
}

void Reset::on_yes_btn_clicked()
{
    if(ui->reg_user->text() == "")
    {
        showTip(tr("用户名不能为空"), false);
        return;
    }
    
    if(ui->reg_email->text() == "")
    {
        showTip(tr("邮箱不能为空"), false);
        return;
    }
    
    if(ui->reg_passwd->text() == "")
    {
        showTip(tr("新密码不能为空"), false);
        return;
    }
    
    if(ui->varifyCode->text() == "")
    {
        showTip(tr("验证码不能为空"), false);
        return;
    }
    
    // 发送重置密码请求
    QJsonObject json_obj;
    json_obj["user"] = ui->reg_user->text();
    json_obj["email"] = ui->reg_email->text();
    json_obj["passwd"] = ui->reg_passwd->text();
    json_obj["varifycode"] = ui->varifyCode->text();
    auto httpMgr = HttpMgr::getInstance();
    if(httpMgr && httpMgr.get()) {
        httpMgr->PostHttpReq(QUrl(gate_url_prefix+"/reset_password"),
                            json_obj, ReqId::ID_RESET_PASSWORD, Modules::RESETMOD);
    } else {
        qDebug() << "HttpMgr 单例对象未正确初始化";
    }
}

void Reset::on_no_btn_clicked()
{
    // 返回登录界面
    emit sigSwitchLogin();
}

void Reset::slot_req_mod_finish(ReqId id, QString res, ErrorCodes err)
{
    if(err != ErrorCodes::SUCCESS)
    {
        showTip(tr("网络请求错误"), false);
        return;
    }
    
    // 解析json响应
    QJsonDocument jsonDoc = QJsonDocument::fromJson(res.toUtf8());
    if(jsonDoc.isNull())
    {
        showTip(tr("json解析失败"), false);
        return;
    }
    
    if(!jsonDoc.isObject())
    {
        showTip(tr("json解析错误"), false);
        return;
    }
    
    m_handlers[id](jsonDoc.object());
}

void Reset::initHttpHandlers()
{
    // 获取验证码回包处理
    m_handlers.insert(ReqId::ID_DET_VERIFY_CODE, [this](const QJsonObject& jsonObj){
        int error = jsonObj["error"].toInt();
        if(error != ErrorCodes::SUCCESS)
        {
            showTip(tr("参数错误"), false);
            return;
        }
        
        auto email = jsonObj["email"].toString();
        showTip(tr("验证码已发送至邮箱，注意查收"), true);
        qDebug() << "Reset - email is : " << email;
    });
    
    // 重置密码回包处理
    m_handlers.insert(ReqId::ID_RESET_PASSWORD, [this](const QJsonObject& jsonObj){
        int error = jsonObj["error"].toInt();
        if(error != ErrorCodes::SUCCESS)
        {
            showTip(tr("重置密码失败"), false);
            return;
        }
        
        showTip(tr("密码重置成功"), true);
        qDebug() << "密码重置成功";
        
        // 延迟返回登录界面
        QTimer::singleShot(2000, this, [this](){
            emit sigSwitchLogin();
        });
    });
}

void Reset::showTip(QString str, bool b_ok)
{
    if(b_ok)
    {
        ui->label->setProperty("state", "normal");
    }
    else
    {
        ui->label->setProperty("state", "err");
    }
    ui->label->setText(str);
    // 这里可以添加样式刷新
    repolish(ui->label);
}
