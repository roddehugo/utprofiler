#include "remplirdossier.h"
#include "ui_remplirdossier.h"

remplirDossier::remplirDossier(Factory* factory,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::remplirDossier),
    fac(factory)
{
    ui->setupUi(this);
}

remplirDossier::~remplirDossier()
{
    delete ui;
}
