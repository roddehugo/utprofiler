#ifndef TM_h
#define TM_h

#include "decorator/Creditable.h"
#include <QString>


class TM : public CategorieDecorator {

 public:

    virtual QString getTitre() const;

    virtual unsigned int getECTS() const;

    QString titre;
    unsigned int ects;
    CategorieDecorator* next;

    TM(const QString& t,const unsigned int& ects,Creditable& credit)
        :titre(t),ects(ects),CategorieDecorator(credit,t,ects),Creditable(credit){

    }
    ~TM(){};
};

#endif // TM_h

