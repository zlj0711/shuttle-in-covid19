#ifndef TRAVELMAP_H
#define TRAVELMAP_H

#include <QWidget>
#include"common.h"
namespace Ui {
class TravelMap;
}

class TravelMap : public QWidget
{
    Q_OBJECT

public:
    explicit TravelMap(QWidget *parent = nullptr);
    ~TravelMap();
    void show();
    void showCity(int city);
    QPointF getCityLocation(int city);
    QPointF calLocation();
    void readRoute();

signals:
    void back();
private slots:
    void on_backBtn_clicked();
protected:
    void paintEvent(QPaintEvent*);
private:
    Ui::TravelMap *ui;
    QTimer *timer;
    QStandardItemModel *model = new QStandardItemModel(this);
};

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent*);
private:
    QTimer *timerLabel;
private slots:
    void TimeOut();


};

#endif // TRAVELMAP_H
