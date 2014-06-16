#include "supprimercursus.h"
#include "ui_supprimercursus.h"

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
    UV* uv = fac->getUVDAO()->findByCode(ui->listWidget->currentItem()->text());
    fac->getUVDAO()->remove(uv);
}

supprimerCursus::~supprimerCursus()
{
    delete ui;
}
