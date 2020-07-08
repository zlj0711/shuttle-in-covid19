#include "travelmap.h"
#include "ui_travelmap.h"
extern QJsonArray routeArr;
extern QTime timeTotal;
int state = 0;
int startTime;
int endTime;
QList <QPointF> startPointList;
QList <QPointF> endPointList;
extern QStringList cityName;
TravelMap::TravelMap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TravelMap)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
}

TravelMap::~TravelMap()
{
    delete ui;
}

void TravelMap::showCity(int city){
    switch(city){
    case 1:
        ui->Beijing->show();
        break;
    case 2:
        ui->Tianjin->show();
        break;
    case 3:
        ui->Shanghai->show();
        break;
    case 4:
        ui->Chongqing->show();
        break;
    case 5:
        ui->Haerbin->show();
        break;
    case 6:
        ui->Shenyang->show();
        break;
    case 7:
        ui->Shijiazhuang->show();
        break;
    case 8:
        ui->Xian->show();
        break;
    case 9:
        ui->Jinan->show();
        break;
    case 10:
        ui->Guangzhou->show();
        break;
    case 11:
        ui->Changsha->show();
        break;
    case 12:
        ui->Nanjing->show();
        break;
    case 13:
        ui->Wuhan->show();
        break;
    case 14:
        ui->Chengdu->show();
        break;
    case 15:
        ui->Shenzhen->show();
        break;
    default:
        break;
    }
}

QPointF TravelMap::getCityLocation(int city){
    QPointF a;
    switch(city){
    case 1:
        a = ui->Beijing->pos();
        break;
    case 2:
        a = ui->Tianjin->pos();
        break;
    case 3:
        a = ui->Shanghai->pos();
        break;
    case 4:
        a = ui->Chongqing->pos();
        break;
    case 5:
        a = ui->Haerbin->pos();
        break;
    case 6:
        a = ui->Shenyang->pos();
        break;
    case 7:
        a = ui->Shijiazhuang->pos();
        break;
    case 8:
        a = ui->Xian->pos();
        break;
    case 9:
        a = ui->Jinan->pos();
        break;
    case 10:
        a = ui->Guangzhou->pos();
        break;
    case 11:
        a = ui->Changsha->pos();
        break;
    case 12:
        a = ui->Nanjing->pos();
        break;
    case 13:
        a = ui->Wuhan->pos();
        break;
    case 14:
        a = ui->Chengdu->pos();
        break;
    case 15:
        a = ui->Shenzhen->pos();
        break;
    default:
        break;
    }
    return a;
}

void TravelMap::readRoute(){
    startPointList = {};
    endPointList = {};
    for(int i = 0;i < routeArr.size();i++){
        QJsonObject obj = routeArr.at(i).toObject();
        int fromCity = obj.value("fromCity").toInt();
        int toCity = obj.value("toCity").toInt();
        startPointList.append(getCityLocation(fromCity));
        endPointList.append(getCityLocation(toCity));
        this->showCity(fromCity);
        this->showCity(toCity);
    }
    startTime = routeArr.at(0).toObject().value("startTime").toInt();
    endTime = routeArr.at(routeArr.size() - 1).toObject().value("endTime").toInt();
}

QPointF calLocation(){
    QPointF nowPoint;
    double x;
    double y;
    double nowTime = (double)timeTotal.elapsed()/(10000) + (double)startTime;
    for(int i = 0; i < routeArr.size();i++){
        int startI = routeArr.at(i).toObject().value("startTime").toInt();
        int endI = routeArr.at(i).toObject().value("endTime").toInt();
        int transType = routeArr.at(i).toObject().value("transType").toInt();
        if(nowTime < (double)startI){
            break;
        }
        else if(nowTime >= (double)startI && nowTime < double(endI)){
            double startX = startPointList.at(i).x();
            double endX = endPointList.at(i).x();
            double startY = startPointList.at(i).y();
            double endY = endPointList.at(i).y();
            x = startX + (nowTime-(double)startI)*(endX - startX)/(endI - startI);
            y = startY + (nowTime-(double)startI)*(endY - startY)/(endI -startI);
            if(transType == 1){
                state = 1;
            }
            if(transType == 2){
                state = 2;
            }
            if(transType == 3){
                state = 3;
            }
            break;
        }
        else if(nowTime >= double(endI) && nowTime <= routeArr.at(i + 1).toObject().value("startTime").toInt() && i < routeArr.size() - 1){
            state = 4;
            x = (double)endPointList.at(i).x();
            y = (double)endPointList.at(i).y();
            break;
        }
        else if(i == routeArr.size() - 1 && nowTime >=(double)endI){
            state = 4;
            x = (double)endPointList.at(i).x();
            y = (double)endPointList.at(i).y();
            break;
        }
    }
    nowPoint.setX(x);
    nowPoint.setY(y);
    return nowPoint;
}

