#include "ajoutcursuswindow.h"
#include "ui_ajoutcursuswindow.h"

ajoutcursuswindow::ajoutcursuswindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajoutcursuswindow)
{
    ui->setupUi(this);
}

ajoutcursuswindow::~ajoutcursuswindow()
{
    delete ui;
}
