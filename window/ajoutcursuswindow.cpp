#include "ajoutcursuswindow.h"
#include "ui_ajoutcursuswindow.h"
#include <QDebug>

ajoutcursuswindow::ajoutcursuswindow(Factory* factory,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajoutcursuswindow),
    fac(factory)
{
    ui->setupUi(this);
    connect(ui->buttonBox , SIGNAL(accepted()), this, SLOT(saveCursus()));
    connect(ui->ajoutcredit , SIGNAL(clicked()), this, SLOT(ajoutCat()));
    connect(ui->retirecredit , SIGNAL(clicked()), this, SLOT(retireCat()));

    ui->listcategorie->addItems(fac->getCategorieDAO()->getStringList("titre"));
    ui->listcursus->addItems(fac->getCursusDAO()->getStringList("code"));
}

ajoutcursuswindow::~ajoutcursuswindow()
{
    delete ui;
}

void ajoutcursuswindow::saveCursus()
{
    QMap <QString,int>mapUV;
    for (int i=0;i<ui->listcreditajoute->count();++i)
    {
        QString texte=ui->listcreditajoute->item(i)->text();
        int cred=(ui->listcreditcol->item(i)->text()).toInt();
        mapUV[texte]=cred;
    }
    if (ui->listcursus->currentItem()!=NULL){
    Cursus* cursus=new Cursus(
                ui->codecursus->text(),
                ui->nomcursus->text(),
                ui->ects->value(),
                ui->maxsemestre->value(),
                ui->previsionsemestre->value(),
                fac->getCursusDAO()->findByCode(ui->listcursus->currentItem()->text()),
                mapUV);
    fac->getCursusDAO()->create(cursus);
    }
    else{
        Cursus* cursus=new Cursus(
                    ui->codecursus->text(),
                    ui->nomcursus->text(),
                    ui->ects->value(),
                    ui->maxsemestre->value(),
                    ui->previsionsemestre->value(),
                    NULL,
                    mapUV);
        fac->getCursusDAO()->create(cursus);
    }

}

void ajoutcursuswindow::ajoutCat()
{
    if(ui->listcategorie->currentItem()!=NULL){
        ui->listcreditajoute->addItem(ui->listcategorie->currentItem()->text());
        ui->listcreditcol->addItem(QString::number(ui->spinBox->value()));
        delete ui->listcategorie->currentItem();
    }
}

void ajoutcursuswindow::retireCat()
{
    if(ui->listcreditajoute->currentItem()!=NULL){
        ui->listcategorie->addItem(ui->listcreditajoute->currentItem()->text());
        delete ui->listcreditcol->item(ui->listcreditajoute->currentRow());
        delete ui->listcreditajoute->currentItem();

    }
}