void TravelMap::paintEvent(QPaintEvent *){
    QPainter painter(this);
    int nowW = timeTotal.elapsed()/(10000);
    double nowWT = (double)timeTotal.elapsed()/(10000) + (double)startTime;
    for(int i = 0;i < routeArr.size();i++){
        int startI = routeArr.at(i).toObject().value("startTime").toInt();
        int endI = routeArr.at(i).toObject().value("endTime").toInt();
        if(nowWT < startI){
            break;
        }
        if(nowWT >= startI && nowWT < endI){
            qDebug() << "in moving" << endl;
            model->clear();
            QString trainNum = "车次：" + routeArr.at(i).toObject().value("trainNum").toString();
            QStandardItem *numItem = new QStandardItem(trainNum);
            model->appendRow(numItem);
            QString fromCity = "始发城市：" + cityName.at(routeArr.at(i).toObject().value("fromCity").toInt() - 1);
            QStandardItem *fromItem = new QStandardItem(fromCity);
            model->appendRow(fromItem);
            QString toCity = "终到城市：" + cityName.at(routeArr.at(i).toObject().value("toCity").toInt() - 1);
            QStandardItem *toItem = new QStandardItem(toCity);
            model->appendRow(toItem);
            QString startMoment = "出发时间：" + QString::number(routeArr.at(i).toObject().value("startTime").toInt()) + ":00";
            QStandardItem *startItem = new QStandardItem(startMoment);
            model->appendRow(startItem);
            QString endMoment = "到达时间：" + QString::number(routeArr.at(i).toObject().value("endTime").toInt()) + ":00";
            QStandardItem *endItem = new QStandardItem(endMoment);
            model->appendRow(endItem);
            ui->stateList->setModel(model);
            ui->stateList->show();
            break;
        }
        if(nowWT >= endI && nowWT < routeArr.at(i+1).toObject().value("startTime").toInt()
                && i < routeArr.size() - 1){
            qDebug() <<"in waiting" << endl;
            model->clear();
            QString str = "在" + cityName.at(routeArr.at(i).toObject().value("toCity").toInt() - 1) + "停留"
                    + QString::number(routeArr.at(i+1).toObject().value("startTime").toInt() - endI) + "小时";
            QStandardItem *waitItem = new QStandardItem(str);
            model->appendRow(waitItem);
            ui->stateList->setModel(model);
            ui->stateList->show();
            break;
        }
        if(nowWT >= endI && i == routeArr.size() - 1){
            qDebug() << "in arrive" << endl;
            model->clear();
            QString endStr = "您已到达";
            QStandardItem *endItem = new QStandardItem(endStr);
            model->appendRow(endItem);
            ui->stateList->setModel(model);
            ui->stateList->show();
            break;
        }
    }

    if( startTime + nowW== endTime){
        timer->stop();
        QString nowTime = QString::number(routeArr.at(routeArr.size() - 1).toObject().value("endTime").toInt())
                + ":" + "00";
        ui->nowTime->display(nowTime);
    }
    else if(startTime + nowW > endTime){
        QString nowTime = QString::number(routeArr.at(routeArr.size() - 1).toObject().value("endTime").toInt())
                + ":" + "00";
        ui->nowTime->display(nowTime);
    }
    else{
        QString nowStr = QString::number(startTime + nowW) + ":" +"00";
        ui->nowTime->display(nowStr);
    }
}

MyLabel::MyLabel(QWidget *parent) :
    QLabel(parent)
{
    timerLabel = new QTimer(this);
    connect(timerLabel, SIGNAL(timeout()), this, SLOT(update()));
    timerLabel->start(1000);
}

void MyLabel::TimeOut(){
    int nowL = timeTotal.elapsed()/(10000);
    if(nowL + startTime == endTime){
        timerLabel->stop();
    }
    update();
}

void MyLabel::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPointF now = calLocation();
    if(state == 4){
        painter.drawPixmap(now, QPixmap(":/wait.jpg"));
    }
    if(state == 1){
        painter.drawPixmap(now, QPixmap(":/plane.jpg"));
    }
    if(state == 2){
        painter.drawPixmap(now, QPixmap(":/train.jpg"));
    }
    if(state == 3){
        painter.drawPixmap(now, QPixmap(":/car.jpg"));
    }
}

void TravelMap::show(){
    ui->Beijing->hide();
    ui->Tianjin->hide();
    ui->Shanghai->hide();
    ui->Chongqing->hide();
    ui->Haerbin->hide();
    ui->Shenyang->hide();
    ui->Shijiazhuang->hide();
    ui->Xian->hide();
    ui->Jinan->hide();
    ui->Guangzhou->hide();
    ui->Changsha->hide();
    ui->Nanjing->hide();
    ui->Wuhan->hide();
    ui->Chengdu->hide();
    ui->Shenzhen->hide();
    this->readRoute();
    QString startTime = QString::number(routeArr.at(0).toObject().value("startTime").toInt())
            + ":" + "00";
    QString endTime = QString::number(routeArr.at(routeArr.size() - 1).toObject().value("endTime").toInt())
            + ":" + "00";
    ui->startTime->display(startTime);
    ui->arrTime->display(endTime);
    QWidget::show();
}
void TravelMap::on_backBtn_clicked()
{
    emit back();
}
