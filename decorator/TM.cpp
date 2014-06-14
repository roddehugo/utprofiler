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
    return titre;
}

void TM::setTitre(const QString &value)
{
    titre = value;
}

unsigned int TM::getEcts() const
{
    return ects;
}

void TM::setEcts(unsigned int value)
{
    ects = value;
}
