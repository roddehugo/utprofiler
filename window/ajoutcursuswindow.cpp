#include "ajoutcursuswindow.h"
#include "ui_ajoutcursuswindow.h"

ajoutcursuswindow::ajoutcursuswindow(Factory* factory,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajoutcursuswindow),
    fac(factory)
{
    ui->setupUi(this);
    connect(ui->buttonBox , SIGNAL(accepted()), this, SLOT(saveCursus()));

}

ajoutcursuswindow::~ajoutcursuswindow()
{
    delete ui;
}

void ajoutcursuswindow::saveCursus()
{
    //Cursus* cursus=new c
}
