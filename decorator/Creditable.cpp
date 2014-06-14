#include "decorator/Creditable.h"

Creditable::Creditable(const QString& titre,const unsigned int ects):
    titre(titre),
    ects(ects)
{

}

CategorieDecorator::CategorieDecorator(const QString& titre,const unsigned int ects, Creditable* creditable):
    creditable(creditable),
    Creditable(titre,ects)
{

}

CategorieDecorator::CategorieDecorator(const QString& titre, Creditable* creditable):
    creditable(creditable),
    Creditable(titre,0)
{

}

Creditable::~Creditable()
{

}


CategorieDecorator::~CategorieDecorator()
{

}


QString Creditable::getTitre() const {
    return titre;
}

QString CategorieDecorator::getTitre() const {
    return creditable->getTitre() + " " + titre;
}

Creditable *CategorieDecorator::getCreditable() const
{
    return creditable;
}

void CategorieDecorator::setCreditable(Creditable *value)
{
    creditable = value;
}

