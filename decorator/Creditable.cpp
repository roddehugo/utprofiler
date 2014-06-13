
#include "decorator/Creditable.h"




QString Creditable::Creditable::getTitre()
{
    }

Creditable::Creditable(QString& titre,unsigned int ects):titre(titre),ects(ects){
}

Creditable::~Creditable(){
}


CategorieDecorator::~CategorieDecorator(){
}


CategorieDecorator::CategorieDecorator(Creditable& creditable,QString& titre,unsigned int ects):m_creditable(creditable),Creditable(titre,ects){

}
