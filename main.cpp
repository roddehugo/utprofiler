#include <QApplication>
#include "writers/LogWriter.h"
#include "dao/Factories.h"
#include "dao/Connexion.h"

int main(int argc, char *argv[])
{

    LogWriter::write("Main.cpp","Lancement de l'application");

    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    //Connexion::getInstance()->setConnexion("/Users/hugo/Dropbox/LO21/Projet/database.sql");

    Factory* fac = AbstractDAOFactory::getFactory(AbstractDAOFactory::DAO_FACTORY);
    UVDAO* uvdao = fac->getUVDAO();



    //return a.exec();
    return 0;
}
