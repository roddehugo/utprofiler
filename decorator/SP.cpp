#include "SP.h"


SP::SP(const QString &titre, const unsigned int ects, Creditable *creditable):
    Creditable(titre,ects),
    CategorieDecorator(titre,ects,creditable)
{

}

SP::~SP()
{

}

QString SP::getTitre() const
{
    return titre;
}

void SP::setTitre(const QString &value)
{
    titre = value;
}

unsigned int SP::getEcts() const
{
    return ects;
}

void SP::setEcts(unsigned int value)
{
    ects = value;
}
