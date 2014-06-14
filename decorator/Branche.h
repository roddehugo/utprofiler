#ifndef Branche_h
#define Branche_h

#include <vector>

#include "decorator/Cursus.h"
#include "decorator/Filiere.h"
#include <QString>


class Branche : public Cursus {

 public:

    Branche(const QString& c, const QString& titre, const int& cat, const unsigned int& ects,const unsigned int m,const unsigned int cur, const unsigned int idparent )
        :Cursus(c,titre,cat,ects,m,cur,idparent){}

    virtual QString getTitre() const;
    virtual QString getCode() const;

    ~Branche(){}

 public:

    /**
     * @element-type Filiere
     */
    std::vector< Filiere > myFiliere;
};

#endif // Branche_h

