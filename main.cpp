
#define q2s(string) string.toStdString()

#include <QApplication>
#include "writers/LogWriter.h"
#include "dao/Factories.h"
#include "dao/Connexion.h"

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


    //return a.exec();
    return 0;
}
