#ifndef SP_h
#define SP_h

#include "decorator/Creditable.h"
#include <QString>


class SP : public CategorieDecorator {

 public:

    virtual QString getTitre()const;
    virtual unsigned int getECTS()const;
    QString titre;
    unsigned int ects;
    CategorieDecorator* next;
    ~SP(){};
    SP(const QString& t,const unsigned int& ects,Creditable& credit)
        :Creditable(credit),CategorieDecorator(credit,t,ects),titre(t),ects(ects){

    }

};


#endif // SP_h

