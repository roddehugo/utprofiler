#define q2s(string) string.toStdString()

#include <QApplication>
#include <QDebug>
#include "writers/LogWriter.h"
#include "dao/Factories.h"
#include "dao/Connexion.h"
#include "window/loginwindow.h"

void testUVDAO(UVDAO* dao){
    QMap<QString,int> ects;
    ects.insert("CS",4);
    ects.insert("TM",3);

    QList<Cursus*> cursus;
    cursus << NULL;

    UV* uv = new UV(999,"TT","Test",1,1,1,ects,cursus);


}


void runTests(Factory* fac){

    testUVDAO(fac->getUVDAO());


}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    LogWriter::writeln("Main.cpp","Lancement de l'application");

    Connexion::getInstance()->setConnexion("/Users/fsamuel/Dropbox/LO21/Projet/utprofiler.db");
    Factory* fac = AbstractDAOFactory::getFactory(AbstractDAOFactory::DAO_FACTORY);


    runTests(fac);


    LoginWindow w(fac);

    w.show();

    return a.exec();
}
