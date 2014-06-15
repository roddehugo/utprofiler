#include "ajoutdossier.h"
#include "ui_ajoutdossier.h"

ajoutDossier::ajoutDossier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajoutDossier)
{
    ui->setupUi(this);
}

ajoutDossier::~ajoutDossier()
{
    delete ui;
}
