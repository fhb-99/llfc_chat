#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_login(nullptr)
    , m_register(nullptr)
    , m_register_yes(nullptr)
    , m_reset(nullptr)
{
    ui->setupUi(this);

    m_login = new Login(this);
    setCentralWidget(m_login);
    m_login->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    m_login->show();



    // 切换注册界面
    connect(m_login, &Login::switchRegistr, this, &MainWindow::slot_get_Register);

    // 忘记密码,切换界面
    connect(m_login, &Login::sigSwitchReset, this, &MainWindow::slot_get_Reset);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_get_Login()
{
    qDebug() << "slot_get_Login() 被调用";
//    if(m_login == nullptr)
//    {
//        m_login = new Login(this);
//    }
    m_login = new Login(this);
    // 直接显示已存在的登录界面，不创建新对象
    m_login->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    // 切换注册界面
    connect(m_login, &Login::switchRegistr, this, &MainWindow::slot_get_Register);

    // 忘记密码,切换界面
    connect(m_login, &Login::sigSwitchReset, this, &MainWindow::slot_get_Reset);

    setCentralWidget(m_login);
    m_login->show();
}

void MainWindow::slot_get_Register()
{
    // 如果m_register已经存在，直接显示，否则创建新的
//    if(m_register == nullptr)
//    {
//        m_register = new Register(this);
//    }
    m_register = new Register(this);
    m_register->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);

    // 只在创建时连接信号，避免重复连接
    connect(m_register, &Register::sigRegisterYes, this, &MainWindow::slot_get_RegisterYes);
    connect(m_register, &Register::sigSwitchLogin, this, &MainWindow::slot_get_Login);
    
    setCentralWidget(m_register);
    m_login->hide();
    m_register->show();
}

void MainWindow::slot_get_Reset()
{
    // 如果m_reset已经存在，直接显示，否则创建新的
//    if(m_reset == nullptr)
//    {
//        m_reset = new Reset(this);
//    }
    m_reset = new Reset(this);
    m_reset->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);

    // 只在创建时连接信号，避免重复连接
    connect(m_reset, &Reset::sigSwitchLogin, this, &MainWindow::slot_get_Login);
    
    setCentralWidget(m_reset);
    m_login->hide();
    m_reset->show();
    qDebug() << "Reset界面已显示";
}

void MainWindow::slot_get_RegisterYes()
{
    // 如果m_register_yes已经存在，直接显示，否则创建新的
//    if(m_register_yes == nullptr)
//    {
//        m_register_yes = new registerYes(this);
//    }
    m_register_yes = new registerYes(this);
    m_register_yes->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);

    // 连接返回登录界面的信号
    connect(m_register_yes, &registerYes::sigSwitchLogin, this, &MainWindow::slot_get_Login);
    
    setCentralWidget(m_register_yes);
    m_register->hide();
    m_register_yes->show();
}
