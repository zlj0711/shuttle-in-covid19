#include "mainwindow.h"
#include "ui_mainwindow.h"

extern QStringList logList;
extern QString FILE_PATH;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&queryWindow,&RouteQuery::back,this,&MainWindow::fromRouteQuery);
    connect(&mapWindow,&TravelMap::back,this,&MainWindow::fromTravelMap);
}
void writeLog(){
    QFile csvFile(FILE_PATH);
    if (csvFile.open(QIODevice::ReadWrite)){
        for(int i = 0;i < logList.size();i++){
            csvFile.write(logList.at(i).toLocal8Bit());
        }
        csvFile.close();
    }
}
MainWindow::~MainWindow()
{
    delete ui;
    writeLog();
}


void MainWindow::on_routeQuery_clicked()
{
    this->hide();
    queryWindow.setWindowTitle("查询窗口");
    queryWindow.show();
}

void MainWindow::on_stateQuery_clicked()
{
    this->hide();
    mapWindow.setWindowTitle("状态窗口");
    mapWindow.show();
}

void MainWindow::on_routeChange_clicked()
{

}
void MainWindow::fromRouteQuery(){
    this->show();
    queryWindow.close();
}

void MainWindow::fromTravelMap(){
    this->show();
    mapWindow.close();
}
