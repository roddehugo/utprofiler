#include "window/mainwindow.h"
#include "window/ajouteruvwindow.h"
#include "window/modifuvwindow.h"
#include "window/ajoutcursuswindow.h"
#include "window/supprimeruvwindow.h"
#include "window/modifiercursuswindow.h"
#include "window/supprimercursus.h"


#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->actionAjoutUV , SIGNAL(triggered()), this, SLOT(on_ajouteruv()));
    QObject::connect(ui->actionModifierUV , SIGNAL(triggered()), this, SLOT(modifieruv()));
    QObject::connect(ui->actionSupprimerUV , SIGNAL(triggered()), this, SLOT(suppruv()));
    QObject::connect(ui->actionAjouterCursus , SIGNAL(triggered()), this, SLOT(ajoutercursus()));
    QObject::connect(ui->actionSupprimerCursus , SIGNAL(triggered()), this, SLOT(supprcursus()));
    QObject::connect(ui->actionModifierCursus , SIGNAL(triggered()), this, SLOT(modifiercursus()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::modifieruv(){
    modifUVwindow *uvw= new modifUVwindow();
    uvw->exec();
}

void MainWindow::on_ajouteruv()
{
     ajouterUVwindow * uvw= new ajouterUVwindow();
        uvw->exec();
}
void MainWindow::suppruv()
{
     supprimerUVwindow * uvw= new supprimerUVwindow();
        uvw->exec();
}
void MainWindow::ajoutercursus()
{
     ajoutcursuswindow * uvw= new ajoutcursuswindow();
        uvw->exec();
}
void MainWindow::modifiercursus()
{
     modifiercursuswindow * uvw= new modifiercursuswindow();
        uvw->exec();
}
void MainWindow::supprcursus()
{
     supprimerCursus * uvw= new supprimerCursus();
        uvw->exec();
}
