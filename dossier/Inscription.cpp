#include "Inscription.h"



Dossier *Inscription::getDossier() const
{
    return dossier;
}

void Inscription::setDossier(Dossier *value)
{
    dossier = value;
}
Inscription::Inscription(const unsigned int id, UV *uv, Semestre *semestre, const Resultat &resultat, Dossier *dossier):
    id(id),
    uv(uv),
    semestre(semestre),
    resultat(resultat),
    dossier(dossier)
{

}

Inscription::Inscription(UV *uv, Semestre *semestre, const Resultat &resultat, Dossier* dossier):
    uv(uv),
    semestre(semestre),
    resultat(resultat),
    dossier(dossier)
{

}

Inscription::~Inscription()
{

}

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


Resultat Inscription::str2resultat(const QString& str)
{
    if(str=="A")
        return A;
    else if(str=="B")
        return B;
    else if(str=="C")
        return C;
    else if(str=="D")
        return D;
    else if(str=="E")
        return E;
    else if(str=="F")
        return F;
    else if(str=="FX")
        return FX;
    else if(str=="ABS")
        return ABS;
    else if(str=="RES")
        return RES;
    else if(str=="EC")
        return EC;
    else if(str=="EQU")
        return EQU;
    else
        throw UTProfilerException("Impossible de convertir QString en Resultat" + str);
}
QString Inscription::resultat2str(Resultat res)
{
    switch(res)
    {
        case A:
            return   "A";
        case B:
            return   "B";
        case C:
            return   "C";
        case D:
            return   "D";
        case E:
            return   "E";
        case F:
            return   "F";
        case FX:
            return   "FX";
        case ABS:
            return   "ABS";
        case RES:
            return   "RES";
        case EC:
            return   "EC";
        case EQU:
            return   "EQU";
        default:
            throw UTProfilerException("Impossible de convertir Resultat en QString");
    }
}

unsigned int Inscription::ID() const
{
    return id;
}


void Inscription::setID(unsigned int value)
{
    id = value;
}

