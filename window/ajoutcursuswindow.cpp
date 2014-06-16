#include "ajoutcursuswindow.h"
#include "ui_ajoutcursuswindow.h"
#include <QDebug>
#include <QListWidget>

ajoutcursuswindow::ajoutcursuswindow(Factory* factory,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajoutcursuswindow),
    fac(factory)
{
    ui->setupUi(this);
    QObject::connect(ui->buttonBox , SIGNAL(accepted()), this, SLOT(saveCursus()));

}

ajoutcursuswindow::~ajoutcursuswindow()
{
    delete ui;
}

void ajoutcursuswindow::saveCursus()
{
    //Cursus* cursus=new Cursus(ui->codecursus->text(),ui->nomcursus->text(),ui->nbcredit,)
}
