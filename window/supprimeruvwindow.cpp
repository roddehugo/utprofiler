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
    QObject::connect(ui->buttonBox , SIGNAL(accepted()), this, SLOT(delUV()));
    ui->listall->addItems(fac->getUVDAO()->getStringList("code"));

}
void supprimerUVwindow::delUV(){
    QString nom = ui->listall->currentItem()->text();
      UV* uv= fac->getUVDAO()->findByCode(nom);
      qDebug()<<uv->getTitre();
      if(fac->getUVDAO()->remove(uv)){
            qDebug()<<"Suppression effectué";

            qDebug()<<fac->getUVDAO()->findByCode(nom)->getTitre();
       }
}

supprimerUVwindow::~supprimerUVwindow()
{
    delete ui;
}
