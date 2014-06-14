#include "modifuvwindow.h"
#include "ui_modifuvwindow.h"

modifUVwindow::modifUVwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifUVwindow)
{
    ui->setupUi(this);
}

modifUVwindow::~modifUVwindow()
{
    delete ui;
}
