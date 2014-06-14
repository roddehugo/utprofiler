#include "supprimercursus.h"
#include "ui_supprimercursus.h"

supprimerCursus::supprimerCursus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supprimerCursus)
{
    ui->setupUi(this);
}

supprimerCursus::~supprimerCursus()
{
    delete ui;
}
