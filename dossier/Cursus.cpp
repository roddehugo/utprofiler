#include "Cursus.h"


Cursus::Cursus(const unsigned int id, const QString &code, const QString &titre, const unsigned int ects,
               const unsigned int maxSemestre, bool current,
               QMap<QString, int> credits, Dossier *dossier, Cursus *parent):
id(id),
titre(titre),
code(code),
ects(ects),
maxSemestres(maxSemestre),
current(current),
dossier(dossier),
credits(credits){

}

Cursus::Cursus(const QString &code, const QString &titre, const unsigned int ects,
               const unsigned int maxSemestre, bool current,
               QMap<QString, int> credits, Dossier *dossier, Cursus *parent):
titre(titre),
code(code),
ects(ects),
maxSemestres(maxSemestre),
current(current),
dossier(dossier),
credits(credits){

}

QString Cursus::getCode() const
{
    return code;
}

QMap<QString, int> Cursus::getCredits() const
{
    return credits;
}

void Cursus::setCredits(const QMap<QString, int> &value)
{
    credits = value;
}

unsigned int Cursus::getMaxSemestres() const
{
    return maxSemestres;
}

void Cursus::setMaxSemestres(unsigned int value)
{
    maxSemestres = value;
}

bool Cursus::isCurrent() const
{
    return current;
}

void Cursus::setCurrent(bool value)
{
    current = value;
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

QString Cursus::getTitre() const
{
    return titre;
}

void Cursus::setTitre(const QString& value){

}

unsigned int Cursus::ID() const
{
    return id;
}

void Cursus::setID(unsigned int value)
{
    id = value;
}
