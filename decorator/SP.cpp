#include "SP.h"


SP::SP(const unsigned int id, const QString &titre, const unsigned int ects, Creditable *creditable):
    Creditable(id,titre,ects),
    CategorieDecorator(id,titre,ects,creditable)
{

}

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
    return creditable->getTitre() + " " + titre;
}

void SP::setTitre(const QString &value)
{
    titre = value;
}


QHash<QString, int> &SP::getEcts(QHash<QString, int> &ectsmap) const
{
    ectsmap.insert(titre,ects);
    creditable->getEcts(ectsmap);
    return ectsmap;
}

void SP::setEcts(unsigned int value)
{
    ects = value;
}

