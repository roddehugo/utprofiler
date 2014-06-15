#include "ajoutdossier.h"
#include "ui_ajoutdossier.h"

ajoutDossier::ajoutDossier(Factory* factory,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajoutDossier),
    fac(factory)
{
    ui->setupUi(this);
}

ajoutDossier::~ajoutDossier()
{
    delete ui;
}
