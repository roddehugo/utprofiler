#include "Semestre.h"

Semestre::Semestre(const Saison &saison, const unsigned int annee, Dossier *dossier, const QMap<int, Inscription *> &inscriptions):
    saison(saison),
    annee(annee),
    dossier(dossier),
    inscriptions(inscriptions)
{

}

Semestre::Semestre(const Saison &saison, const unsigned int annee, Dossier *dossier):
    saison(saison),
    annee(annee),
    dossier(dossier)
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



