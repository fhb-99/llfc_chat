/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

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

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLabel *user_label;
    QLineEdit *user_name;
    QLabel *pass_label;
    QLineEdit *password;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *forget_pass;
    QWidget *widget_4;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *login;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *reg_user;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(300, 500);
        Dialog->setMinimumSize(QSize(300, 500));
        Dialog->setMaximumSize(QSize(300, 500));
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(Dialog);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(Dialog);
        widget_2->setObjectName("widget_2");
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName("gridLayout");
        user_label = new QLabel(widget_2);
        user_label->setObjectName("user_label");
        user_label->setMinimumSize(QSize(30, 30));

        gridLayout->addWidget(user_label, 0, 0, 1, 1);

        user_name = new QLineEdit(widget_2);
        user_name->setObjectName("user_name");
        user_name->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(user_name, 0, 1, 1, 1);

        pass_label = new QLabel(widget_2);
        pass_label->setObjectName("pass_label");
        pass_label->setMinimumSize(QSize(30, 30));

        gridLayout->addWidget(pass_label, 1, 0, 1, 1);

        password = new QLineEdit(widget_2);
        password->setObjectName("password");
        password->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(password, 1, 1, 1, 1);

        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName("widget_3");
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_3 = new QSpacerItem(202, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        forget_pass = new QPushButton(widget_3);
        forget_pass->setObjectName("forget_pass");
        forget_pass->setMinimumSize(QSize(55, 30));
        forget_pass->setMaximumSize(QSize(45, 30));

        horizontalLayout_2->addWidget(forget_pass);


        gridLayout->addWidget(widget_3, 2, 0, 1, 2);


        verticalLayout->addWidget(widget_2);

        widget_4 = new QWidget(Dialog);
        widget_4->setObjectName("widget_4");
        gridLayout_2 = new QGridLayout(widget_4);
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);

        login = new QPushButton(widget_4);
        login->setObjectName("login");
        login->setMinimumSize(QSize(65, 30));
        login->setMaximumSize(QSize(65, 30));

        gridLayout_2->addWidget(login, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(98, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(99, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        reg_user = new QPushButton(widget_4);
        reg_user->setObjectName("reg_user");
        reg_user->setMinimumSize(QSize(65, 30));
        reg_user->setMaximumSize(QSize(65, 30));

        gridLayout_2->addWidget(reg_user, 1, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(98, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 1, 2, 1, 1);


        verticalLayout->addWidget(widget_4);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "TextLabel", nullptr));
        user_label->setText(QCoreApplication::translate("Dialog", "\347\224\250\346\210\267\357\274\232", nullptr));
        pass_label->setText(QCoreApplication::translate("Dialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        forget_pass->setText(QCoreApplication::translate("Dialog", "\345\277\230\350\256\260\345\257\206\347\240\201", nullptr));
        login->setText(QCoreApplication::translate("Dialog", "\347\231\273\345\275\225", nullptr));
        reg_user->setText(QCoreApplication::translate("Dialog", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
