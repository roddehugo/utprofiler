#include "ajouteruvwindow.h"
#include "ui_ajouteruvwindow.h"
#include "mainwindow.h"
#include <QDebug>
#include <QListView>
#include <QListWidget>
#include <QTableView>
#include <QStandardItemModel>


ajouterUVwindow::ajouterUVwindow(Factory* factory,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajouterUVwindow),
    fac(factory)
{

    CategorieDAO * cat= fac->getCategorieDAO();
    CursusDAO* cursus=fac->getCursusDAO();
    ui->setupUi(this);
    QObject::connect(ui->buttonBox , SIGNAL(accepted()), this, SLOT(saveUV()));
    QObject::connect(ui->ajoutcursus , SIGNAL(clicked()), this, SLOT(addcursus()));
    QObject::connect(ui->retirecursus , SIGNAL(clicked()), this, SLOT(removecursus()));
    QObject::connect(ui->ajoutcredit , SIGNAL(clicked()), this, SLOT(addcredit()));
    QObject::connect(ui->retirecredit , SIGNAL(clicked()), this, SLOT(removecredit()));
    ui->categoriecol->addItems(cat->getStringList("titre"));
    ui->cursuscolonne->addItems(cursus->getStringList("code"));

}


void ajouterUVwindow::ajoutCategorie(QListWidget *listCat,  QListWidget* listeCreditAjoute, QListWidget *listeCreditCol, QString  valcredit){
    if (listCat->currentItem() != NULL) {
        listeCreditAjoute->addItem(listCat->currentItem()->text());
        delete listCat->currentItem();
        listeCreditCol->addItem(valcredit);
    }
}
void ajouterUVwindow::ajoutCursus(QListWidget *listCursus,  QListWidget* listeCursusAjoute){
    if (listCursus->currentItem() != NULL) {
        listeCursusAjoute->addItem(listCursus->currentItem()->text());

        delete listCursus->currentItem();
    }
}

void ajouterUVwindow::retraitCategorie(QListWidget *listCat, QListWidget *listeCategorieCol, QListWidget *listeCreditCol)
{
    if (listeCategorieCol->currentItem()!=NULL){
        int n=listeCategorieCol->currentRow();
        listCat->addItem(listeCategorieCol->currentItem()->text());
        delete listeCategorieCol->currentItem();
        delete listeCreditCol->item(n);
    }
}

void ajouterUVwindow::retraitCursus(QListWidget *listCursus, QListWidget *listeCursusAjoute)
{
    if (listeCursusAjoute->currentItem()!=NULL){
        listCursus->addItem(listeCursusAjoute->currentItem()->text());
        delete listeCursusAjoute->currentItem();
    }
}



void ajouterUVwindow::addcursus(){
    QListWidget* c1=ui->cursuscolonne;
    QListWidget* c2=ui->cursusajoute;

    ajoutCursus( c1 , c2);


}
void ajouterUVwindow::addcredit(){
    QListWidget* c1=ui->categoriecol;
    QListWidget* c2=ui->creditajoute;
    QListWidget* c3=ui->creditcol;
    QString v=QString::number(ui->spinBox->value());

    ajoutCategorie( c1 , c2 , c3 , v);


}


void ajouterUVwindow::saveUV(){
    const QString c =  ui->codeuv->text();
    const QString t = ui->titreuv->text();
    const bool a = ui->isautomne->isChecked();
    const bool p = ui->isprintemps->isChecked();
    const bool d = ui->isdemiuv->isChecked();
    QMap <QString,int>mapUV;
    QList <Cursus*> listCursus;
    for (int boucle=0;boucle<ui->creditajoute->count();++boucle)
    {
        QString texte=ui->creditajoute->item(boucle)->text();
        int cred=(ui->creditcol->item(boucle)->text()).toInt();
        mapUV[texte]=cred;
    }
    for (int i=0;i<ui->cursusajoute->count();++i)
    {
        QString texte=ui->cursusajoute->item(i)->text();
        listCursus.append(fac->getCursusDAO()->findByCode(texte));
    }

    UV* uv= new UV(c,t,p,a,d,mapUV,listCursus);
    if(fac->getUVDAO()->create(uv)){
        qDebug()<<"ajout effectue";
    }
}

void ajouterUVwindow::removecredit()
{
    QListWidget* c1=ui->categoriecol;
    QListWidget* c2=ui->creditajoute;
    QListWidget* c3=ui->creditcol;

    retraitCategorie( c1 , c2 , c3);
}

void ajouterUVwindow::removecursus()
{
    QListWidget* c1=ui->cursuscolonne;
    QListWidget* c2=ui->cursusajoute;

    retraitCursus(c1,c2);
}

ajouterUVwindow::~ajouterUVwindow()
{
    delete ui;
}
