#include "mainwindow.h"
#include<common.h>
float cityRisk[] = {0.9, 0.5, 0.5, 0.5, 0.9, 0.5, 0.2, 0.2, 0.2, 0.5, 0.2, 0.2, 0.9, 0.2, 0.5};
int transRisk[] = {9, 5, 2};
int reMap[15][24];
int map[288][288];
QStringList cityName = {"北京", "天津", "上海", "重庆", "哈尔滨",
                        "沈阳", "石家庄", "西安", "济南", "广州",
                      "长沙", "南京", "武汉", "成都", "深圳"};
int count;
QJsonArray infoArr;
QJsonArray routeArr;
QTime timeTotal;
QStringList logList = {};
QString FILE_PATH("./log.txt");
class CommonHelper
{
public:
    static void setStyle(const QString &style) {
        QFile qss(style);
        qss.open(QFile::ReadOnly);
        qApp->setStyleSheet(qss.readAll());
        qss.close();
    }
};
int findCity(int node){
    for(int i = 1;i <=15;i++){
        for(int j = 0;j < 24;j++){
            if(reMap[i][j] == node){
                return i;
            }
        }
    }
}
int findHour(int node){
    for(int i = 1;i <=15;i++){
        for(int j = 0;j < 24;j++){
            if(reMap[i][j] == node){
                return j;
            }
        }
    }
}
void loadWaitingData(){
    for(int i = 1;i < count;i++){
        for(int j = 1;j < count;j++){
            if(findCity(i) == findCity(j) && findHour(j) > findHour(i)){
                map[i][j] = cityRisk[findCity(i)] * (findHour(j) - findHour(i));
                //                qDebug() << "i:" << i << "j:" << j << "risk:" <<map[i][j];
            }
        }
    }
}
void loadData(){
    int dd =1;
    count = 1;
    memset(reMap, 0, sizeof (reMap));
    memset(map, 0, sizeof (map));
    QDir dir = QDir::current();
    QFile file(dir.filePath("timetable.csv"));
    if(!file.open(QIODevice::ReadOnly))
        qDebug() << "open file failed";
    QTextStream *out = new QTextStream(&file);
    QStringList line = out -> readAll().split("\n");
    for(int i = 1; i < line.count() - 1; i++){
        QStringList info = line.at(i).split(",");
        int fromCity = info.at(1).toInt();
        int toCity = info.at(2).toInt();
        int transType = info.at(3).toInt();
        int startTime = info.at(5).split(":").at(0).toInt();
        int endTime = info.at(6).split(":").at(0).toInt();
        QString trainNum = info.at(4);
        int price = info.at(7).toInt();
        QJsonObject infoObj;
        infoObj.insert("fromCity", fromCity);
        infoObj.insert("toCity", toCity);
        infoObj.insert("transType", transType);
        infoObj.insert("startTime", startTime);
        infoObj.insert("endTime", endTime);
        infoObj.insert("trainNum", trainNum);
        infoObj.insert("price", price);
        infoArr.push_back(infoObj);
        int risk = cityRisk[fromCity - 1] * transRisk[transType - 1] * (endTime - startTime);
        if(risk == 0){
            risk = 1;
        }
        if(reMap[fromCity][startTime] == 0){
            reMap[fromCity][startTime] = count;
            count ++;
        }
        if(reMap[toCity][endTime] == 0){
            reMap[toCity][endTime] = count;
            count ++;
        }
        int fromNode = reMap[fromCity][startTime];
        int toNode = reMap[toCity][endTime];
        map[fromNode][toNode] = risk;
    }
    file.close();
    loadWaitingData();
}
void loadLog(){
    QFile csvFile(FILE_PATH);
    if (csvFile.open(QIODevice::ReadWrite))
    {
        QTextStream stream(&csvFile);
        while (!stream.atEnd()){
            logList.push_back(stream.readLine() + "\n");
        }
    csvFile.close();
    }
}

int main(int argc, char *argv[])
{
    if (!qEnvironmentVariableIsSet("QT_DEVICE_PIXEL_RATIO")                     // 高分屏支持
            && !qEnvironmentVariableIsSet("QT_AUTO_SCREEN_SCALE_FACTOR")
            && !qEnvironmentVariableIsSet("QT_SCALE_FACTOR")
            && !qEnvironmentVariableIsSet("QT_SCREEN_SCALE_FACTORS")) {
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    }
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    //加载qss样式
    CommonHelper::setStyle(":/Qss/style.qss");
    loadData();
    loadLog();
    MainWindow w;
    w.setWindowTitle("低风险旅行模拟系统");
    w.show();
    return a.exec();
}
