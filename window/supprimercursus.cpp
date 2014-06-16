#include "supprimercursus.h"
#include "ui_supprimercursus.h"
#include <QDebug>

supprimerCursus::supprimerCursus(Factory* factory,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supprimerCursus),
    fac(factory)
{

    ui->setupUi(this);

    connect(ui->buttonBox,SIGNAL(accepted()),this, SLOT(delCursus()));

    ui->listWidget->addItems(fac->getCursusDAO()->getStringList("code"));

}
void supprimerCursus::delCursus(){
    if (ui->listWidget->currentItem()!=NULL){
    Cursus* cursus = fac->getCursusDAO()->findByCode(ui->listWidget->currentItem()->text());
    if(fac->getCursusDAO()->remove(cursus)){
        qDebug()<<"Suppression effectuée";
    }
    }
}

supprimerCursus::~supprimerCursus()
{
    delete ui;
}
