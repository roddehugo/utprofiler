#define q2s(string) string.toStdString()

#include <QApplication>
#include <QDebug>
#include "writers/LogWriter.h"
#include "dao/Factories.h"
#include "dao/Connexion.h"
#include "window/loginwindow.h"

void runTests(Factory* fac){

    fac->getCategorieDAO()->create("CS");
    fac->getCategorieDAO()->create("TM");
    fac->getCategorieDAO()->create("TSH");
    fac->getCategorieDAO()->create("SP");
    fac->getCategorieDAO()->create("Libre");


    Etudiant* me = new Etudiant("roddehug","Hugo","Rodde");
    fac->getEtudiantDAO()->create(me);

    Dossier* monDossier = new Dossier("Mon Dossier",0,me);
    fac->getDossierDAO()->create(monDossier);

    QMap<QString,int> tcEcts;
    tcEcts.insert("CS",48);
    tcEcts.insert("TM",24);
    tcEcts.insert("TSH",24);
    tcEcts.insert("SP",6);

    QMap<QString,int> giEcts;
    giEcts.insert("CS",30);
    giEcts.insert("TM",30);
    giEcts.insert("TSH",28);
    giEcts.insert("SP",60);
    giEcts.insert("Libre",24);

    Cursus* tc = new Cursus("TC","Tronc Commun",120,6,4,NULL,tcEcts);
    Cursus* gi = new Cursus("GI","Branche Génie Informatique",180,8,6,NULL,giEcts);

    fac->getCursusDAO()->create(tc);
    fac->getCursusDAO()->create(gi);

    Semestre* tc01 = new Semestre(Automne,2011,0,monDossier);
    Semestre* tc02 = new Semestre(Printemps,2012,0,monDossier);
    Semestre* tc03 = new Semestre(Automne,2012,1,monDossier);
    Semestre* tc04 = new Semestre(Printemps,2013,0,monDossier);
    Semestre* gi01 = new Semestre(Automne,2013,0,monDossier);
    Semestre* gi02 = new Semestre(Printemps,2014,0,monDossier);

    fac->getSemestreDAO()->create(tc01);
    fac->getSemestreDAO()->create(tc02);
    fac->getSemestreDAO()->create(tc03);
    fac->getSemestreDAO()->create(tc04);
    fac->getSemestreDAO()->create(gi01);
    fac->getSemestreDAO()->create(gi02);

    QMap<QString,int> nf93ects;
    nf93ects.insert("CS",4);
    nf93ects.insert("TM",3);

    QMap<QString,int> lo21ects;
    lo21ects.insert("CS",2);
    lo21ects.insert("SP",5);

    QList<Cursus *> lo21list;
    lo21list << gi;

    QList<Cursus *> nf93list;
    nf93list << tc;

    UV* nf93 = new UV("NF93","Logique",1,0,0,nf93ects,nf93list);
    UV* lo21 = new UV("LO21","Programmation",1,1,0,lo21ects,lo21list);

    fac->getUVDAO()->create(nf93);
    fac->getUVDAO()->create(lo21);

    Inscription *i1 = new Inscription(nf93,tc03,B);
    Inscription *i2 = new Inscription(lo21,gi02,EC);

    fac->getInscriptionDAO()->create(i1);
    fac->getInscriptionDAO()->create(i2);

    /*Suppression des objets*/

    fac->getInscriptionDAO()->remove(i1);
    fac->getInscriptionDAO()->remove(i2);

    fac->getUVDAO()->remove(nf93);
    fac->getUVDAO()->remove(lo21);

    fac->getSemestreDAO()->remove(tc01);
    fac->getSemestreDAO()->remove(tc02);
    fac->getSemestreDAO()->remove(tc03);
    fac->getSemestreDAO()->remove(tc04);
    fac->getSemestreDAO()->remove(gi01);
    fac->getSemestreDAO()->remove(gi02);

    fac->getCursusDAO()->remove(tc);
    fac->getCursusDAO()->remove(gi);

    fac->getCategorieDAO()->remove("CS");
    fac->getCategorieDAO()->remove("TM");
    fac->getCategorieDAO()->remove("TSH");
    fac->getCategorieDAO()->remove("SP");
    fac->getCategorieDAO()->remove("Libre");

    fac->getEtudiantDAO()->remove(me);

    fac->getDossierDAO()->remove(monDossier);

}

int main(int argc, char *argv[])
{
    /* Application

    QApplication a(argc, argv);

    LogWriter::writeln("Main.cpp","Lancement de l'application"); 

    Connexion::getInstance()->setConnexion("/Users/fsamuel/Dropbox/LO21/Projet/utprofiler.db");
    Factory* fac = AbstractDAOFactory::getFactory(AbstractDAOFactory::DAO_FACTORY);


    LoginWindow w(fac);

    w.show();

    return a.exec();

    //*///

    //* Tests

    LogWriter::writeln("Main.cpp","Lancement de l'application");

    Connexion::getInstance()->setConnexion("/Users/hugo/Dropbox/UVs/LO21/Projet/test.db");
    Factory* fac = AbstractDAOFactory::getFactory(AbstractDAOFactory::DAO_FACTORY);

    runTests(fac);

    return 0;

    //*///
}
