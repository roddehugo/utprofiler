#include "TSH.h"

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
    return titre;
}

void TSH::setTitre(const QString &value)
{
    titre = value;
}

unsigned int TSH::getEcts() const
{
    return ects;
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
