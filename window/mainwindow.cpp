#include "window/mainwindow.h"
#include "window/ajouteruvwindow.h"
#include "window/modifuvwindow.h"
#include "window/ajoutcursuswindow.h"
#include "window/supprimeruvwindow.h"
#include "window/modifiercursuswindow.h"
#include "window/supprimercursus.h"
#include "window/modeldossier.h"
#include "window/saisirinscription.h"
#include "window/ajoutsemestres.h"
#include "window/ajoutdossier.h"
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>

#include "ui_mainwindow.h"

MainWindow::MainWindow(Factory* factory,QWidget *parent) :
    QMainWindow(parent),
 //   m_pTableWidget(NULL),
    m_tree(NULL),
    ui(new Ui::MainWindow),
    fac(factory)
{
//    m_pTableWidget = new QTableWidget(ui->frame);
//    m_pTableWidget->setRowCount(0);
//    m_pTableWidget->setColumnCount(5);
//    m_pTableWidget->verticalHeader()->setVisible(false);
//    m_pTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
//    m_pTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
//    m_pTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
//    m_pTableWidget->setShowGrid(true);
//    m_pTableWidget->setGeometry(QApplication::desktop()->screenGeometry());
//    m_pTableWidget->horizontalHeader()->setStretchLastSection(true);
//    QTableWidgetItem *h1 = new QTableWidgetItem("Titre");
//    h1->setTextAlignment(Qt::AlignLeft);
//    QTableWidgetItem *h2 = new QTableWidgetItem("Saison");
//    h2->setTextAlignment(Qt::AlignLeft);
//    QTableWidgetItem *h3 = new QTableWidgetItem("Année");
//    h3->setTextAlignment(Qt::AlignLeft);
//    QTableWidgetItem *h4 = new QTableWidgetItem("Etranger");
//    h4->setTextAlignment(Qt::AlignLeft);
//    QTableWidgetItem *h5 = new QTableWidgetItem("Cursus");
//    h5->setTextAlignment(Qt::AlignLeft);
//    m_pTableWidget->setHorizontalHeaderItem(0,h1);
//    m_pTableWidget->setHorizontalHeaderItem(1,h2);
//    m_pTableWidget->setHorizontalHeaderItem(2,h3);
//    m_pTableWidget->setHorizontalHeaderItem(3,h4);
//    m_pTableWidget->setHorizontalHeaderItem(4,h5);
//    m_pTableWidget->setFixedSize(493,370);

//    m_tree = new QTreeWidget(ui->widget_3);
//    m_tree->setColumnCount(4);
//    QTreeWidgetItem* headerItem = new QTreeWidgetItem();
//    headerItem->setText(0,QString("Nom"));
//    headerItem->setText(1,QString("Titre"));
//    headerItem->setText(2,QString("Crédits"));
//    headerItem->setText(2,QString("Catégories"));
//    m_tree->setHeaderItem(headerItem);

    currentEtudiant = fac->getEtudiantDAO()->getCurrent();
    ui->setupUi(this);
    ui->nom->setText(currentEtudiant->getNom());
    ui->prenom->setText(currentEtudiant->getPrenom());

    listDossiers = fac->getDossierDAO()->findByEtudiant(currentEtudiant->ID());
    if(listDossiers.count()==0){
        Dossier* fold = new Dossier("Dossier de "+currentEtudiant->getLogin(),false,currentEtudiant);
        fac->getDossierDAO()->create(fold);
        listDossiers << fold->getTitre();
        ui->dossierCombo->addItem(fold->getTitre());
    }else{
        ui->dossierCombo->addItems(listDossiers);
    }

    currentDossier = fac->getDossierDAO()->findByStr(ui->dossierCombo->currentText());
    fac->getDossierDAO()->setCurrent(currentDossier);


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
    ui->listUV->clear();
    ui->listUV->addItems(fac->getUVDAO()->getStringList("code"));
}

void MainWindow::modifieruv(){
    modifUVwindow  uvw(fac);
    if (uvw.exec()){
        fillMainWindow();
    }
}

void MainWindow::on_ajouteruv()
{
    ajouterUVwindow uvw(fac);
    if (uvw.exec()){
        fillMainWindow();
    }


}
void MainWindow::suppruv()
{
    supprimerUVwindow uvw(fac);
    if (uvw.exec()){
        fillMainWindow();
    }
}
void MainWindow::ajoutercursus()
{
    ajoutcursuswindow uvw(fac);
    if (uvw.exec()){
        fillMainWindow();
    }
}
void MainWindow::modifiercursus()
{
    modifiercursuswindow uvw(fac);
    if (uvw.exec()){
        fillMainWindow();
    }
}
void MainWindow::supprcursus()
{
    supprimerCursus uvw(fac);
    if (uvw.exec()){
        fillMainWindow();
    }
}

void MainWindow::on_remplirDossier_clicked()
{
    saisirinscription uvw(fac);
    if (uvw.exec()){
        fillMainWindow();
    }
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
//    ajoutdossier* uvw=new ajoutdossier(fac);
//    uvw.exec();
    bool ok;
    QString text = QInputDialog::getText(this, "Ajouter un dossier", "Nom du dossier", QLineEdit::Normal,"",&ok);
    if (ok && !text.isEmpty()){
        Dossier* fold = new Dossier(text,false,currentEtudiant);
        fac->getDossierDAO()->create(fold);
        listDossiers << fold->getTitre();
    }
}

void MainWindow::on_inscrireSemestre_clicked()
{
    ajoutSemestres uvw(fac);
    if (uvw.exec()){
        fillMainWindow();
    }
}

void MainWindow::on_dossierCombo_currentTextChanged(const QString &arg1)
{

    currentDossier = fac->getDossierDAO()->findByStr(arg1);
    fac->getDossierDAO()->setCurrent(currentDossier);
//    QMessageBox msgBox;
//    msgBox.setText("Le dossier en cours est :\n"+currentDossier->getTitre());
//    msgBox.exec();
}
