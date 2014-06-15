#include "ajoutcursuswindow.h"
#include "ui_ajoutcursuswindow.h"

ajoutcursuswindow::ajoutcursuswindow(Factory* factory,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajoutcursuswindow),
    fac(factory)
{
    ui->setupUi(this);

}

ajoutcursuswindow::~ajoutcursuswindow()
{
    delete ui;
}
