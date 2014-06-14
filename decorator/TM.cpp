#include "TM.h"

TM::TM(const QString &titre, const unsigned int ects, Creditable *creditable):
    Creditable(titre,ects),
    CategorieDecorator(titre,ects,creditable)
{

}

TM::~TM()
{

}

QString TM::getTitre() const
{
    return creditable->getTitre() + " " + titre;
}

void TM::setTitre(const QString &value)
{
    titre = value;
}

QHash<QString, int> &TM::getEcts(QHash<QString, int> &ectsmap) const
{
    ectsmap.insert(titre,ects);
    creditable->getEcts(ectsmap);
    return ectsmap;
}

void TM::setEcts(unsigned int value)
{
    ects = value;
}
