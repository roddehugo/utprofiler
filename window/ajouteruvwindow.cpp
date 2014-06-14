#include "ajouteruvwindow.h"
#include "ui_ajouteruvwindow.h"

ajouterUVwindow::ajouterUVwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajouterUVwindow)
{
    ui->setupUi(this);
}

ajouterUVwindow::~ajouterUVwindow()
{
    delete ui;
}
