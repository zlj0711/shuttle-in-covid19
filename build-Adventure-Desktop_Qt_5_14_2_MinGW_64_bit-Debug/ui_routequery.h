/********************************************************************************
** Form generated from reading UI file 'routequery.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROUTEQUERY_H
#define UI_ROUTEQUERY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RouteQuery
{
public:
    QLabel *label;
    QPushButton *startBtn;
    QListView *planList;
    QPushButton *backButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *fromLabel;
    QComboBox *fromChoice;
    QHBoxLayout *horizontalLayout_2;
    QLabel *toLabel;
    QComboBox *toChoice;
    QHBoxLayout *horizontalLayout_3;
    QLabel *strategyLabel;
    QComboBox *strategyChoice;
    QHBoxLayout *horizontalLayout_5;
    QLabel *timeLabel;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *backBtn;
    QPushButton *queryBtn;

    void setupUi(QWidget *RouteQuery)
    {
        if (RouteQuery->objectName().isEmpty())
            RouteQuery->setObjectName(QString::fromUtf8("RouteQuery"));
        RouteQuery->resize(290, 270);
        label = new QLabel(RouteQuery);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 10, 151, 31));
        startBtn = new QPushButton(RouteQuery);
        startBtn->setObjectName(QString::fromUtf8("startBtn"));
        startBtn->setGeometry(QRect(150, 223, 131, 31));
        planList = new QListView(RouteQuery);
        planList->setObjectName(QString::fromUtf8("planList"));
        planList->setGeometry(QRect(11, 41, 271, 171));
        backButton = new QPushButton(RouteQuery);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(12, 223, 131, 31));
        widget = new QWidget(RouteQuery);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(9, 50, 271, 211));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        fromLabel = new QLabel(widget);
        fromLabel->setObjectName(QString::fromUtf8("fromLabel"));

        horizontalLayout->addWidget(fromLabel);

        fromChoice = new QComboBox(widget);
        fromChoice->addItem(QString());
        fromChoice->addItem(QString());
        fromChoice->addItem(QString());
        fromChoice->addItem(QString());
        fromChoice->addItem(QString());
        fromChoice->addItem(QString());
        fromChoice->addItem(QString());
        fromChoice->addItem(QString());
        fromChoice->addItem(QString());
        fromChoice->addItem(QString());
        fromChoice->addItem(QString());
        fromChoice->addItem(QString());
        fromChoice->addItem(QString());
        fromChoice->addItem(QString());
        fromChoice->addItem(QString());
        fromChoice->setObjectName(QString::fromUtf8("fromChoice"));

        horizontalLayout->addWidget(fromChoice);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        toLabel = new QLabel(widget);
        toLabel->setObjectName(QString::fromUtf8("toLabel"));

        horizontalLayout_2->addWidget(toLabel);

        toChoice = new QComboBox(widget);
        toChoice->addItem(QString());
        toChoice->addItem(QString());
        toChoice->addItem(QString());
        toChoice->addItem(QString());
        toChoice->addItem(QString());
        toChoice->addItem(QString());
        toChoice->addItem(QString());
        toChoice->addItem(QString());
        toChoice->addItem(QString());
        toChoice->addItem(QString());
        toChoice->addItem(QString());
        toChoice->addItem(QString());
        toChoice->addItem(QString());
        toChoice->addItem(QString());
        toChoice->addItem(QString());
        toChoice->setObjectName(QString::fromUtf8("toChoice"));

        horizontalLayout_2->addWidget(toChoice);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        strategyLabel = new QLabel(widget);
        strategyLabel->setObjectName(QString::fromUtf8("strategyLabel"));

        horizontalLayout_3->addWidget(strategyLabel);

        strategyChoice = new QComboBox(widget);
        strategyChoice->addItem(QString());
        strategyChoice->addItem(QString());
        strategyChoice->setObjectName(QString::fromUtf8("strategyChoice"));

        horizontalLayout_3->addWidget(strategyChoice);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        timeLabel = new QLabel(widget);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));

        horizontalLayout_5->addWidget(timeLabel);

        spinBox = new QSpinBox(widget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout_5->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        backBtn = new QPushButton(widget);
        backBtn->setObjectName(QString::fromUtf8("backBtn"));

        horizontalLayout_4->addWidget(backBtn);

        queryBtn = new QPushButton(widget);
        queryBtn->setObjectName(QString::fromUtf8("queryBtn"));

        horizontalLayout_4->addWidget(queryBtn);


        verticalLayout->addLayout(horizontalLayout_4);

        backButton->raise();
        startBtn->raise();
        planList->raise();
        label->raise();

        retranslateUi(RouteQuery);

        QMetaObject::connectSlotsByName(RouteQuery);
    } // setupUi

    void retranslateUi(QWidget *RouteQuery)
    {
        RouteQuery->setWindowTitle(QCoreApplication::translate("RouteQuery", "Form", nullptr));
        label->setText(QCoreApplication::translate("RouteQuery", "\350\257\267\350\276\223\345\205\245\346\202\250\347\232\204\350\256\241\345\210\222\346\227\205\350\241\214\344\277\241\346\201\257", nullptr));
        startBtn->setText(QCoreApplication::translate("RouteQuery", "\345\274\200\345\247\213\346\227\205\350\241\214", nullptr));
        backButton->setText(QCoreApplication::translate("RouteQuery", "\350\277\224\345\233\236", nullptr));
        fromLabel->setText(QCoreApplication::translate("RouteQuery", "\345\207\272\345\217\221\345\234\260", nullptr));
        fromChoice->setItemText(0, QCoreApplication::translate("RouteQuery", "\345\214\227\344\272\254", nullptr));
        fromChoice->setItemText(1, QCoreApplication::translate("RouteQuery", "\345\244\251\346\264\245", nullptr));
        fromChoice->setItemText(2, QCoreApplication::translate("RouteQuery", "\344\270\212\346\265\267", nullptr));
        fromChoice->setItemText(3, QCoreApplication::translate("RouteQuery", "\351\207\215\345\272\206", nullptr));
        fromChoice->setItemText(4, QCoreApplication::translate("RouteQuery", "\345\223\210\345\260\224\346\273\250", nullptr));
        fromChoice->setItemText(5, QCoreApplication::translate("RouteQuery", "\346\262\210\351\230\263", nullptr));
        fromChoice->setItemText(6, QCoreApplication::translate("RouteQuery", "\347\237\263\345\256\266\345\272\204", nullptr));
        fromChoice->setItemText(7, QCoreApplication::translate("RouteQuery", "\350\245\277\345\256\211", nullptr));
        fromChoice->setItemText(8, QCoreApplication::translate("RouteQuery", "\346\265\216\345\215\227", nullptr));
        fromChoice->setItemText(9, QCoreApplication::translate("RouteQuery", "\345\271\277\345\267\236", nullptr));
        fromChoice->setItemText(10, QCoreApplication::translate("RouteQuery", "\351\225\277\346\262\231", nullptr));
        fromChoice->setItemText(11, QCoreApplication::translate("RouteQuery", "\345\215\227\344\272\254", nullptr));
        fromChoice->setItemText(12, QCoreApplication::translate("RouteQuery", "\346\255\246\346\261\211", nullptr));
        fromChoice->setItemText(13, QCoreApplication::translate("RouteQuery", "\346\210\220\351\203\275", nullptr));
        fromChoice->setItemText(14, QCoreApplication::translate("RouteQuery", "\346\267\261\345\234\263", nullptr));

        toLabel->setText(QCoreApplication::translate("RouteQuery", "\347\233\256\347\232\204\345\234\260", nullptr));
        toChoice->setItemText(0, QCoreApplication::translate("RouteQuery", "\345\214\227\344\272\254", nullptr));
        toChoice->setItemText(1, QCoreApplication::translate("RouteQuery", "\345\244\251\346\264\245", nullptr));
        toChoice->setItemText(2, QCoreApplication::translate("RouteQuery", "\344\270\212\346\265\267", nullptr));
        toChoice->setItemText(3, QCoreApplication::translate("RouteQuery", "\351\207\215\345\272\206", nullptr));
        toChoice->setItemText(4, QCoreApplication::translate("RouteQuery", "\345\223\210\345\260\224\346\273\250", nullptr));
        toChoice->setItemText(5, QCoreApplication::translate("RouteQuery", "\346\262\210\351\230\263", nullptr));
        toChoice->setItemText(6, QCoreApplication::translate("RouteQuery", "\347\237\263\345\256\266\345\272\204", nullptr));
        toChoice->setItemText(7, QCoreApplication::translate("RouteQuery", "\350\245\277\345\256\211", nullptr));
        toChoice->setItemText(8, QCoreApplication::translate("RouteQuery", "\346\265\216\345\215\227", nullptr));
        toChoice->setItemText(9, QCoreApplication::translate("RouteQuery", "\345\271\277\345\267\236", nullptr));
        toChoice->setItemText(10, QCoreApplication::translate("RouteQuery", "\351\225\277\346\262\231", nullptr));
        toChoice->setItemText(11, QCoreApplication::translate("RouteQuery", "\345\215\227\344\272\254", nullptr));
        toChoice->setItemText(12, QCoreApplication::translate("RouteQuery", "\346\255\246\346\261\211", nullptr));
        toChoice->setItemText(13, QCoreApplication::translate("RouteQuery", "\346\210\220\351\203\275", nullptr));
        toChoice->setItemText(14, QCoreApplication::translate("RouteQuery", "\346\267\261\345\234\263", nullptr));

        strategyLabel->setText(QCoreApplication::translate("RouteQuery", "\346\227\205\350\241\214\347\255\226\347\225\245", nullptr));
        strategyChoice->setItemText(0, QCoreApplication::translate("RouteQuery", "\346\234\200\344\275\216\351\243\216\351\231\251", nullptr));
        strategyChoice->setItemText(1, QCoreApplication::translate("RouteQuery", "\351\231\220\346\227\266\346\234\200\344\275\216\351\243\216\351\231\251", nullptr));

        timeLabel->setText(QCoreApplication::translate("RouteQuery", "\351\231\220\345\210\266\346\227\266\351\227\264(h)", nullptr));
        backBtn->setText(QCoreApplication::translate("RouteQuery", "\350\277\224\345\233\236", nullptr));
        queryBtn->setText(QCoreApplication::translate("RouteQuery", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RouteQuery: public Ui_RouteQuery {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROUTEQUERY_H
