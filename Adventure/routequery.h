#ifndef ROUTEQUERY_H
#define ROUTEQUERY_H
#include"common.h"
#include "travelmap.h"
namespace Ui {
class RouteQuery;
}

class RouteQuery : public QWidget
{
    Q_OBJECT

public:
    explicit RouteQuery(QWidget *parent = nullptr);
    QStringList calStrategy(int fromCity, int toCity, int strategyChoice, int time);
    void show();
    void fromTravelMap();
    ~RouteQuery();
signals:
    void back();
private slots:
    void on_backBtn_clicked();
    void on_queryBtn_clicked();

    void on_backButton_clicked();

    void on_startBtn_clicked();

    void on_strategyChoice_currentIndexChanged(int index);

private:
    Ui::RouteQuery *ui;
    QStandardItemModel *model = new QStandardItemModel(this);
    TravelMap mapWindow;
};

#endif // ROUTEQUERY_H
