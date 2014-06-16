#ifndef Inscription_h
#define Inscription_h

#include "dossier/Semestre.h"
#include "dossier/UV.h"

enum Resultat{
    A,B,C,D,E,F,FX,
    ABS, /*Absent*/
    RES, /*Reserve*/
    EC, /*En cours*/
    EQU  /*Equivalence*/
};

class UV;
class Semestre;

class Inscription {

 public:
    Inscription(const unsigned int id, UV* uv, Semestre* semestre, const Resultat& resultat);
    Inscription(UV *uv, Semestre *semestre, const Resultat &resultat);
    ~Inscription();

    Resultat getResultat() const;
    void setResultat(const Resultat &value);

    Semestre *getSemestre() const;
    void setSemestre(Semestre *value);

    UV *getUv() const;
    void setUv(UV *value);

    static Resultat str2resultat(const QString& str);
    static QString resultat2str(Resultat res);

    unsigned int ID() const;
    void setID(unsigned int value);

private:
    Resultat resultat;
    Semestre* semestre;
    UV* uv;
    unsigned int id;


};

#endif // Inscription_h

