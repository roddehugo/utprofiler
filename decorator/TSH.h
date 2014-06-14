#ifndef TSH_h
#define TSH_h

#include "decorator/Creditable.h"
#include <QString>
enum ligne {Communiquer,Perception};
enum colonne{Pratique,Theorique};
class TSH : public CategorieDecorator {

 public:

    virtual ligne getTagl();

    virtual colonne getTagc();
    virtual QString getTitre() const;

    virtual unsigned int getECTS() const;
    QString titre;
    unsigned int ects;
    CategorieDecorator* next;

    TSH(const QString& t,const unsigned int& ects,Creditable& credit,colonne c, ligne l)
        :titre(t),ects(ects),CategorieDecorator(credit,t,ects),Creditable(credit),tagc(c),tagl(l){

    }
    ~TSH(){};
 private:
    colonne tagc;
    ligne tagl;




};

#endif // TSH_h

