#include "modifuvwindow.h"
#include "ui_modifuvwindow.h"
#include <QApplication>
#include <QDebug>
#include <QListWidget>

modifUVwindow::modifUVwindow(Factory* factory,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifUVwindow),
    fac(factory)
{
     ui->setupUi(this);

     ui->colonneuv->addItems(fac->getUVDAO()->getStringList("code"));
     ui->listcategorie->addItems(fac->getCategorieDAO()->getStringList("titre"));
     ui->listecursus->addItems(fac->getCursusDAO()->getStringList("code"));

    QObject::connect(ui->modifuv , SIGNAL(clicked()), this, SLOT(on_modifuv_clicked()));
    QObject::connect(ui->buttonBox , SIGNAL(accepted()), this, SLOT(saveuv()));

    QObject::connect(ui->butajoutcursus , SIGNAL(clicked()), this, SLOT(addcursus()));
    QObject::connect(ui->butretirecursus , SIGNAL(clicked()), this, SLOT(removecursus()));
    QObject::connect(ui->butajoutcredit , SIGNAL(clicked()), this, SLOT(addcredit()));
    QObject::connect(ui->butretirecredit , SIGNAL(clicked()), this, SLOT(removecredit()));
}
void modifUVwindow::saveuv(){
    const QString c =  ui->codeuv->text();
    const QString t = ui->titreuv->text();
    const bool a = ui->isautomne->isChecked();
    const bool p = ui->isprintemps->isChecked();
    const bool d = ui->isdemiuv->isChecked();
    QMap <QString,int>mapUV;
    QList <Cursus*> listCursus;
    for (int boucle=0;boucle<ui->catajoute->count();++boucle)
    {
        QString texte=ui->catajoute->item(boucle)->text();
        int cred=(ui->creditajoute->item(boucle)->text()).toInt();
        mapUV[texte]=cred;
    }
    for (int i=0;i<ui->cursusajoute->count();++i)
    {
        QString texte=ui->cursusajoute->item(i)->text();
        listCursus.append(fac->getCursusDAO()->findByCode(texte));
    }

    UV* uv= new UV(c,t,p,a,d,mapUV,listCursus);
    if(fac->getUVDAO()->create(uv)){
        qDebug()<<"modification effectue";
    }
}

void modifUVwindow::on_modifuv_clicked(){
    QString code = ui->colonneuv->currentItem()->text();
    UV* uv=fac->getUVDAO()->findByCode(code);
    ui->codeuv->setPlaceholderText(uv->getCode());
    ui->titreuv->setPlaceholderText(uv->getTitre());
    ui->isautomne->setChecked(uv->isAutomne());
    ui->isprintemps->setChecked(uv->isPrintemps());
    ui->isdemiuv->setChecked(uv->isDemiUV());

}

void modifUVwindow::addcredit(){
    if (ui->listcategorie->currentItem() != NULL) {
        ui->catajoute->addItem(ui->listcategorie->currentItem()->text());
        delete ui->listcategorie->currentItem();
        ui->creditajoute->addItem(QString::number(ui->spinBox->value()));
    }
}
void modifUVwindow::addcursus(){
    if (ui->listecursus->currentItem() != NULL) {
        ui->cursusajoute->addItem(ui->listecursus->currentItem()->text());

        delete ui->listecursus->currentItem();
    }
}

void modifUVwindow::removecredit()
{
    if (ui->catajoute->currentItem()!=NULL){
        int n=ui->catajoute->currentRow();
        ui->listcategorie->addItem(ui->catajoute->currentItem()->text());
        delete ui->catajoute->currentItem();
        delete ui->creditajoute->item(n);
    }
}

void modifUVwindow::removecursus()
{
    if (ui->cursusajoute->currentItem()!=NULL){
        ui->listecursus->addItem(ui->cursusajoute->currentItem()->text());
        delete ui->cursusajoute->currentItem();
    }
}
modifUVwindow::~modifUVwindow()
{

    delete ui;
}
