#include "supprimercursus.h"
#include "ui_supprimercursus.h"

supprimerCursus::supprimerCursus(Factory* factory,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supprimerCursus),
    fac(factory)
{
    ui->setupUi(this);
}

supprimerCursus::~supprimerCursus()
{
    delete ui;
}
