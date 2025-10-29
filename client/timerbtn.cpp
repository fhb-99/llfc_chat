#include "timerbtn.h"

#include <QMouseEvent>
#include <QDebug>

TimerBtn::TimerBtn(QWidget * parent) : QPushButton(parent), m_count(10)
{
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, [&](){
        m_count--;
        if(m_count <= 0)
        {
            m_timer->stop();
            this->setEnabled(true);
            this->setText("获取");
            m_count = 10;
            return;
        }
        this->setText(QString::number(m_count));
    });
}

TimerBtn::~TimerBtn()
{
    m_timer->stop();
}

void TimerBtn::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        qDebug() << "MyButton is released";
        // 设置为不可点击状态
        this->setEnabled(false);
        // 显示倒计时
        this->setText(QString::number(m_count));
        m_timer->start(1000);
        emit clicked();
    }
    QPushButton::mouseMoveEvent(event);
}
