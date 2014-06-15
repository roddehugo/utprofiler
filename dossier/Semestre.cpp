#include "Semestre.h"

Semestre::Semestre(const unsigned int id, const Saison &saison, unsigned int annee, bool etranger, Dossier *dossier, const QMap<int, Inscription *> &inscriptions):
    id(id),
    saison(saison),
    annee(annee),
    etranger(etranger),
    dossier(dossier),
    inscriptions(inscriptions)
{

}

Semestre::Semestre(const unsigned int id, const Saison &saison, unsigned int annee, bool etranger, Dossier *dossier):
    id(id),
    saison(saison),
    annee(annee),
    etranger(etranger),
    dossier(dossier)
{

}

Semestre::Semestre(const Saison &saison, unsigned int annee, bool etranger, Dossier *dossier):
    saison(saison),
    annee(annee),
    etranger(etranger),
    dossier(dossier)
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
Dossier *Semestre::getDossier() const
{
    return dossier;
}

void Semestre::setDossier(Dossier *value)
{
    dossier = value;
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
            throw UTProfilerException("Impossible de convertir Saison en QString" + saison);
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



