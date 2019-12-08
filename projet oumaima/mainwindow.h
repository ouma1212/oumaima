#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "personnel.h"
#include"service.h"
#include<QString>
#include <QMainWindow>
#include <QSystemTrayIcon>


namespace Ui
{
class MainWindow;
}

class QSystemTrayIcon;
class MainWindow : public QMainWindow
{
    Q_OBJECT
  public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked();
    void on_pb_modifier_clicked();
    void on_pb_rechercher_clicked();

    void on_pb_verifier_clicked();
     void on_pb_ajouter_s_clicked();
     void on_pb_supprimer_s_clicked();
     void on_pb_modifier_s_clicked();
     void on_pb_verifier_s_clicked();
     void on_pb_rechercher_s_clicked();


     void on_actionQuitter_triggered();

     void on_actionA_propos_de_Qt_triggered();

private:
    Ui::MainWindow *ui;
    QSystemTrayIcon *mSystemTrayIcon;

    Personnel tmppersonnel;
    service tmpservice;
};
#endif // MAINWINDOW_H
