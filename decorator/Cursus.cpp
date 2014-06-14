#include "Cursus.h"

Cursus::Cursus(const QString& code, const QString& titre, const unsigned int ects,
               const unsigned int maxSemestre, bool current,
               Creditable* creditable, Dossier* dossier, Cursus* parent ):
    Creditable(titre,ects),
    code(code),
    maxSemestres(maxSemestre),
    current(current),
    parent(parent),
    dossier(dossier)
{}

Cursus::Cursus(const QString& code, const QString& titre, const unsigned int ects,
               const unsigned int maxSemestre, bool current,
               Creditable* creditable, Dossier* dossier):
    Creditable(titre,ects),
    code(code),
    maxSemestres(maxSemestre),
    current(current),
    dossier(dossier)
{}

Cursus::~Cursus(){}


QString Cursus::getCode() const
{
    return code;
}

void Cursus::setCode(const QString &value)
{
    code = value;
}

QString Cursus::getTitre() const
{
    return titre;
}

void Cursus::setTitre(const QString &value)
{
    titre = value;
}

unsigned int Cursus::getMaxSemestres() const
{
    return maxSemestres;
}

void Cursus::setMaxSemestres(unsigned int value)
{
    maxSemestres = value;
}

bool Cursus::getCurrent() const
{
    return current;
}

void Cursus::setCurrent(bool value)
{
    current = value;
}


Creditable *Cursus::getCreditable() const
{
    return creditable;
}

void Cursus::setCreditable(Creditable *value)
{
    creditable = value;
}

Cursus *Cursus::getParent() const
{
    return parent;
}

void Cursus::setParent(Cursus *value)
{
    parent = value;
}

Dossier *Cursus::getDossier() const
{
    return dossier;
}

void Cursus::setDossier(Dossier *value)
{
    dossier = value;
}


unsigned int Cursus::getEcts() const
{
    return ects;
}

void Cursus::setEcts(unsigned int value)
{
    ects = value;
}
