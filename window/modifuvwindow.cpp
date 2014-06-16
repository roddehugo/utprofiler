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

    QObject::connect(ui->modifuv , SIGNAL(clicked()), this, SLOT(on_modifuv_clicked()));
    QObject::connect(ui->buttonBox , SIGNAL(accepted()), this, SLOT(saveuv()));
    ui->colonneuv->addItems(fac->getUVDAO()->getStringList("code"));
}
void modifUVwindow::saveUV(){
    const QString c =  ui->codeuv->text();
    const QString t = ui->titreuv->text();
    const bool a = ui->isautomne->isChecked();
    const bool p = ui->isprintemps->isChecked();
    const bool d = ui->isdemiuv->isChecked();

}

void modifUVwindow::on_modifuv_clicked(){
    QString code = ui->colonneuv->currentItem()->text();
    UV* uv=fac->getUVDAO()->findByCode(code);
    ui->codeuv->setPlaceholderText(uv->getCode());
    ui->titreuv->setPlaceholderText(uv->getTitre());
    ui->isautomne->setChecked(uv->isAutomne());
    ui->isprintemps->setChecked(uv->isPrintemps());
    ui->isdemiuv->setChecked(uv->isDemiUV());
    //ui->listcategorie->addItems(fac->getCategorieDAO()->getStringList("code"));
    //ui->listecursus->addItems(fac->getCursusDAO()->getStringList("code"));


}

modifUVwindow::~modifUVwindow()
{

    delete ui;
}
