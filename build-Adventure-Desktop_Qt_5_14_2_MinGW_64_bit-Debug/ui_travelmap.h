/********************************************************************************
** Form generated from reading UI file 'travelmap.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAVELMAP_H
#define UI_TRAVELMAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "travelmap.h"

QT_BEGIN_NAMESPACE

class Ui_TravelMap
{
public:
    QListView *stateList;
    QPushButton *backBtn;
    MyLabel *map;
    QLCDNumber *nowTime;
    QLabel *nowLabel;
    QLCDNumber *startTime;
    QLCDNumber *arrTime;
    QLabel *startLabel;
    QLabel *arrLabel;
    QLabel *stateLabel;
    QLabel *Haerbin;
    QLabel *Shenyang;
    QLabel *Changsha;
    QLabel *Shenzhen;
    QLabel *Guangzhou;
    QLabel *Chongqing;
    QLabel *Chengdu;
    QLabel *Shanghai;
    QLabel *Nanjing;
    QLabel *Wuhan;
    QLabel *Xian;
    QLabel *Jinan;
    QLabel *Shijiazhuang;
    QLabel *Tianjin;
    QLabel *Beijing;

    void setupUi(QWidget *TravelMap)
    {
        if (TravelMap->objectName().isEmpty())
            TravelMap->setObjectName(QString::fromUtf8("TravelMap"));
        TravelMap->resize(761, 481);
        stateList = new QListView(TravelMap);
        stateList->setObjectName(QString::fromUtf8("stateList"));
        stateList->setGeometry(QRect(630, 300, 121, 131));
        backBtn = new QPushButton(TravelMap);
        backBtn->setObjectName(QString::fromUtf8("backBtn"));
        backBtn->setGeometry(QRect(640, 440, 111, 31));
        map = new MyLabel(TravelMap);
        map->setObjectName(QString::fromUtf8("map"));
        map->setGeometry(QRect(0, 0, 611, 481));
        map->setStyleSheet(QString::fromUtf8("border-image: url(:/map.png);"));
        nowTime = new QLCDNumber(TravelMap);
        nowTime->setObjectName(QString::fromUtf8("nowTime"));
        nowTime->setGeometry(QRect(630, 40, 121, 61));
        nowLabel = new QLabel(TravelMap);
        nowLabel->setObjectName(QString::fromUtf8("nowLabel"));
        nowLabel->setGeometry(QRect(670, 20, 71, 20));
        startTime = new QLCDNumber(TravelMap);
        startTime->setObjectName(QString::fromUtf8("startTime"));
        startTime->setGeometry(QRect(630, 120, 121, 61));
        arrTime = new QLCDNumber(TravelMap);
        arrTime->setObjectName(QString::fromUtf8("arrTime"));
        arrTime->setGeometry(QRect(630, 200, 121, 61));
        startLabel = new QLabel(TravelMap);
        startLabel->setObjectName(QString::fromUtf8("startLabel"));
        startLabel->setGeometry(QRect(670, 100, 51, 21));
        arrLabel = new QLabel(TravelMap);
        arrLabel->setObjectName(QString::fromUtf8("arrLabel"));
        arrLabel->setGeometry(QRect(670, 180, 71, 21));
        stateLabel = new QLabel(TravelMap);
        stateLabel->setObjectName(QString::fromUtf8("stateLabel"));
        stateLabel->setGeometry(QRect(670, 270, 61, 21));
        Haerbin = new QLabel(TravelMap);
        Haerbin->setObjectName(QString::fromUtf8("Haerbin"));
        Haerbin->setGeometry(QRect(510, 100, 20, 20));
        Haerbin->setStyleSheet(QString::fromUtf8("border-image: url(:/city.jpg);"));
        Shenyang = new QLabel(TravelMap);
        Shenyang->setObjectName(QString::fromUtf8("Shenyang"));
        Shenyang->setGeometry(QRect(500, 150, 20, 20));
        Shenyang->setStyleSheet(QString::fromUtf8("border-image: url(:/city.jpg);"));
        Changsha = new QLabel(TravelMap);
        Changsha->setObjectName(QString::fromUtf8("Changsha"));
        Changsha->setGeometry(QRect(400, 340, 20, 20));
        Changsha->setStyleSheet(QString::fromUtf8("border-image: url(:/city.jpg);"));
        Shenzhen = new QLabel(TravelMap);
        Shenzhen->setObjectName(QString::fromUtf8("Shenzhen"));
        Shenzhen->setGeometry(QRect(420, 410, 20, 20));
        Shenzhen->setStyleSheet(QString::fromUtf8("border-image: url(:/city.jpg);"));
        Guangzhou = new QLabel(TravelMap);
        Guangzhou->setObjectName(QString::fromUtf8("Guangzhou"));
        Guangzhou->setGeometry(QRect(400, 400, 20, 20));
        Guangzhou->setStyleSheet(QString::fromUtf8("border-image: url(:/city.jpg);"));
        Chongqing = new QLabel(TravelMap);
        Chongqing->setObjectName(QString::fromUtf8("Chongqing"));
        Chongqing->setGeometry(QRect(330, 320, 20, 20));
        Chongqing->setStyleSheet(QString::fromUtf8("border-image: url(:/city.jpg);"));
        Chengdu = new QLabel(TravelMap);
        Chengdu->setObjectName(QString::fromUtf8("Chengdu"));
        Chengdu->setGeometry(QRect(290, 320, 20, 20));
        Chengdu->setStyleSheet(QString::fromUtf8("border-image: url(:/city.jpg);"));
        Shanghai = new QLabel(TravelMap);
        Shanghai->setObjectName(QString::fromUtf8("Shanghai"));
        Shanghai->setGeometry(QRect(490, 290, 20, 20));
        Shanghai->setStyleSheet(QString::fromUtf8("border-image: url(:/city.jpg);"));
        Nanjing = new QLabel(TravelMap);
        Nanjing->setObjectName(QString::fromUtf8("Nanjing"));
        Nanjing->setGeometry(QRect(460, 280, 20, 20));
        Nanjing->setStyleSheet(QString::fromUtf8("border-image: url(:/city.jpg);"));
        Wuhan = new QLabel(TravelMap);
        Wuhan->setObjectName(QString::fromUtf8("Wuhan"));
        Wuhan->setGeometry(QRect(410, 300, 20, 20));
        Wuhan->setStyleSheet(QString::fromUtf8("border-image: url(:/city.jpg);"));
        Xian = new QLabel(TravelMap);
        Xian->setObjectName(QString::fromUtf8("Xian"));
        Xian->setGeometry(QRect(360, 250, 20, 20));
        Xian->setStyleSheet(QString::fromUtf8("border-image: url(:/city.jpg);"));
        Jinan = new QLabel(TravelMap);
        Jinan->setObjectName(QString::fromUtf8("Jinan"));
        Jinan->setGeometry(QRect(430, 230, 20, 20));
        Jinan->setStyleSheet(QString::fromUtf8("border-image: url(:/city.jpg);"));
        Shijiazhuang = new QLabel(TravelMap);
        Shijiazhuang->setObjectName(QString::fromUtf8("Shijiazhuang"));
        Shijiazhuang->setGeometry(QRect(410, 210, 20, 20));
        Shijiazhuang->setStyleSheet(QString::fromUtf8("border-image: url(:/city.jpg);"));
        Tianjin = new QLabel(TravelMap);
        Tianjin->setObjectName(QString::fromUtf8("Tianjin"));
        Tianjin->setGeometry(QRect(440, 200, 20, 20));
        Tianjin->setStyleSheet(QString::fromUtf8("border-image: url(:/city.jpg);"));
        Beijing = new QLabel(TravelMap);
        Beijing->setObjectName(QString::fromUtf8("Beijing"));
        Beijing->setGeometry(QRect(430, 180, 20, 20));
        Beijing->setStyleSheet(QString::fromUtf8("border-image: url(:/city.jpg);"));

        retranslateUi(TravelMap);

        QMetaObject::connectSlotsByName(TravelMap);
    } // setupUi

    void retranslateUi(QWidget *TravelMap)
    {
        TravelMap->setWindowTitle(QCoreApplication::translate("TravelMap", "Form", nullptr));
        backBtn->setText(QCoreApplication::translate("TravelMap", "\350\277\224\345\233\236", nullptr));
        map->setText(QString());
        nowLabel->setText(QCoreApplication::translate("TravelMap", "\345\275\223\345\211\215\346\227\266\351\227\264", nullptr));
        startLabel->setText(QCoreApplication::translate("TravelMap", "\345\207\272\345\217\221\346\227\266\351\227\264", nullptr));
        arrLabel->setText(QCoreApplication::translate("TravelMap", "\345\210\260\350\276\276\346\227\266\351\227\264", nullptr));
        stateLabel->setText(QCoreApplication::translate("TravelMap", "\345\275\223\345\211\215\347\212\266\346\200\201", nullptr));
        Haerbin->setText(QString());
        Shenyang->setText(QString());
        Changsha->setText(QString());
        Shenzhen->setText(QString());
        Guangzhou->setText(QString());
        Chongqing->setText(QString());
        Chengdu->setText(QString());
        Shanghai->setText(QString());
        Nanjing->setText(QString());
        Wuhan->setText(QString());
        Xian->setText(QString());
        Jinan->setText(QString());
        Shijiazhuang->setText(QString());
        Tianjin->setText(QString());
        Beijing->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TravelMap: public Ui_TravelMap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAVELMAP_H
