#include "TSH.h"

TSH::TSH(const unsigned int id, const QString &titre, const unsigned int ects, Creditable *creditable):
    Creditable(id,titre,ects),
    CategorieDecorator(id,titre,ects,creditable)
{

}

TSH::TSH(const QString &titre, const unsigned int ects, Creditable *creditable):
    Creditable(titre,ects),
    CategorieDecorator(titre,ects,creditable)
{

}

TSH::~TSH()
{

}

QString TSH::getTitre() const
{
    return creditable->getTitre() + " " + titre;
}

void TSH::setTitre(const QString &value)
{
    titre = value;
}

QHash<QString, int> &TSH::getEcts(QHash<QString, int> &ectsmap) const
{
    ectsmap.insert(titre,ects);
    creditable->getEcts(ectsmap);
    return ectsmap;
}

void TSH::setEcts(unsigned int value)
{
    ects = value;
}


colonne TSH::getTagc() const
{
    return tagc;
}

void TSH::setTagc(const colonne &value)
{
    tagc = value;
}

ligne TSH::getTagl() const
{
    return tagl;
}

void TSH::setTagl(const ligne &value)
{
    tagl = value;
}
