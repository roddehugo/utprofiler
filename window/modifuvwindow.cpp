#include "modifuvwindow.h"
#include "ui_modifuvwindow.h"
#include <QDebug>
#include <QListWidget>

modifUVwindow::modifUVwindow(Factory* factory,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifUVwindow),
    fac(factory)
{
    UVDAO* uvdao=fac->getUVDAO();
     ui->setupUi(this);

    QObject::connect(ui->modifuv , SIGNAL(clicked()), this, SLOT(on_modifuv_clicked()));

    QObject::connect(ui->buttonBox , SIGNAL(accepted()), this, SLOT(saveuv()));

}
void modifUVwindow::saveUV(){
    const QString c =  ui->codeuv->text();
    const QString t = ui->titreuv->text();
    const bool a = ui->isautomne->isChecked();
    const bool p = ui->isprintemps->isChecked();
    const bool d = ui->isdemiuv->isChecked();

}

void modifUVwindow::on_modifuv_clicked(){


    ui->codeuv->setPlaceholderText("Nom");
    ui->titreuv->setPlaceholderText("titre");
    ui->isautomne->setChecked(true);
    ui->isprintemps->setChecked(true);
    ui->isdemiuv->setChecked(true);

}

modifUVwindow::~modifUVwindow()
{

    delete ui;
}
