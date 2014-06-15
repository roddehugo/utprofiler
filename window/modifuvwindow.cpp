#include "modifuvwindow.h"
#include "ui_modifuvwindow.h"

modifUVwindow::modifUVwindow(Factory* factory,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifUVwindow),
    fac(factory)
{
    ui->setupUi(this);
}

modifUVwindow::~modifUVwindow()
{
    delete ui;
}
