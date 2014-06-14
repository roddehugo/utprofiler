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
    return creditable->getTitre() + " " + titre;
}

void CS::setTitre(const QString &value)
{
    titre = value;
}

QHash<QString, int> &CS::getEcts(QHash<QString, int> &ectsmap) const
{
    ectsmap.insert(titre,ects);
    creditable->getEcts(ectsmap);
    return ectsmap;
}

void CS::setEcts(unsigned int value)
{
    ects = value;
}
