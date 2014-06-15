#include "window/mainwindow.h"
#include "window/ajouteruvwindow.h"
#include "window/modifuvwindow.h"
#include "window/ajoutcursuswindow.h"
#include "window/supprimeruvwindow.h"
#include "window/modifiercursuswindow.h"
#include "window/supprimercursus.h"
#include "window/remplirdossier.h"
#include <QDebug>
#include <QMessageBox>

#include "ui_mainwindow.h"

MainWindow::MainWindow(Factory* factory,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    fac(factory)
{
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
    QObject::connect(ui->remplirDossier , SIGNAL(clicked()), this, SLOT(on_remplirDossier_clicked()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::modifieruv(){
    modifUVwindow *uvw= new modifUVwindow(fac);
    uvw->exec();
}

void MainWindow::on_ajouteruv()
{
     ajouterUVwindow * uvw= new ajouterUVwindow(fac);
     if (uvw->exec()){
            QString code;
//            code=uvw->getCode();
//            QMessageBox msgBox;
//            msgBox.setText(code);
//            msgBox.exec();


     }}
void MainWindow::suppruv()
{
     supprimerUVwindow * uvw= new supprimerUVwindow(fac);
     if (uvw->exec()){
            QMessageBox::information(this,"suppression", "supprimé");
        }
}
void MainWindow::ajoutercursus()
{
     ajoutcursuswindow * uvw= new ajoutcursuswindow(fac);
        uvw->exec();
}
void MainWindow::modifiercursus()
{
     modifiercursuswindow * uvw= new modifiercursuswindow(fac);
        uvw->exec();
}
void MainWindow::supprcursus()
{
     supprimerCursus * uvw= new supprimerCursus(fac);
        uvw->exec();
}

void MainWindow::on_remplirDossier_clicked()
{
 remplirDossier* uvw=new remplirDossier(fac);
 uvw->exec();
}
