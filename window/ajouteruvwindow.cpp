#include "ajouteruvwindow.h"
#include "ui_ajouteruvwindow.h"
#include <QDebug>

ajouterUVwindow::ajouterUVwindow(Factory* factory,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajouterUVwindow),
    fac(factory)
{
    UVDAO* uvdao = fac->getUVDAO();
    CategorieDAO * cat= fac->getCategorieDAO();
    ui->setupUi(this);
    QObject::connect(ui->buttonBox , SIGNAL(accepted()), this, SLOT(saveuv()));


}

void ajouterUVwindow::saveUV(){
    const QString c =  ui->codeuv->text();
    const QString t = ui->titreuv->text();
    const bool a = ui->isautomne->isChecked();
    const bool p = ui->isprintemps->isChecked();
    const bool d = ui->isdemiuv->isChecked();

  //    Creditable * uv = new UV(params);
//    uv=new CS(params,uv);
//    uv=new TM(params,uv);

//    Creditable* uv2 = new CS(params,new TM(params, new UV(params)));

//    Creditable* uv = new UV(1,"TC","Tronc Commun",120,6,1,NULL,NULL);
//    if(uvdao->create(new UV())){
//        setUpMainWindow();
//    }else{
//        QMessageBox msgBox;
//        msgBox.setText("Impossible d'ajouter l'uv.");
//        msgBox.exec();
//    }
}

ajouterUVwindow::~ajouterUVwindow()
{
    delete ui;
}
