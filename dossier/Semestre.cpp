#include "Semestre.h"

unsigned int computedEcts = 0;


Semestre::Semestre(const unsigned int id, const QString& titre,const Saison &saison, unsigned int annee, bool etranger, Cursus *cursus):
    id(id),
    titre(titre),
    saison(saison),
    annee(annee),
    etranger(etranger),
    cursus(cursus)
{

}

Semestre::Semestre(const QString& titre, const Saison &saison, unsigned int annee, bool etranger, Cursus *cursus):
    titre(titre),
    saison(saison),
    annee(annee),
    etranger(etranger),
    cursus(cursus)
{

}

Semestre::~Semestre()
{

}

Saison Semestre::getSaison() const
{
    return saison;
}

void Semestre::setSaison(const Saison &value)
{
    saison = value;
}
unsigned int Semestre::getAnnee() const
{
    return annee;
}

void Semestre::setAnnee(unsigned int value)
{
    annee = value;
}

QMap<int, Inscription *> Semestre::getInscriptions() const
{
    return inscriptions;
}

void Semestre::setInscriptions(const QMap<int, Inscription *> &value)
{
    inscriptions = value;
}
Cursus *Semestre::getCursus() const
{
    if(cursus)
        return cursus;
}

void Semestre::setCursus(Cursus *value)
{
    cursus = value;
}
bool Semestre::isEtranger() const
{
    return etranger;
}

void Semestre::setEtranger(bool value)
{
    etranger = value;
}

Saison Semestre::str2saison(const QString &str)
{
    if(str=="Automne")
        return Automne;
    else if(str=="Printemps")
        return Printemps;
    else
        UTProfilerException("Impossible de convertir QString en Saison" + str);

}

QString Semestre::saison2str(Saison saison)
{
    switch(saison)
    {
        case Automne:
            return "Automne";
        case Printemps:
            return "Printemps";
        default:
            throw UTProfilerException("Impossible de convertir Saison en QString");
    }
}

unsigned int Semestre::ID() const
{
    return id;
}

void Semestre::setID(unsigned int value)
{
    id = value;
}
QString Semestre::getTitre() const
{
    return titre;
}

void Semestre::setTitre(const QString &value)
{
    titre = value;
}

unsigned int Semestre::getComputedEcts() const
{
    return computedEcts;
}

void Semestre::setComputedEcts(unsigned int value)
{
    computedEcts = value;
}

QString Semestre::getComputedCode() const
{
    QString str = saison2str(saison);
    str.truncate(1);
    return QString( str + QString::number(annee%100));
}


