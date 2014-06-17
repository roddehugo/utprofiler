#include "ajoutdossier.h"
#include "ui_ajoutdossier.h"

ajoutdossier::ajoutdossier(Factory* fac, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajoutdossier),
    factory(fac)
{
    ui->setupUi(this);
}

ajoutdossier::~ajoutdossier()
{
    delete ui;
}
