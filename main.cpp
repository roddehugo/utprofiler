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

//    LoginWindow w(fac);

//    w.show();

    return a.exec();
}
