#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "carte.h"
#include "client.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushbutton_clicked();

    void on_pushButton_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_tabWidget_3_currentChanged(int index);

    void on_pushButton_3_clicked();


    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_radioButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void makePlot();
private:
    Ui::MainWindow *ui;
    Carte tmpcarte;
    Client tmpclient;
};
#endif // MAINWINDOW_H
