#include "Semestre.h"

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
    if(str=="A")
        return Automne;
    else if(str=="P")
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




