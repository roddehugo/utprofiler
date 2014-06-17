#include "supprimeruvwindow.h"
#include "ui_supprimeruvwindow.h"
#include <QString>
#include <QDebug>
supprimerUVwindow::supprimerUVwindow(Factory* factory,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supprimerUVwindow),
    fac(factory)
{
    ui->setupUi(this);
    ui->listall->addItems(fac->getUVDAO()->getStringList("code"));
    QObject::connect(ui->buttonBox , SIGNAL(accepted()), this, SLOT(delUV()));


}
void supprimerUVwindow::delUV(){
    QString nom = ui->listall->currentItem()->text();
      UV* uv= fac->getUVDAO()->findByCode(nom);
      if(fac->getUVDAO()->remove(uv)){
            qDebug()<<"Suppression effectué";
       }
      emit finsuppr();
}

supprimerUVwindow::~supprimerUVwindow()
{
    delete ui;
}
