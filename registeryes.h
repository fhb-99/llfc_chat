#ifndef REGISTERYES_H
#define REGISTERYES_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class registerYes;
}

class registerYes : public QDialog
{
    Q_OBJECT

public:
    explicit registerYes(QWidget *parent = nullptr);
    ~registerYes();

private slots:
    void on_getLogin_btn_clicked();

private:
    QTimer * m_timer;
    int m_count;

    Ui::registerYes *ui;

signals:
    void sigSwitchLogin();
};

#endif // REGISTERYES_H
