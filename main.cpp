#include "mainwindow.h"
#include "jsoncalls.h"
#include <QApplication>
#include <QWindow>
#include <QJsonObject>
#include <QJsonDocument>
#include <QtNetwork>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
