#include "ajoutfilierewindow.h"
#include "ui_ajoutfilierewindow.h"

ajoutfilierewindow::ajoutfilierewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajoutfilierewindow)
{
    ui->setupUi(this);
}

ajoutfilierewindow::~ajoutfilierewindow()
{
    delete ui;
}
