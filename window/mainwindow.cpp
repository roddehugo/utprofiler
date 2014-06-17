#include "window/mainwindow.h"
#include "window/ajouteruvwindow.h"
#include "window/modifuvwindow.h"
#include "window/ajoutcursuswindow.h"
#include "window/supprimeruvwindow.h"
#include "window/modifiercursuswindow.h"
#include "window/supprimercursus.h"
#include "window/modeldossier.h"
#include "window/saisirinscription.h"
#include "window/ajoutdossier.h"
#include <QDebug>
#include <QObject>
#include <QMessageBox>

#include "ui_mainwindow.h"

MainWindow::MainWindow(Factory* factory,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    fac(factory)
{

    setAttribute (Qt::WA_DeleteOnClose);
    EtudiantDAO* etudao = fac->getEtudiantDAO();
    Etudiant* me = etudao->getCurrent();
    ui->setupUi(this);
    ui->nom->setText(me->getNom());
    ui->prenom->setText(me->getPrenom());

    QObject::connect(ui->actionAjoutUV , SIGNAL(triggered()), this, SLOT(on_ajouteruv()));
    QObject::connect(ui->actionModifierUV , SIGNAL(triggered()), this, SLOT(modifieruv()));
    QObject::connect(ui->actionSupprimerUV , SIGNAL(triggered()), this, SLOT(suppruv()));
    QObject::connect(ui->actionAjouterCursus , SIGNAL(triggered()), this, SLOT(ajoutercursus()));
    QObject::connect(ui->actionSupprimerCursus , SIGNAL(triggered()), this, SLOT(supprcursus()));
    QObject::connect(ui->actionModifierCursus , SIGNAL(triggered()), this, SLOT(modifiercursus()));
    QObject::connect(ui->exigerUV , SIGNAL(clicked()), this, SLOT(exigerUV()));
    QObject::connect(ui->prefererUV , SIGNAL(clicked()), this, SLOT(prefererUV()));
    QObject::connect(ui->rejeterUV , SIGNAL(clicked()), this, SLOT(rejeterUV()));
    QObject::connect(ui->annulerUV ,SIGNAL(clicked()), this, SLOT(retirerpref()));
        fillMainWindow();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fillMainWindow()
{
    ui->listUV->addItems(fac->getUVDAO()->getStringList("code"));
        qDebug()<<"¡¡¡¡¡¡refill!!!!";
}

void MainWindow::modifieruv(){
    modifUVwindow uvw(fac);
    uvw.exec();
}

void MainWindow::on_ajouteruv()
{
    ajouterUVwindow uvw(fac);
    if (uvw.exec()){
        QString code;
    }


}
void MainWindow::suppruv()
{
    supprimerUVwindow uvw(fac);
    if (uvw.exec()){
        QMessageBox::information(this,"suppression", "supprimé");
    }
}
void MainWindow::ajoutercursus()
{
    ajoutcursuswindow  uvw(fac);
    uvw.exec();
}
void MainWindow::modifiercursus()
{
    modifiercursuswindow uvw(fac);
    uvw.exec();
}
void MainWindow::supprcursus()
{
    supprimerCursus  uvw(fac);
    uvw.exec();
}

void MainWindow::on_remplirDossier_clicked()
{
    saisirinscription uvw(fac);
    uvw.exec();
}

void MainWindow::exigerUV()
{

    if(ui->listUV->currentItem()!=NULL){
        ui->listUVexige->addItem(ui->listUV->currentItem()->text());
        delete ui->listUV->currentItem();
    }

}

void MainWindow::prefererUV()
{

    if(ui->listUV->currentItem()!=NULL){
        ui->listUVpref->addItem(ui->listUV->currentItem()->text());
        delete ui->listUV->currentItem();
    }
}

void MainWindow::rejeterUV()
{

    if(ui->listUV->currentItem()!=NULL){
        ui->listUVrejet->addItem(ui->listUV->currentItem()->text());
        delete ui->listUV->currentItem();
    }
}

void MainWindow::retirerpref()
{
    if(ui->listUVexige->currentItem()!=NULL){
        ui->listUV->addItem(ui->listUVexige->currentItem()->text());
        delete ui->listUVexige->currentItem();
    }
    if(ui->listUVpref->currentItem()!=NULL){
        ui->listUV->addItem(ui->listUVpref->currentItem()->text());
        delete ui->listUVpref->currentItem();
    }
    if(ui->listUVrejet->currentItem()!=NULL){
        ui->listUV->addItem(ui->listUVrejet->currentItem()->text());
        delete ui->listUVrejet->currentItem();
    }
}

void MainWindow::on_ajouterDossier_clicked()
{
    ajoutDossier ajw(fac);
    ajw.exec();
}
