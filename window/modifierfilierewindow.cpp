#include "modifierfilierewindow.h"
#include "ui_modifierfilierewindow.h"

modifierfilierewindow::modifierfilierewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifierfilierewindow)
{
    ui->setupUi(this);
}

modifierfilierewindow::~modifierfilierewindow()
{
    delete ui;
}
