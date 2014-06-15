#include "supprimeruvwindow.h"
#include "ui_supprimeruvwindow.h"

supprimerUVwindow::supprimerUVwindow(Factory* factory,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supprimerUVwindow),
    fac(factory)
{
    ui->setupUi(this);
}

supprimerUVwindow::~supprimerUVwindow()
{
    delete ui;
}
