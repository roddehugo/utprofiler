#include "modifiercursuswindow.h"
#include "ui_modifiercursuswindow.h"

modifiercursuswindow::modifiercursuswindow(Factory* factory,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifiercursuswindow),
    fac(factory)
{
    ui->setupUi(this);
}

modifiercursuswindow::~modifiercursuswindow()
{
    delete ui;
}
