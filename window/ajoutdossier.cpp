#include "ajoutdossier.h"
#include "ui_ajoutdossier.h"

ajoutDossier::ajoutDossier(Factory* factory,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajoutDossier),
    fac(factory)
{
    ui->setupUi(this);

    ui->anneeCombo->addItems(fac->getSemestreDAO()->getStringListAnnee());
    ui->saisonCombo->addItems(fac->getSemestreDAO()->getStringListSaison());
}

ajoutDossier::~ajoutDossier()
{
    delete ui;
}
