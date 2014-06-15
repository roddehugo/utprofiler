#define q2s(string) string.toStdString()

#include <QApplication>
#include <QDebug>
#include "writers/LogWriter.h"
#include "decorator/Creditable.h"
#include "decorator/CS.h"
#include "decorator/TM.h"
#include "decorator/TSH.h"
#include "decorator/SP.h"
#include "dao/Factories.h"
#include "dao/Connexion.h"
#include "window/loginwindow.h"


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    LogWriter::writeln("Main.cpp","Lancement de l'application");

    Connexion::getInstance()->setConnexion("/Users/fsamuel/Dropbox/LO21/Projet/save.db");
    Factory* fac = AbstractDAOFactory::getFactory(AbstractDAOFactory::DAO_FACTORY);

    Creditable* tc = new Cursus(1,"TC","Tronc Commun",120,6,1,NULL,NULL);
    tc = new TM(1,"TM",30,tc);
    qDebug()<<tc->getTitre();

    LoginWindow w(fac);

    w.show();

    return a.exec();
}
