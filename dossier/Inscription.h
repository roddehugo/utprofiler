#ifndef Inscription_h
#define Inscription_h

#include "Resultat.h"
#include "Semestre.h"
#include "UV.h"


class Inscription {

 public:

    virtual Resultat getResultat();

    virtual void setResultat(Resultat r);


 private:
    Resultat resultat;

 public:

    /**
     * @element-type Semestre
     */
    Semestre mySemestre;

    /**
     * @element-type UV
     */
    UV myUV;
};

#endif // Inscription_h

