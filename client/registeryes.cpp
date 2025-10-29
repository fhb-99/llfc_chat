#include "registeryes.h"
#include "ui_registeryes.h"

registerYes::registerYes(QWidget *parent)
    : QDialog(parent)
    , m_count(5), ui(new Ui::registerYes)
{
    ui->setupUi(this);

    m_timer = new QTimer(this);
    m_timer->start(1000);
    connect(m_timer, &QTimer::timeout, [this](){
        if(m_count == 0)
        {
            m_timer->stop();
            emit sigSwitchLogin();
            return;
        }
        m_count--;
        auto str = QString("注册成功，%1 s后返回登录").arg(m_count);
        ui->count_label->setText(str);
    });
}

registerYes::~registerYes()
{
    // m_timer->stop();
    delete ui;
}

void registerYes::on_getLogin_btn_clicked()
{
    m_timer->stop();
    emit sigSwitchLogin();
}


