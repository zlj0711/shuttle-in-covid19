#include "routequery.h"
#include "ui_routequery.h"
extern int reMap[15][24];
extern int map[288][288];
extern int count;
int resultI[288];
int road[288][288];
extern QJsonArray infoArr;
extern QJsonArray routeArr;
extern QTime timeTotal;
extern QStringList cityName;
extern QStringList logList;
RouteQuery::RouteQuery(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RouteQuery)
{
    ui->setupUi(this);
    connect(&mapWindow,&TravelMap::back,this,&RouteQuery::fromTravelMap);
}

RouteQuery::~RouteQuery()
{
    delete ui;
}

void RouteQuery::on_backBtn_clicked()
{
    emit back();
}

void RouteQuery::show(){
    ui->label->setText("请输入您的计划旅行信息");
    ui->backBtn->show();
    ui->queryBtn->show();
    ui->fromChoice->show();
    ui->toChoice->show();
    ui->toLabel->show();
    ui->fromLabel->show();
    ui->strategyChoice->show();
    ui->strategyLabel->show();
    ui->spinBox->hide();
    ui->timeLabel->hide();
    ui ->startBtn->hide();
    ui->planList->hide();
    ui->backButton->hide();
    QWidget::show();
}
void RouteQuery::on_queryBtn_clicked()
{
    routeArr = {};
    QString logNow = "";
    logNow += ui->fromChoice->currentText();
    logNow += ",";
    logNow += ui->toChoice->currentText();
    logNow += ",";
    logNow += ui->strategyChoice->currentText();
    if(ui->strategyChoice->currentIndex() == 1){
        logNow += ",";
        logNow += QString::number(ui->spinBox->value());
    }
    qDebug() << "log:" << logNow;
    int fromCity = ui->fromChoice->currentIndex() + 1;
    int toCity = ui->toChoice->currentIndex() + 1;
    int strategy = ui->strategyChoice->currentIndex();
    if(fromCity == toCity){
        QMessageBox::information(this, "error!", "目的城市不能与出发城市相同");
    }
    else{
        model->clear();
        ui->planList->setModel(model);
        int time = ui->spinBox->value();
        QStringList solution = calStrategy(fromCity, toCity, strategy,time);
        ui->label->setText("为您规划的低风险旅行计划");
        ui->backBtn->hide();
        ui->queryBtn->hide();
        ui->fromChoice->hide();
        ui->toChoice->hide();
        ui->toLabel->hide();
        ui->fromLabel->hide();
        ui->strategyChoice->hide();
        ui->strategyLabel->hide();
        ui->timeLabel->hide();
        ui->spinBox->hide();
        for(int i = 0;i < solution.size();i++){
            QString str = solution.at(i);
            logNow += ",";
            logNow += str;
            QStandardItem *item = new QStandardItem(str);
            model->appendRow(item);
        }
        logNow += '\n';
        qDebug() << logNow;
        logList.append(logNow);
        ui->planList->setModel(model);
        ui->planList->show();
        ui->backButton->show();
        ui->startBtn->show();
    }

}
int findToCity(int node){
    for(int i = 1;i <=15;i++){
        for(int j = 0;j < 24;j++){
            if(reMap[i][j] == node){
                return i;
            }
        }
    }
}

int dij(int start, int toCity){
    int find = 0;
    memset(road, 0, sizeof(road));
    int minT = 99999;
    for(int j = 1;j <288;j++){
        for(int k = 1;k <=2;k++){
            if(k == 1){
                road[j][k] = start;
            }
            if(map[start][j] != 0 && k ==2){
                road[j][k] = j;
            }
        }
    }
    int flag[288];
    memset(flag, 0, sizeof(flag));
    flag[start] = 1;
    int dist[288];
    for(int i = 1;i < 288;i++){
        dist[i] = map[start][i];
    }
    int result[288];
    memset(result, 0, sizeof (result));
    result[0] = start;
    int u;
    for(int i = 1;i < 288;i++){
        find = 0;
        int min = 99999;
        for(int j = 1; j < 288;j++){
            if(flag[j] == 0 && dist[j] < min && dist[j] != 0){
                min = dist[j];
                u = j;
                find = 1;
            }
        }
        if(find == 0){
            break;
        }
        flag[u] = 1;
        result[i] = u;
        for(int k = 1;k < 288;k++){
            if(map[u][k] != 0){
                if(dist[k] > dist[u] + map[u][k] || dist[k] == 0){
                    dist[k] = dist[u] + map[u][k];
                    for(int t = 1; t < 288;t++){
                        if(road[u][t] != 0){
                            road[k][t] = road[u][t];
                        }
                        else{
                            road[k][t] = k;
                            break;
                        }
                    }
                }
            }
        }
    }
    int record;
    int noFound = 1;
    for(int m = 1; m < 288;m++){
        if(dist[m]!=0){
            if(findToCity(m) == toCity){
                noFound = 0;
                if(dist[m] < minT){
                    minT = dist[m];
                    record = m;
                }
            }
        }
    }
    if(noFound == 0){
        for(int t = 1;t < 288;t++){
            resultI[t-1] = road[record][t];
        }
        return dist[record];
    }
    else{
        return 99999;
    }
}
QString findNodeInfo(int node){
    for(int i = 1;i <=15;i++){
        for(int j = 0;j < 24;j++){
            if(reMap[i][j] == node){
                return QString::number(i) + "," + QString::number(j);
            }
        }
    }
}

