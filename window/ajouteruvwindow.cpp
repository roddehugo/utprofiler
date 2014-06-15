#include "ajouteruvwindow.h"
#include "ui_ajouteruvwindow.h"
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
    UVDAO* uvdao = fac->getUVDAO();
    CategorieDAO * cat= fac->getCategorieDAO();
    CursusDAO* cursus=fac->getCursusDAO();
    ui->setupUi(this);
    QObject::connect(ui->buttonBox , SIGNAL(accepted()), this, SLOT(saveUV()));
    QObject::connect(ui->ajoutcursus , SIGNAL(clicked()), this, SLOT(addcursus()));
    QObject::connect(ui->retirecursus , SIGNAL(clicked()), this, SLOT(removecursus()));
    QObject::connect(ui->ajoutcredit , SIGNAL(clicked()), this, SLOT(addcredit()));
    QObject::connect(ui->retirecredit , SIGNAL(clicked()), this, SLOT(removecredit()));
    QObject::connect(ui->spinBox , SIGNAL(editingFinished()), this, SLOT(valcredit()));

    ui->categoriecol->addItems(cat->getStringList("titre"));
    ui->cursuscolonne->addItems(cursus->getStringList("code"));
}


//void ajouterUVwindow::ajoutItem(QListWidget *l1,  QListWidget *l2) {
//    if (l1->currentItem() != NULL) {
//        l2->addItem(l1->currentItem());
//        qDebug()<<l1->currentItem()->text();
//        delete l1->currentItem();
//    }
//}

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

    ajoutCursus( c1 , c2 );


}
void ajouterUVwindow::addcredit(){
    QListWidget* c1=ui->categoriecol;
    QListWidget* c2=ui->creditajoute;
    QListWidget* c3=ui->creditcol;
    QString v=QString::number(ui->spinBox->value());

    ajoutCategorie( c1 , c2 , c3 , v);


}
void ajouterUVwindow::valcredit(){
    int valcredit=ui->spinBox->value();


}

void ajouterUVwindow::saveUV(){
    const QString c =  ui->codeuv->text();
    const QString t = ui->titreuv->text();
    const bool a = ui->isautomne->isChecked();
    const bool p = ui->isprintemps->isChecked();
    const bool d = ui->isdemiuv->isChecked();
    for (int boucle=0;boucle<ui->creditajoute->count();++boucle)
    {
        QString texte=ui->creditajoute->item(boucle)->text();

    }
    //ui->creditajoute->findItems()
    //    Creditable * uv = new UV(params);
    //    uv=new CS(params,uv);
    //    uv=new TM(params,uv);

    //    Creditable* uv2 = new CS(params,new TM(params, new UV(params)));

    //    Creditable* uv = new UV(1,"TC","Tronc Commun",120,6,1,NULL,NULL);
    //    if(uvdao->create(new UV())){
    //        setUpMainWindow();
    //    }else{
    //        QMessageBox msgBox;
    //        msgBox.setText("Impossible d'ajouter l'uv.");
    //        msgBox.exec();
    //    }
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
