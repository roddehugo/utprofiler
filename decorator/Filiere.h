#ifndef Filiere_h
#define Filiere_h

#include "decorator/Cursus.h"
#include <QString>

class Branche;

class Filiere : public Cursus {

 public:

    Filiere(const QString& c, const QString& titre, const int& cat, const unsigned int& ects,const unsigned int m,const unsigned int cur, const unsigned int idparent )
        :Cursus(c,titre,cat,ects,m,cur,idparent){}

    virtual QString getTitre() const;
    virtual QString getCode() const;

    ~Filiere(){}

 public:
    QString codeBranche;
    /**
     * @element-type Branche
     */
    Branche *myBranche;
};

#endif // Filiere_h

