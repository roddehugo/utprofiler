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
#include <QApplication>
#include "ui_mainwindow.h"

MainWindow::MainWindow(Factory* factory,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    fac(factory)
{

    currentEtudiant = fac->getEtudiantDAO()->getCurrent();
    ui->setupUi(this);
    ui->nom->setText(currentEtudiant->getNom());
    ui->prenom->setText(currentEtudiant->getPrenom());

    ui->m_tree->setColumnCount(4);
    QTreeWidgetItem* headerItem = new QTreeWidgetItem();
    headerItem->setText(0,QString("Nom"));
    headerItem->setText(1,QString("Titre"));
    headerItem->setText(2,QString("Crédits"));
    headerItem->setText(3,QString("Catégories"));
    ui->m_tree->setHeaderItem(headerItem);

    ui->m_tree->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->m_tree->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->m_tree->setSelectionMode(QAbstractItemView::SingleSelection);

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

    QList <Dossier *> myDossiers = fac->getDossierDAO()->findAllByEtudiant(currentEtudiant->ID());

    for (QList<Dossier *>::const_iterator d = myDossiers.begin(); d != myDossiers.end(); ++d) {
        qDebug()<<(*d)->getTitre();
        QTreeWidgetItem *folderWidget = new QTreeWidgetItem(ui->m_tree,QStringList( (*d)->getTitre() ));

        QList<Semestre *> mySemestres = fac->getInscriptionDAO()->findSemestresByDossier( (*d)->ID() );
        for(QList<Semestre *>::const_iterator s = mySemestres.begin(); s != mySemestres.end(); ++s){
            qDebug() << (*s)->getTitre();

            QStringList columns;
            columns << (*s)->getTitre()
                    << (*s)->getComputedCode()
                    << QString::number( fac->getSemestreDAO()->calculEcts( (*s)->ID() ) );
                   // << (*s)->getCursus()->getTitre();
            qDebug() << columns;
            QTreeWidgetItem *semWidget = new QTreeWidgetItem(folderWidget, columns );

        }

    }

    ui->m_tree->header()->resizeSections(QHeaderView::ResizeToContents);


    connect(ui->actionAjoutUV , SIGNAL(triggered()), this, SLOT(on_ajouteruv()));
    connect(ui->actionModifierUV , SIGNAL(triggered()), this, SLOT(modifieruv()));
    connect(ui->actionSupprimerUV , SIGNAL(triggered()), this, SLOT(suppruv()));
    connect(ui->actionAjouterCursus , SIGNAL(triggered()), this, SLOT(ajoutercursus()));
    connect(ui->actionSupprimerCursus , SIGNAL(triggered()), this, SLOT(supprcursus()));
    connect(ui->actionModifierCursus , SIGNAL(triggered()), this, SLOT(modifiercursus()));
    connect(ui->exigerUV , SIGNAL(clicked()), this, SLOT(exigerUV()));
    connect(ui->prefererUV , SIGNAL(clicked()), this, SLOT(prefererUV()));
    connect(ui->rejeterUV , SIGNAL(clicked()), this, SLOT(rejeterUV()));
    connect(ui->annulerUV ,SIGNAL(clicked()), this, SLOT(retirerpref()));
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
