#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPropertyAnimation>
#include <QPointer>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

MainWindow::~MainWindow()
{
    delete ui;
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
        slideMenuAnimation.data()->start();
    }

}

void MainWindow::on_menuButton_clicked()
{
    toggleMenu(300, true);
}

