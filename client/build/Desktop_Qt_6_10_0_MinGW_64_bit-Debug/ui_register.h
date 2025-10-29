/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "clickedlabel.h"
#include "timerbtn.h"

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QWidget *widget_4;
    QGridLayout *gridLayout_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *RegVerify;
    QLineEdit *reg_verify;
    TimerBtn *get_verify;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *RegEmail;
    QLineEdit *reg_emial;
    QLabel *reg_pass;
    QLineEdit *reg_passwd_again;
    QLabel *RegUserName;
    QLineEdit *reg_password;
    QLineEdit *reg_username;
    QLabel *reg_again;
    ClickedLabel *pass_visible;
    ClickedLabel *confirm_visible;
    QWidget *widget_5;
    QGridLayout *gridLayout_3;
    QLabel *err_tip;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *yes_btn;
    QPushButton *no_btn;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName("Register");
        Register->resize(300, 500);
        Register->setMinimumSize(QSize(300, 500));
        Register->setMaximumSize(QSize(300, 500));
        verticalLayout = new QVBoxLayout(Register);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_3 = new QSpacerItem(20, 44, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout->addItem(verticalSpacer_3);

        widget_4 = new QWidget(Register);
        widget_4->setObjectName("widget_4");
        gridLayout_2 = new QGridLayout(widget_4);
        gridLayout_2->setObjectName("gridLayout_2");
        widget_2 = new QWidget(widget_4);
        widget_2->setObjectName("widget_2");
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        RegVerify = new QLabel(widget_2);
        RegVerify->setObjectName("RegVerify");
        RegVerify->setMinimumSize(QSize(0, 30));
        RegVerify->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(RegVerify);

        reg_verify = new QLineEdit(widget_2);
        reg_verify->setObjectName("reg_verify");
        reg_verify->setMinimumSize(QSize(75, 30));
        reg_verify->setMaximumSize(QSize(75, 30));

        horizontalLayout->addWidget(reg_verify);

        get_verify = new TimerBtn(widget_2);
        get_verify->setObjectName("get_verify");
        get_verify->setMinimumSize(QSize(0, 30));
        get_verify->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(get_verify);


        gridLayout_2->addWidget(widget_2, 2, 0, 1, 1);

        widget = new QWidget(widget_4);
        widget->setObjectName("widget");
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        RegEmail = new QLabel(widget);
        RegEmail->setObjectName("RegEmail");
        RegEmail->setMinimumSize(QSize(0, 30));
        RegEmail->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(RegEmail, 1, 0, 1, 1);

        reg_emial = new QLineEdit(widget);
        reg_emial->setObjectName("reg_emial");
        reg_emial->setMinimumSize(QSize(150, 30));
        reg_emial->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(reg_emial, 1, 2, 1, 2);

        reg_pass = new QLabel(widget);
        reg_pass->setObjectName("reg_pass");
        reg_pass->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(reg_pass, 2, 0, 1, 1);

        reg_passwd_again = new QLineEdit(widget);
        reg_passwd_again->setObjectName("reg_passwd_again");
        reg_passwd_again->setMinimumSize(QSize(150, 30));
        reg_passwd_again->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(reg_passwd_again, 3, 2, 1, 2);

        RegUserName = new QLabel(widget);
        RegUserName->setObjectName("RegUserName");
        RegUserName->setMinimumSize(QSize(0, 30));
        RegUserName->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(RegUserName, 0, 0, 1, 1);

        reg_password = new QLineEdit(widget);
        reg_password->setObjectName("reg_password");
        reg_password->setMinimumSize(QSize(150, 30));
        reg_password->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(reg_password, 2, 2, 1, 2);

        reg_username = new QLineEdit(widget);
        reg_username->setObjectName("reg_username");
        reg_username->setMinimumSize(QSize(150, 30));
        reg_username->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(reg_username, 0, 2, 1, 2);

        reg_again = new QLabel(widget);
        reg_again->setObjectName("reg_again");
        reg_again->setMinimumSize(QSize(0, 30));
        reg_again->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(reg_again, 3, 0, 1, 1);

        pass_visible = new ClickedLabel(widget);
        pass_visible->setObjectName("pass_visible");
        pass_visible->setMinimumSize(QSize(20, 0));
        pass_visible->setMaximumSize(QSize(20, 16777215));

        gridLayout->addWidget(pass_visible, 2, 4, 1, 1);

        confirm_visible = new ClickedLabel(widget);
        confirm_visible->setObjectName("confirm_visible");
        confirm_visible->setMinimumSize(QSize(20, 0));
        confirm_visible->setMaximumSize(QSize(20, 16777215));

        gridLayout->addWidget(confirm_visible, 3, 4, 1, 1);


        gridLayout_2->addWidget(widget, 1, 0, 1, 1);

        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName("widget_5");
        gridLayout_3 = new QGridLayout(widget_5);
        gridLayout_3->setObjectName("gridLayout_3");
        err_tip = new QLabel(widget_5);
        err_tip->setObjectName("err_tip");

        gridLayout_3->addWidget(err_tip, 0, 0, 1, 1);


        gridLayout_2->addWidget(widget_5, 0, 0, 1, 1);


        verticalLayout->addWidget(widget_4);

        verticalSpacer_2 = new QSpacerItem(20, 44, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout->addItem(verticalSpacer_2);

        widget_3 = new QWidget(Register);
        widget_3->setObjectName("widget_3");
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        yes_btn = new QPushButton(widget_3);
        yes_btn->setObjectName("yes_btn");
        yes_btn->setMinimumSize(QSize(90, 30));
        yes_btn->setMaximumSize(QSize(90, 30));

        horizontalLayout_2->addWidget(yes_btn);

        no_btn = new QPushButton(widget_3);
        no_btn->setObjectName("no_btn");
        no_btn->setMinimumSize(QSize(90, 30));
        no_btn->setMaximumSize(QSize(90, 30));

        horizontalLayout_2->addWidget(no_btn);


        verticalLayout->addWidget(widget_3);

        verticalSpacer = new QSpacerItem(20, 44, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QCoreApplication::translate("Register", "Dialog", nullptr));
        RegVerify->setText(QCoreApplication::translate("Register", "\351\252\214\350\257\201\347\240\201\357\274\232", nullptr));
        get_verify->setText(QCoreApplication::translate("Register", "\350\216\267\345\217\226\351\252\214\350\257\201\347\240\201", nullptr));
        RegEmail->setText(QCoreApplication::translate("Register", "\351\202\256\347\256\261\357\274\232", nullptr));
        reg_pass->setText(QCoreApplication::translate("Register", "\345\257\206\347\240\201\357\274\232", nullptr));
        RegUserName->setText(QCoreApplication::translate("Register", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        reg_again->setText(QCoreApplication::translate("Register", "\347\241\256\350\256\244\357\274\232", nullptr));
        pass_visible->setText(QString());
        confirm_visible->setText(QString());
        err_tip->setText(QCoreApplication::translate("Register", "\351\224\231\350\257\257\346\217\220\347\244\272", nullptr));
        yes_btn->setText(QCoreApplication::translate("Register", "\347\241\256\350\256\244", nullptr));
        no_btn->setText(QCoreApplication::translate("Register", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
