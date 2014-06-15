#include "ajouteruvwindow.h"
#include "ui_ajouteruvwindow.h"

ajouterUVwindow::ajouterUVwindow(Factory* factory,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajouterUVwindow),
    fac(factory)
{
    ui->setupUi(this);
}

ajouterUVwindow::~ajouterUVwindow()
{
    delete ui;
}
