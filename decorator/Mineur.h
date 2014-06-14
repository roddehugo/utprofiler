#ifndef Mineur_h
#define Mineur_h

#include "decorator/Cursus.h"
#include <QString>


class Mineur : public Cursus {

 public:
    Mineur(const QString& c, const QString& titre, const int& cat, const unsigned int& ects,const unsigned int m,const unsigned int cur, const unsigned int idparent )
        :Cursus(c,titre,cat,ects,m,cur,idparent){}

    virtual QString getTitre() const;
    virtual QString getCode() const;

    ~Mineur(){}

};

#endif // Mineur_h

