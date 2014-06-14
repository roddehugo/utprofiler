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

class UV;
class Semestre;

class Inscription {

 public:
    Inscription(UV* uv, Semestre* semestre, const Resultat& resultat);
    ~Inscription();


    Resultat getResultat() const;
    void setResultat(const Resultat &value);

    Semestre *getSemestre() const;
    void setSemestre(Semestre *value);

    UV *getUv() const;
    void setUv(UV *value);

private:
    Resultat resultat;
    Semestre* semestre;
    UV* uv;


};

#endif // Inscription_h

