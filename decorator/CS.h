#ifndef CS_h
#define CS_h

#include "decorator/Creditable.h"
#include <QString>


class CS : public CategorieDecorator {

 public:

     QString getTitre()const;
     unsigned int getECTS() const;

     QString titre;
     unsigned int ects;
     CategorieDecorator* next;

     CS(const QString& t,const unsigned int& ects,Creditable& credit)
         :titre(t),ects(ects),CategorieDecorator(credit,t,ects),Creditable(credit){

     }
     ~CS(){};



};

#endif // CS_h

