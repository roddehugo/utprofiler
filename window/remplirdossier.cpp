#include "remplirdossier.h"
#include "ui_remplirdossier.h"

remplirDossier::remplirDossier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::remplirDossier)
{
    ui->setupUi(this);
}

remplirDossier::~remplirDossier()
{
    delete ui;
}
