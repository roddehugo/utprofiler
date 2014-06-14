#include "CS.h"


CS::CS(const QString &titre, const unsigned int ects, Creditable *creditable):
    Creditable(titre,ects),
    CategorieDecorator(titre,ects,creditable)
{

}

CS::~CS()
{

}

QString CS::getTitre() const
{
    return titre;
}

void CS::setTitre(const QString &value)
{
    titre = value;
}

unsigned int CS::getEcts() const
{
    return ects;
}

void CS::setEcts(unsigned int value)
{
    ects = value;
}
