#ifndef TIMERBTN_H
#define TIMERBTN_H

#include <QPushButton>
#include <QTimer>

class TimerBtn : public QPushButton
{
public:
    TimerBtn(QWidget * parent = nullptr);
    ~TimerBtn();

    // 重写鼠标释放功能
    virtual void mouseReleaseEvent(QMouseEvent * event) override;

private:
    QTimer * m_timer;
    int m_count;
};

#endif // TIMERBTN_H
