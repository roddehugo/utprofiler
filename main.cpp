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

    Connexion::getInstance()->setConnexion("/Users/hugo/Dropbox/UVs/LO21/Projet/save.db");
    Factory* fac = AbstractDAOFactory::getFactory(AbstractDAOFactory::DAO_FACTORY);
    UVDAO* uvdao = fac->getUVDAO();
    QMap<int,UV*> uvmap = uvdao->findAll();
    UV* lo21 = uvmap.value(1);

    Creditable* tc = new CS("CS",35,new TM("TM",35,new TSH("TSH",35,lo21 ) ) );
    LogWriter::writeln("Main.cpp",tc->getTitre());
    QHash<QString, int> ectsmap;
    ectsmap = tc->getEcts(ectsmap);
    qDebug() << ectsmap;

    //LogWriter::writeln("Main.cpp",QString::number(tc->getEcts()) );

//    LoginWindow w(fac);

//    w.show();

    return a.exec();
}
