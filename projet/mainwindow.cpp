#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"client.h"
#include"carte.h"
#include<QString>
#include<QMessageBox>
#include<QPixmap>
#include"qcustomplot.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

QPixmap pix("C:/Users/HAYET/Desktop/GAlogo.png");
ui->label_pic->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
ui->label_pic_2->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
ui->label_pic_3->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
ui->label_pic_5->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
ui->label_pic_6->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
ui->label_pic_7->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
MainWindow::makePlot();
}

MainWindow::~MainWindow()
{

    delete ui;
}



void MainWindow::on_pushbutton_clicked()
{
    int id = ui->lineEdit->text().toInt();
    QString type= ui->lineEdit_2->text();
    int points= ui->lineEdit_3->text().toInt();
    int id_client= ui->lineEdit_20->text().toInt();
  Carte e(id,type,points,id_client);
  bool test=e.ajouter();
  if(test)
{ui->tabcarte->setModel(tmpcarte.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une carte"),
                  QObject::tr("Carte ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une carte"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_clicked()
{
    int id = ui->lineEdit_supp->text().toInt();
    bool test=tmpcarte.supprimer(id);
    if(test)
    {ui->tabcarte->setModel(tmpcarte.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une carte"),
                    QObject::tr("carte supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une carte"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
void MainWindow::on_tabWidget_currentChanged(int index)
{
    ui->tabcarte->setModel(tmpcarte.afficher());
    ui->tabcartetri->setModel(tmpcarte.afficherorder());
}




void MainWindow::on_pushButton_3_clicked()
{
    int id = ui->lineEdit_4->text().toInt();
    QString nom= ui->lineEdit_5->text();
    QString prenom= ui->lineEdit_6->text();
    QString adresse= ui->lineEdit_7->text();
    QString date_naiss= ui->lineEdit_8->text();
    Client a(id,nom,prenom,adresse,date_naiss);
    bool test=a.ajouter1();
    if(test)
  {
  ui->tabclient->setModel(tmpclient.afficher1());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
  QObject::tr("Client ajouté.\nClick Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un client "),
                    QObject::tr("Erreur else !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_tabWidget_3_currentChanged(int index)
{
 ui->tabclient->setModel(tmpclient.afficher1());
 ui->tabclient2->setModel(tmpclient.afficherorder1());
}

void MainWindow::on_pushButton_2_clicked()
{
    int id = ui->lineEdit_9->text().toInt();
    bool test=tmpclient.supprimer1(id);
    if(test)
    {ui->tabclient->setModel(tmpclient.afficher1());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("client supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_4_clicked()
{

    int id = ui->lineEdit_10->text().toInt();
    QString nom= ui->lineEdit_11->text();
    QString prenom= ui->lineEdit_12->text();
    QString adresse=ui->lineEdit_13->text();
    QString date_naiss=ui->lineEdit_14->text();
   Client x(id,nom,prenom,adresse,date_naiss);
  bool test=x.modifier1(id);
  if(test)
{ui->tabclient->setModel(tmpclient.afficher1());//refresh
 ui->tabclient2->setModel(tmpclient.afficherorder1());
QMessageBox::information(nullptr, QObject::tr("Modifier client"),
                  QObject::tr("Client modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier client"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pushButton_5_clicked()
{
    int id = ui->lineEdit_15->text().toInt();
    QString type= ui->lineEdit_16->text();
    int points= ui->lineEdit_17->text().toInt();
    int id_client= ui->lineEdit_4->text().toInt();

   Carte x(id,type,points,id_client);
  bool test=x.modifier(id);
  if(test)
{ui->tabcarte->setModel(tmpcarte.afficher());//refresh
 ui->tabcartetri->setModel(tmpcarte.afficherorder());
QMessageBox::information(nullptr, QObject::tr("Modifier carte"),
                  QObject::tr("Carte modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier client"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}




void MainWindow::on_pushButton_6_clicked()
{
    QString id = ui->lineEdit_18->text();


        ui->tabcarterecherche ->setModel(tmpcarte.recherche(id));

}



void MainWindow::on_pushButton_7_clicked()
{
    QString id = ui->lineEdit_19->text();
    ui->tableclientrechercher->setModel(tmpclient.recherche1(id));

}
void MainWindow::makePlot()
{
    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->customPlot->setBackground(QBrush(gradient));

    // create empty bar chart objects:
    //QCPBars *regen = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    //QCPBars *nuclear = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    QCPBars *fossil = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
   // regen->setAntialiased(false); // gives more crisp, pixel aligned bar borders
   // nuclear->setAntialiased(false);
    fossil->setAntialiased(false);
   // regen->setStackingGap(1);
   // nuclear->setStackingGap(1);
    fossil->setStackingGap(1);
    // set names and colors:
    fossil->setName("Nombre des clients");
    fossil->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    fossil->setBrush(QColor(111, 9, 176));
    /*nuclear->setName("Nuclear");
    nuclear->setPen(QPen(QColor(250, 170, 20).lighter(150)));
    nuclear->setBrush(QColor(250, 170, 20));
    regen->setName("Regenerative");
    regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    regen->setBrush(QColor(0, 168, 140));*/
    // stack bars on top of each other:
   // nuclear->moveAbove(fossil);
   // regen->moveAbove(nuclear);

    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7<<8<<9<<10<<11<<12;
    labels << "1.1" << "2.1" << "3.1" << "4.1" << "5.1" << "6.1" << "7.1"<< "8.1" << "9.1" << "10.1" << "11.1" << "12.1";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->customPlot->xAxis->setTicker(textTicker);
    ui->customPlot->xAxis->setTickLabelRotation(60);
    ui->customPlot->xAxis->setSubTicks(false);
    ui->customPlot->xAxis->setTickLength(0, 7);
    ui->customPlot->xAxis->setRange(0, 14);
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->xAxis->grid()->setVisible(true);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->customPlot->yAxis->setRange(0, 12.1);
    ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
    ui->customPlot->yAxis->setLabel("Nombre des clients \n par % date fin(2019)");
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setLabelColor(Qt::white);
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> fossilData;
    fossilData=tmpclient.statistique();
    fossil->setData(ticks, fossilData);

    // setup legend:
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    ui->customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}
