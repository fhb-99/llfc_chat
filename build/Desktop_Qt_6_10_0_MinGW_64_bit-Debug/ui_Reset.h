/********************************************************************************
** Form generated from reading UI file 'Reset.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESET_H
#define UI_RESET_H

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

class Ui_Reset
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *reg_user;
    QLabel *label_3;
    QLineEdit *reg_email;
    QLabel *label_4;
    QLineEdit *reg_passwd;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLineEdit *varifyCode;
    QPushButton *getVarifyCode;
    QSpacerItem *verticalSpacer;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *yes_btn;
    QPushButton *no_btn;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *Reset)
    {
        if (Reset->objectName().isEmpty())
            Reset->setObjectName("Reset");
        Reset->resize(300, 500);
        Reset->setMinimumSize(QSize(300, 500));
        Reset->setMaximumSize(QSize(300, 500));
        verticalLayout_2 = new QVBoxLayout(Reset);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        widget = new QWidget(Reset);
        widget->setObjectName("widget");
        widget->setLayoutDirection(Qt::LeftToRight);
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        verticalLayout_2->addWidget(widget);

        widget_2 = new QWidget(Reset);
        widget_2->setObjectName("widget_2");
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(widget_2);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        reg_user = new QLineEdit(widget_2);
        reg_user->setObjectName("reg_user");

        gridLayout->addWidget(reg_user, 0, 1, 1, 1);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        reg_email = new QLineEdit(widget_2);
        reg_email->setObjectName("reg_email");

        gridLayout->addWidget(reg_email, 1, 1, 1, 1);

        label_4 = new QLabel(widget_2);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        reg_passwd = new QLineEdit(widget_2);
        reg_passwd->setObjectName("reg_passwd");

        gridLayout->addWidget(reg_passwd, 2, 1, 1, 1);


        verticalLayout_2->addWidget(widget_2);

        widget_3 = new QWidget(Reset);
        widget_3->setObjectName("widget_3");
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName("horizontalLayout");
        label_5 = new QLabel(widget_3);
        label_5->setObjectName("label_5");

        horizontalLayout->addWidget(label_5);

        varifyCode = new QLineEdit(widget_3);
        varifyCode->setObjectName("varifyCode");

        horizontalLayout->addWidget(varifyCode);

        getVarifyCode = new QPushButton(widget_3);
        getVarifyCode->setObjectName("getVarifyCode");

        horizontalLayout->addWidget(getVarifyCode);


        verticalLayout_2->addWidget(widget_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        widget_4 = new QWidget(Reset);
        widget_4->setObjectName("widget_4");
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        yes_btn = new QPushButton(widget_4);
        yes_btn->setObjectName("yes_btn");

        horizontalLayout_2->addWidget(yes_btn);

        no_btn = new QPushButton(widget_4);
        no_btn->setObjectName("no_btn");

        horizontalLayout_2->addWidget(no_btn);


        verticalLayout_2->addWidget(widget_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        retranslateUi(Reset);

        QMetaObject::connectSlotsByName(Reset);
    } // setupUi

    void retranslateUi(QDialog *Reset)
    {
        Reset->setWindowTitle(QCoreApplication::translate("Reset", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Reset", "\351\224\231\350\257\257\346\217\220\347\244\272", nullptr));
        label_2->setText(QCoreApplication::translate("Reset", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Reset", "\351\202\256\347\256\261\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("Reset", "\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("Reset", "\351\252\214\350\257\201\347\240\201", nullptr));
        getVarifyCode->setText(QCoreApplication::translate("Reset", "\350\216\267\345\217\226", nullptr));
        yes_btn->setText(QCoreApplication::translate("Reset", "\347\241\256\345\256\232", nullptr));
        no_btn->setText(QCoreApplication::translate("Reset", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Reset: public Ui_Reset {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESET_H
