#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPropertyAnimation>
#include <QPointer>
#include <QNetworkAccessManager>
#include <QNetworkReply>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    void toggleMenu(int maxWidth, bool toggle);
    QJsonArray getDirJSON(QString path);
    void listAddFiles(QJsonArray data);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_menuButton_clicked();
    void on_closeBtn_clicked();
    void on_minBtn_clicked();
    void on_maxBtn_clicked();


    void on_filesBtn_clicked();

private:
    Ui::MainWindow* ui;
    QPointer<QPropertyAnimation> slideMenuAnimation;
    QString queryUrl = "http://localhost:8081/api/getDir?path=";
};
#endif // MAINWINDOW_H
