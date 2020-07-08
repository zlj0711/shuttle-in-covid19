#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "routequery.h"
#include "travelmap.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void fromRouteQuery();
    void fromTravelMap();

private slots:
    void on_routeQuery_clicked();

    void on_stateQuery_clicked();

    void on_routeChange_clicked();

private:
    Ui::MainWindow *ui;
    RouteQuery queryWindow;
    TravelMap mapWindow;
};
#endif // MAINWINDOW_H
