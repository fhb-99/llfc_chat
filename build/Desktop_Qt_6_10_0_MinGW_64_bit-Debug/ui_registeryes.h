/********************************************************************************
** Form generated from reading UI file 'registeryes.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERYES_H
#define UI_REGISTERYES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registerYes
{
public:
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *count_label;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_3;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *getLogin_btn;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *registerYes)
    {
        if (registerYes->objectName().isEmpty())
            registerYes->setObjectName("registerYes");
        registerYes->resize(300, 500);
        registerYes->setMinimumSize(QSize(300, 500));
        registerYes->setMaximumSize(QSize(300, 500));
        registerYes->setSizeIncrement(QSize(0, 0));
        verticalLayout_3 = new QVBoxLayout(registerYes);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout_3->addItem(verticalSpacer);

        widget = new QWidget(registerYes);
        widget->setObjectName("widget");
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        count_label = new QLabel(widget);
        count_label->setObjectName("count_label");
        count_label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(count_label);


        verticalLayout_3->addWidget(widget);

        widget_2 = new QWidget(registerYes);
        widget_2->setObjectName("widget_2");
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(widget_2);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout_2->addItem(verticalSpacer_3);


        verticalLayout_3->addWidget(widget_2);

        widget_3 = new QWidget(registerYes);
        widget_3->setObjectName("widget_3");
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(94, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        getLogin_btn = new QPushButton(widget_3);
        getLogin_btn->setObjectName("getLogin_btn");
        getLogin_btn->setMinimumSize(QSize(75, 30));
        getLogin_btn->setMaximumSize(QSize(75, 30));

        horizontalLayout->addWidget(getLogin_btn);

        horizontalSpacer_2 = new QSpacerItem(93, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addWidget(widget_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout_3->addItem(verticalSpacer_2);


        retranslateUi(registerYes);

        QMetaObject::connectSlotsByName(registerYes);
    } // setupUi

    void retranslateUi(QDialog *registerYes)
    {
        registerYes->setWindowTitle(QCoreApplication::translate("registerYes", "Dialog", nullptr));
        count_label->setText(QCoreApplication::translate("registerYes", "\346\263\250\345\206\214\346\210\220\345\212\237\357\274\2145\347\247\222\345\220\216\350\277\224\345\233\236\347\231\273\345\275\225", nullptr));
        label_2->setText(QCoreApplication::translate("registerYes", "\345\217\257\347\202\271\345\207\273\346\214\211\351\222\256\347\233\264\346\216\245\350\277\224\345\233\236\347\231\273\345\275\225\347\225\214\351\235\242", nullptr));
        getLogin_btn->setText(QCoreApplication::translate("registerYes", "\350\277\224\345\233\236\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registerYes: public Ui_registerYes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERYES_H
