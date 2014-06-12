#ifndef Inscription_h
#define Inscription_h

#include "dossier/Semestre.h"
#include "decorator/UV.h"

enum Resultat{
    A,B,C,D,E,F,FX,
    RES, /*Reserve*/
    ACT, /*En cours*/
    EQU  /*Equivalence*/
};

class Inscription {

 public:

    Resultat getResultat();

    void setResultat(Resultat r);


 private:
    Resultat resultat;

 public:

};

#endif // Inscription_h