int dijTime(int start, int toCity, int time){
    int find = 0;
    int timeNow = 0;
    memset(road, 0, sizeof(road));
    int minT = 99999;
    for(int j = 1;j <288;j++){
        for(int k = 1;k <=2;k++){
            if(k == 1){
                road[j][k] = start;
            }
            if(map[start][j] != 0 && k ==2){
                road[j][k] = j;
            }
        }
    }
    int flag[288];
    memset(flag, 0, sizeof(flag));
    flag[start] = 1;
    int dist[288];
    for(int i = 1;i < 288;i++){
        dist[i] = map[start][i];
    }
    int result[288];
    memset(result, 0, sizeof (result));
    result[0] = start;
    int u;
    for(int i = 1;i < 288;i++){
        find = 0;
        int min = 99999;
        for(int j = 1; j < 288;j++){
            int timeTmp = findNodeInfo(j).split(",").at(0).toInt();
            if(flag[j] == 0 && dist[j] < min && dist[j] != 0 && timeNow + timeTmp <= time){
                min = dist[j];
                u = j;
                find = 1;
                timeNow += timeTmp;
            }
        }
        if(find == 0){
            break;
        }
        flag[u] = 1;
        result[i] = u;
        for(int k = 1;k < 288;k++){
            if(map[u][k] != 0){
                if(dist[k] > dist[u] + map[u][k] || dist[k] == 0){
                    dist[k] = dist[u] + map[u][k];
                    for(int t = 1; t < 288;t++){
                        if(road[u][t] != 0){
                            road[k][t] = road[u][t];
                        }
                        else{
                            road[k][t] = k;
                            break;
                        }
                    }
                }
            }
        }
    }
    int record;
    int noFound = 1;
    for(int m = 1; m < 288;m++){
        if(dist[m]!=0){
            if(findToCity(m) == toCity){
                noFound = 0;
                if(dist[m] < minT){
                    minT = dist[m];
                    record = m;
                }
            }
        }
    }
    if(noFound == 0){
        for(int t = 1;t < 288;t++){
            resultI[t-1] = road[record][t];
        }
        return dist[record];
    }
    else{
        return 99999;
    }
}



QString findPathInfo(int node1, int node2){
    QString nodeInfo1 = findNodeInfo(node1);
    QString nodeInfo2 = findNodeInfo(node2);
    int city1 = nodeInfo1.split(",").at(0).toInt();
    int city2 = nodeInfo2.split(",").at(0).toInt();
    int time1 = nodeInfo1.split(",").at(1).toInt();
    int time2 = nodeInfo2.split(",").at(1).toInt();
    if(city1 == city2){
        QString fullInfo = "在" + cityName.at(city1 - 1) +"停留"
                + QString::number(time2 - time1) + "小时";
        return fullInfo;

    }
    else{
        for(int i = 0;i < infoArr.size();i++){
            if(infoArr.at(i).toObject().value("fromCity") == city1 &&
                    infoArr.at(i).toObject().value("toCity") == city2 &&
                    infoArr.at(i).toObject().value("startTime") == time1 &&
                    infoArr.at(i).toObject().value("endTime") == time2){
                QString fullInfo = infoArr.at(i).toObject().value("trainNum").toString() + "  " +
                        cityName.at(city1 - 1) + "-->" +cityName.at(city2 - 1)+
                        "  " + QString::number(time1) + ":00" + "-->" + QString::number(time2) + ":00"
                        + "  " + "￥" + QString::number(infoArr.at(i).toObject().value("price").toInt());
                routeArr.append(infoArr.at(i).toObject());
                return fullInfo;
            }
        }
    }
}

QStringList RouteQuery::calStrategy(int fromCity, int toCity, int strategyChoice, int time){
    int finalMin = 99999;
    int finalResult[count];
    int minI;
    memset(finalResult, 0, sizeof(finalResult));
    for(int i = 1; i < 24; i++){
        memset(resultI, 0, sizeof(resultI));
        if(reMap[fromCity][i] != 0){
            if(strategyChoice == 0){
                minI = dij(reMap[fromCity][i], toCity);
            }
            else{
                minI = dijTime(reMap[fromCity][i], toCity, time);
            }

            if(minI< finalMin){
                finalMin = minI;
                memcpy(finalResult, resultI, count);
            }
        }
    }
    QString str = "";
    QStringList list;
    for(int i = 0;i < count-1;i++){
        if(finalResult[i + 1] == 0){
            break;
        }
        str  = findPathInfo(finalResult[i], finalResult[i + 1]);
        list.append(str);
    }
    return list;
}

void RouteQuery::on_backButton_clicked()
{
    emit back();
}

void RouteQuery::on_startBtn_clicked()
{
    timeTotal.start();
    this->close();
    mapWindow.show();
}

void RouteQuery::fromTravelMap(){
    this->show();
    mapWindow.close();
    emit back();
}

void RouteQuery::on_strategyChoice_currentIndexChanged(int index)
{
    if(index == 0){
        ui->timeLabel->hide();
        ui->spinBox->hide();
    }
    if(index == 1){
        ui->timeLabel->show();
        ui->spinBox->show();
    }
}
