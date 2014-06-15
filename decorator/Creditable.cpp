#include "decorator/Creditable.h"

Creditable::Creditable(const unsigned int id, const QString& titre,const unsigned int ects):
    id(id),
    titre(titre),
    ects(ects)
{

}

CategorieDecorator::CategorieDecorator(const unsigned int id, const QString& titre,const unsigned int ects, Creditable* creditable):
    Creditable(id,titre,ects),
    creditable(creditable)
{

}

CategorieDecorator::CategorieDecorator(const unsigned int id, const QString& titre, Creditable* creditable):
    Creditable(id,titre,0),
    creditable(creditable)
{

}

Creditable::Creditable(const QString& titre,const unsigned int ects):
    titre(titre),
    ects(ects)
{

}

CategorieDecorator::CategorieDecorator(const QString& titre,const unsigned int ects, Creditable* creditable):
    Creditable(titre,ects),
    creditable(creditable)
{

}

CategorieDecorator::CategorieDecorator(const QString& titre, Creditable* creditable):
    Creditable(titre,0),
    creditable(creditable)
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

void Creditable::setEcts(const unsigned int e){
    ects = e;
}

QHash<QString, int>& Creditable::getEcts(QHash<QString, int>& ectsmap) const {

    QHash<QString, int>::const_iterator i;
    int s = 0;
    for (i = ectsmap.constBegin(); i != ectsmap.constEnd(); ++i){
        s+=i.value();
    }
    if(ects!=0){
        ectsmap.insert("Crédits libres",ects-s);
        ectsmap.insert(titre,ects);
    }else{
        ectsmap.insert(titre,s);
    }

    return ectsmap;
}

Creditable *CategorieDecorator::getCreditable() const
{
    return creditable;
}

void CategorieDecorator::setCreditable(Creditable *value)
{
    creditable = value;
}

unsigned int Creditable::ID() const
{
    return id;
}

void Creditable::setID(unsigned int value){
    id = value;
}
