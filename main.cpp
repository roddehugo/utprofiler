#define q2s(string) string.toStdString()

#include <QApplication>
#include <QDebug>
#include "writers/LogWriter.h"
#include "dao/Factories.h"
#include "dao/Connexion.h"
#include "decorator/Creditable.h"
#include "decorator/CS.h"
#include "decorator/TM.h"
#include "decorator/TSH.h"
#include "decorator/TC.h"
#include "window/loginwindow.h"
#include "decorator/Branche.h"
#include "decorator/Filiere.h"
#include "decorator/HuTech.h"
#include "decorator/SP.h"
#include "decorator/Mineur.h"


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    LogWriter::writeln("Main.cpp","Lancement de l'application");


//    Creditable *c=new TC("GI","info",2,32,2,2,3);
//    qDebug()<< (c)<<endl;
//    Creditable *u=new UV("GI","info",2,32,2,2,3);
//    qDebug()<< (u)<<endl;
//    //           Creditable *d=new Cursus("GM","mec",2,32,2,2,3);
//    //           std::cout<<(d)<<endl;


//    //           d=new CategorieDecorator(*d,15,"Puant");
//    CategorieDecorator* d=new CS("titre",6,*c);
//    qDebug()<<(d)<<endl;
//    d=new TM("titre",6,*c);
//    qDebug()<<(d)<<endl;
//    CategorieDecorator* v=new TSH("titre",6,*c,Theorique,Perception);
//    qDebug()<<(v)<<endl;

    Connexion::getInstance()->setConnexion("/Users/fsamuel/Dropbox/LO21/Projet/save.db");
    Factory* fac = AbstractDAOFactory::getFactory(AbstractDAOFactory::DAO_FACTORY);


    LoginWindow w(fac);

    w.show();

    return a.exec();
}
