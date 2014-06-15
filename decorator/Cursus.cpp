#include "Cursus.h"

Cursus::Cursus(unsigned int id, const QString& code, const QString& titre, const unsigned int ects,
               const unsigned int maxSemestre, bool current,
               Dossier* dossier, Cursus* parent ):
    Creditable(id,titre,ects),
    code(code),
    maxSemestres(maxSemestre),
    current(current),
    parent(parent),
    dossier(dossier)
{}

Cursus::Cursus(unsigned int id, const QString& code, const QString& titre, const unsigned int ects,
               const unsigned int maxSemestre, bool current,
               Dossier* dossier):
    Creditable(id,titre,ects),
    code(code),
    maxSemestres(maxSemestre),
    current(current),
    dossier(dossier)
{}
Cursus::Cursus(const QString& code, const QString& titre, const unsigned int ects,
               const unsigned int maxSemestre, bool current,
               Dossier* dossier, Cursus* parent ):
    Creditable(titre,ects),
    code(code),
    maxSemestres(maxSemestre),
    current(current),
    parent(parent),
    dossier(dossier)
{}

Cursus::Cursus(const QString& code, const QString& titre, const unsigned int ects,
               const unsigned int maxSemestre, bool current,
               Dossier* dossier):
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
