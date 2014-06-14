#include "Inscription.h"


Resultat Inscription::getResultat() const
{
    return resultat;
}

void Inscription::setResultat(const Resultat &value)
{
    resultat = value;
}
Semestre *Inscription::getSemestre() const
{
    return semestre;
}

void Inscription::setSemestre(Semestre *value)
{
    semestre = value;
}
UV *Inscription::getUv() const
{
    return uv;
}

void Inscription::setUv(UV *value)
{
    uv = value;
}


