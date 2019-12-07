#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personnel.h"
#include"service.h"
#include<QString>
#include <QMessageBox>
#include<QPixmap>
#include<QSystemTrayIcon>



MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent)
    ,ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mSystemTrayIcon=new QSystemTrayIcon(this);
    QPixmap pix("C:/Users/user/Pictures/QT_picture/images.png");
    ui->label_pic->setPixmap(pix);

    QPixmap pixs("C:/Users/user/Pictures/pictures/slide-side-8.png");
    ui->label_pic_s->setPixmap(pixs);
    int w=ui->label_pic_s->width();
    int h=ui->label_pic_s->height();
    ui->label_pic_s->setPixmap(pixs.scaled(w,h,Qt::KeepAspectRatio));
   mSystemTrayIcon= new QSystemTrayIcon(this);
        mSystemTrayIcon ->setIcon(QIcon(":/ myappico.png"));
        mSystemTrayIcon ->setVisible(true);




    ui->tabpersonnel->setModel(tmppersonnel.afficher());
    ui->tabservice->setModel(tmpservice.afficher());
       ui->tab_tri->setModel(tmppersonnel.afficher_personnel_trier());
         ui->tabs_tri->setModel(tmpservice.afficher_service_trier());
        for(int i=25 ;i<60;i++)

         {

             ui->comboBox->addItem(QString::number(i)+"ans");

          }
}






MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString  age= ui->comboBox->currentText();
    int id_service = ui->lineEdit_id_service->text().toInt();

  Personnel p(id,nom,prenom,age,id_service);
  bool test=p.ajouter();
  if(test)
{   mSystemTrayIcon->showMessage(tr("Ajouter un personnel!"),
                                 tr("personnel ajouté.\n"));
      ui->tabpersonnel->setModel(tmppersonnel.afficher());//refresh
         ui->tab_tri->setModel(tmppersonnel.afficher_personnel_trier());
QMessageBox::information(nullptr, QObject::tr("Ajouter un personnel"),
                  QObject::tr("Personnel ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);



}
  else

            QMessageBox::critical(nullptr, QObject::tr("Ajouter un personnel"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{  mSystemTrayIcon->showMessage(tr("supprimer un personnel!"),
                                tr("personnel supprimé .\n"));
int id = ui->tmppersonnel->text().toInt();
bool test=tmppersonnel.supprimer(id);
if(test)
{
    ui->tabpersonnel->setModel(tmppersonnel.afficher());//refresh
   ui->tab_tri->setModel(tmppersonnel.afficher_personnel_trier());
    QMessageBox::information(nullptr, QObject::tr("Supprimer un personnel"),
                QObject::tr("Personnel supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un personnel"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);





}


void MainWindow::on_pb_modifier_clicked()
{mSystemTrayIcon->showMessage(tr("modifier un personnel!"),
                              tr("personnel modifié.\n"));
    int id = ui->lineEdit_idm->text().toInt();
    QString nom= ui->lineEdit_nomm->text();
    QString prenom= ui->lineEdit_premomm->text();
     QString age= ui->lineEdit_agem->text();
     int id_service = ui->lineEdit_3->text().toInt();

   Personnel p(id,nom,prenom,age,id_service);
  bool test=p.modifier(id);
  if(test)
{ui->tabpersonnel->setModel(tmppersonnel.afficher());//refresh
   ui->tab_tri->setModel(tmppersonnel.afficher_personnel_trier());
QMessageBox::information(nullptr, QObject::tr("Modifier un personnel"),
                  QObject::tr("Personnel modifier.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier personnel"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}




void MainWindow::on_pb_verifier_clicked()
{
    mSystemTrayIcon->showMessage(tr("Verifier un personnel!"),
                                          tr("personnel verifié.\n"));
    int id = ui->lineEdit_7->text().toInt();

       Personnel test= tmppersonnel.verifier(id);

       if (test.get_id()==id)

      {

           QMessageBox::information(nullptr, QObject::tr("Rechercher un Personnel"),

                           QObject::tr("Personnel trouvé.\n"

                                       "Click Cancel to exit."),
QMessageBox::Cancel);

            }

       else


       {

           QMessageBox::critical(nullptr, QObject::tr("Error !"),

           QObject::tr("Echech de l'Opération !.\n"

                        "Click Cancel to exit."), QMessageBox::Cancel);

       }

}

void MainWindow::on_pb_rechercher_clicked()
{
    mSystemTrayIcon->showMessage(tr("rechercher un service!"),
                                     tr("service recherché.\n"));
    QString str=ui->lineEdit_id_4->text();
    ui->tableView->setModel(tmppersonnel.recherche(str));
}




void MainWindow::on_pb_ajouter_s_clicked()
{
mSystemTrayIcon->showMessage(tr("Ajouter un service!"),
                                 tr("service ajouté.\n"));
    int id_service = ui->lineEdit_ids->text().toInt();
    QString nom= ui->lineEdit_noms->text();

  service p(id_service,nom);
  bool test=p.ajouter();
  if(test)
{
      ui->tabservice->setModel(tmpservice.afficher());//refresh
         ui->tabs_tri->setModel(tmpservice.afficher_service_trier());
QMessageBox::information(nullptr, QObject::tr("Ajouter un service"),
                  QObject::tr("service ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un service"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_s_clicked()
{ mSystemTrayIcon->showMessage(tr("Supprimer un service!"),
                               tr("service supprimé.\n"));
int id = ui->lineEdit_4->text().toInt();
bool test=tmpservice.supprimer(id);
if(test)
{
    ui->tabservice->setModel(tmpservice.afficher());//refresh
       ui->tabs_tri->setModel(tmpservice.afficher_service_trier());
    QMessageBox::information(nullptr, QObject::tr("Supprimer un service"),
                QObject::tr("service supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un service"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_pb_modifier_s_clicked()
{ mSystemTrayIcon->showMessage(tr("modifier un service!"),
                               tr("service modifié.\n"));


    int id_service = ui->lineEdit_id_servicem->text().toInt();
    QString nom= ui->lineEdit_nomm_3->text();


   service s(id_service,nom);
  bool test=s.modifier(id_service);
  if(test)
{ui->tabservice->setModel(tmpservice.afficher());//refresh
   ui->tabs_tri->setModel(tmpservice.afficher_service_trier());
QMessageBox::information(nullptr, QObject::tr("Modifier un service"),
                  QObject::tr("service modifier.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier service"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_pb_verifier_s_clicked()

{ mSystemTrayIcon->showMessage(tr("verifier un service!"),
                               tr("service vérifié.\n"));

    int id_service= ui->lineEdit->text().toInt();

       service test= tmpservice.verifier(id_service);

       if (test.get_id_service()==id_service)

             {

           QMessageBox::information(nullptr, QObject::tr("Rechercher un service"),

                           QObject::tr("service trouvé.\n"

                                       "Click Cancel to exit."),
QMessageBox::Cancel);

             }

       else


       {

           QMessageBox::critical(nullptr, QObject::tr("Error !"),

           QObject::tr("Echech de l'Opération !.\n"

                        "Click Cancel to exit."), QMessageBox::Cancel);

       }

}


void MainWindow::on_pb_rechercher_s_clicked()
{

    QString str=ui->lineEdit_2->text();
    ui->tableView_3->setModel(tmpservice.recherche(str));
}



















void MainWindow::on_actionQuitter_triggered()
{
    close();
}



void MainWindow::on_actionA_propos_de_Qt_triggered()
{
    QMessageBox::information(nullptr, QObject::tr("info !"),

    QObject::tr("information qt !.\n"

                 "Click Cancel to exit."), QMessageBox::Cancel);

}
