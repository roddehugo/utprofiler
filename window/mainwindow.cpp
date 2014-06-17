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

    /* ONGLET DOSSIER */

    ui->m_tree->setColumnCount(5);
    QTreeWidgetItem* headerItem = new QTreeWidgetItem();
    headerItem->setText(0,QString("Nom"));
    headerItem->setText(1,QString("Titre"));
    headerItem->setText(2,QString("Crédits"));
    headerItem->setText(3,QString("Catégories"));
    headerItem->setText(4,QString("Résultat"));
    ui->m_tree->setHeaderItem(headerItem);
    ui->m_tree->header()->resizeSection(0, 150);
    ui->m_tree->header()->resizeSection(1, 300);
    ui->m_tree->header()->resizeSection(2, 70);
    ui->m_tree->header()->resizeSection(3, 70);
    ui->m_tree->header()->resizeSection(4, 40);
    ui->m_tree->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->m_tree->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->m_tree->setSelectionMode(QAbstractItemView::SingleSelection);

    listDossiers = fac->getDossierDAO()->findByEtudiant(currentEtudiant->ID());
    if(listDossiers.count()==0){
        Dossier* fold = new Dossier("Défaut de "+currentEtudiant->getLogin(),true,currentEtudiant);
        fac->getDossierDAO()->create(fold);
        listDossiers << fold->getTitre();
        ui->dossierCombo->addItem(fold->getTitre());
    }else{
        ui->dossierCombo->addItems(listDossiers);
    }

    currentDossier = fac->getDossierDAO()->findByStr(ui->dossierCombo->currentText());
    fac->getDossierDAO()->setCurrent(currentDossier);

    QList <Dossier *> myDossiers = fac->getDossierDAO()->findAllByEtudiant(currentEtudiant->ID());

    QMap<QString, Cursus*> cursusToCompute;

    for (QList<Dossier *>::const_iterator d = myDossiers.begin(); d != myDossiers.end(); ++d) {

        QTreeWidgetItem *folderWidget = new QTreeWidgetItem(ui->m_tree,QStringList( (*d)->getTitre() ));

        QList<Semestre *> mySemestres = fac->getInscriptionDAO()->findSemestresByDossier( (*d)->ID() );
        for(QList<Semestre *>::const_iterator s = mySemestres.begin(); s != mySemestres.end(); ++s){

            QStringList columns;
            columns << (*s)->getTitre()
                    << (*s)->getComputedCode()
                    << QString::number( fac->getSemestreDAO()->calculEcts( (*s)->ID() ) );
            if((*s)->getCursus()){
                columns << (*s)->getCursus()->getFull();

                if((*d)->isCurrent()){
                    cursusToCompute[(*s)->getCursus()->getCode()] = (*s)->getCursus();
                }

            }

            QTreeWidgetItem *semWidget = new QTreeWidgetItem(folderWidget, columns );

            QList<UV *> myUVs = fac->getInscriptionDAO()->findUvsBySemestre( (*s)->ID() );
            for(QList<UV *>::const_iterator u = myUVs.begin(); u != myUVs.end(); ++u){

                QStringList columns;
                columns << (*u)->getCode()
                        << (*u)->getTitre()
                        << (*u)->getCreditsString()
                        << (*u)->getCursusString()
                        << fac->getInscriptionDAO()->getResultat((*d)->ID(),(*s)->ID(),(*u)->ID());

                QTreeWidgetItem *uvWidget = new QTreeWidgetItem(semWidget, columns);

            }
        }

    }

    /* ONGLET CURSUS */


    //SELECT code, categories.titre, SUM(cud.ects) as somme FROM cursus
    //LEFT JOIN uvs_cursus ON cursus.id = uvs_cursus.idcursus
    //LEFT JOIN inscriptions ON inscriptions.uv = uvs_cursus.iduv
    //LEFT JOIN categorie_uv_decorator cud ON cud.iduv = uvs_cursus.iduv
    //LEFT JOIN categories ON categories.id = cud.idcategorie
    //WHERE inscriptions.resultat IN ('A','B','C','D','E')
    //GROUP BY categories.titre, code;


//    for(QMap<QString, Cursus*>::const_iterator i = cursusToCompute.constBegin(); cursusToCompute.constEnd(); ++i){
//        ui->m_gridcursus->addItem()      ;
//    }






    /* SIGNAUX */

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
