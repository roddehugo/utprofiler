#include "supprimeruvwindow.h"
#include "ui_supprimeruvwindow.h"

supprimerUVwindow::supprimerUVwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supprimerUVwindow)
{
    ui->setupUi(this);
}

supprimerUVwindow::~supprimerUVwindow()
{
    delete ui;
}
