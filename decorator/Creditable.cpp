#include "decorator/Creditable.h"

QString Creditable::getTitre() const {}
Creditable::Creditable(const QString& titre,const unsigned int& ects)
    :titre(titre),ects(ects){

}

Creditable::~Creditable(){
}


CategorieDecorator::~CategorieDecorator(){
}


CategorieDecorator::CategorieDecorator(Creditable& creditable,const QString& titre,const unsigned int ects)
    :m_creditable(creditable),Creditable(titre,ects){

}

QString CategorieDecorator::getTitre() const {

}
