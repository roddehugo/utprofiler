#include "modifiercursuswindow.h"
#include "ui_modifiercursuswindow.h"

modifiercursuswindow::modifiercursuswindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifiercursuswindow)
{
    ui->setupUi(this);
}

modifiercursuswindow::~modifiercursuswindow()
{
    delete ui;
}
