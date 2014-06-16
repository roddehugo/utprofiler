#include "Cursus.h"



Cursus *Cursus::getParent() const
{
    return parent;
}

void Cursus::setParent(Cursus *value)
{
    parent = value;
}
Cursus::Cursus(const unsigned int id, const QString &code, const QString &titre, const unsigned int ects,
               const unsigned int maxSemestre,const unsigned int previsionsSemestres,
               QMap<QString, int> credits, Cursus *parent):
    id(id),
    titre(titre),
    code(code),
    ects(ects),
    parent(parent),
    maxSemestres(maxSemestre),
    previsionsSemestres(previsionsSemestres),
    credits(credits){

}

Cursus::Cursus(const QString &code, const QString &titre, const unsigned int ects,
               const unsigned int maxSemestre,const unsigned int previsionsSemestres,
               QMap<QString, int> credits, Cursus *parent):
    titre(titre),
    code(code),
    ects(ects),
    maxSemestres(maxSemestre),
    parent(parent),
    previsionsSemestres(previsionsSemestres),
    credits(credits){

}

unsigned int Cursus::getPrevisionsSemestres() const
{
    return previsionsSemestres;
}

void Cursus::setPrevisionsSemestres(unsigned int value)
{
    previsionsSemestres = value;
}

QString Cursus::getCode() const
{
    return code;
}

void Cursus::setCode(const QString& value){
    code = value;
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
