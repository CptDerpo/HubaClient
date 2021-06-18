#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPropertyAnimation>
#include <QPointer>
#include <QListWidget>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    QCoreApplication::setApplicationName("HubaClient");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::listAddFiles(QJsonArray data)
{
    for (const auto &v : data)
    {
        QListWidgetItem* dog = new QListWidgetItem;
        dog->setText(v.toObject().value("name").toString());
        dog->setForeground(Qt::white);

        qDebug() << v.toObject().value("name").toString();
        dog->setIcon(QIcon(":/resource/file.svg"));
        ui->fileListWidget->addItem(dog);
    }
}



QJsonArray MainWindow::getDirJSON(QString path)
{
    QNetworkRequest request{QUrl(queryUrl + path)};
    qDebug() << queryUrl + path;
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkAccessManager man;

    QPointer<QNetworkReply> reply = man.get(request);

    while(!reply->isFinished())
    {
        QApplication::processEvents();
    }

    QByteArray response_data = reply.data()->readAll();
    QJsonDocument dirjson = QJsonDocument::fromJson(response_data);

    QJsonObject object = dirjson.object();
    QJsonValue value = object.value("Files");
    QJsonArray array = value.toArray();
    return array;
}

void MainWindow::toggleMenu(int maxWidth, bool toggle)
{
    if(toggle)
    {
        //INIT WIDTH
        int width {ui->frameMenu->width()};
        int widthExtended { };

        //SET MAX WIDTH
        if (width == 0) widthExtended = maxWidth;
        else widthExtended = 0;

        //ANIMATE MOIST MOIST MOOOOOOIST

        slideMenuAnimation = new QPropertyAnimation(ui->frameMenu, "minimumWidth");
        slideMenuAnimation.data()->setDuration(400);
        slideMenuAnimation.data()->setStartValue(width);
        slideMenuAnimation.data()->setEndValue(widthExtended);
        slideMenuAnimation.data()->start(QAbstractAnimation::DeleteWhenStopped);
    }

}

void MainWindow::on_menuButton_clicked()
{
    if(slideMenuAnimation.data()){
        return;
    }
    toggleMenu(300, true);
}

void MainWindow::on_closeBtn_clicked()
{
    QCoreApplication::quit();
}

void MainWindow::on_maxBtn_clicked()
{
    static bool isMax = false;
    if(!isMax)
    {
        this->setWindowState(Qt::WindowMaximized);
        isMax = true;
    }
    else
    {
        this->setWindowState(Qt::WindowNoState);
        isMax = false;
    }
}

void MainWindow::on_minBtn_clicked()
{
    this->setWindowState(Qt::WindowMinimized);
}

void MainWindow::on_filesBtn_clicked()
{
    ui->fileListWidget->clear();
    QJsonArray files = getDirJSON(".");
    listAddFiles(files);
}

