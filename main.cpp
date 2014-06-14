
#define q2s(string) string.toStdString()

#include <QApplication>
#include "writers/LogWriter.h"
#include "dao/Factories.h"
#include "dao/Connexion.h"
#include <QDebug>
#include "decorator/Creditable.h"
#include "decorator/CS.h"
#include "decorator/TM.h"
#include "decorator/TSH.h"
#include "decorator/TC.h"




int main(int argc, char *argv[])
{

    LogWriter::writeln("Main.cpp","Lancement de l'application");

    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    //Connexion::getInstance()->setConnexion("/Users/hugo/Dropbox/UVs/LO21/Projet/database.db");

  //  Factory* fac = AbstractDAOFactory::getFactory(AbstractDAOFactory::DAO_FACTORY);
    //UVDAO* uvdao = fac->getUVDAO();
    //QMap <int, UV*> uvmap =  uvdao->findAll();
    Creditable *c=new TC("GI","info",2,32,2,2,3);
      qDebug()<< (c)<<endl;
      Creditable *u=new UV("GI","info",2,32,2,2,3);
        qDebug()<< (u)<<endl;
//           Creditable *d=new Cursus("GM","mec",2,32,2,2,3);
//           std::cout<<(d)<<endl;


//           d=new CategorieDecorator(*d,15,"Puant");
          CategorieDecorator* d=new CS("titre",6,*c);
           qDebug()<<(d)<<endl;
           d=new TM("titre",6,*c);
            qDebug()<<(d)<<endl;
            CategorieDecorator* v=new TSH("titre",6,*c,Theorique,Perception);
             qDebug()<<(v)<<endl;

    //return a.exec();
    return 0;
}
