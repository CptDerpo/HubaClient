#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPropertyAnimation>
#include <QPointer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    void toggleMenu(int maxWidth, bool toggle);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_menuButton_clicked();

private:
    Ui::MainWindow* ui;
    QPointer<QPropertyAnimation> slideMenuAnimation;
};
#endif // MAINWINDOW_H
