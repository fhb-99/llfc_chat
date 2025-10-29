#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
#include "register.h"
#include "registeryes.h"
#include "reset.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Login * m_login;
    Register * m_register;
    registerYes * m_register_yes;
    Reset * m_reset;
    Ui::MainWindow *ui;

private slots:
    void slot_get_Login();
    void slot_get_Register();
    void slot_get_Reset();
    void slot_get_RegisterYes();
};
#endif // MAINWINDOW_H
