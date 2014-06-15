#include "Desiderata.h"




Desiderata::Desiderata(const unsigned int id, TypeDesiderata type, Dossier *dossier, Creditable *uv):
    id(id),type(type),myDossier(dossier),uv(uv){
}

Desiderata::Desiderata(TypeDesiderata type, Dossier *dossier, Creditable *uv):
    type(type),myDossier(dossier),uv(uv)
{

}

Desiderata::~Desiderata()
{

}
unsigned int Desiderata::getId() const
{
    return id;
}

void Desiderata::setId(unsigned int value)
{
    id = value;
}
Creditable *Desiderata::getUv() const
{
    return uv;
}

void Desiderata::setUv(Creditable *value)
{
    uv = value;
}

TypeDesiderata Desiderata::str2typeD(const QString &str)
{
    if(str=="Preference")
        return Preference;
    else if(str=="Exigence")
        return Exigence;
    else if(str=="Rejet")
        return Rejet;
    else
        UTProfilerException("Impossible de convertir QString en TypeDesiderata" + str);


}

QString Desiderata::typeD2str(TypeDesiderata desiderata)
{
    switch(desiderata)
    {
    case Preference:
        return "Preference";
    case Exigence:
        return "Exigence";
    case Rejet:
        return "Rejet";
    default:
        throw UTProfilerException("Impossible de convertir Desiderata en QString" + desiderata);
    }


}
TypeDesiderata Desiderata::getType() const
{
    return type;
}

void Desiderata::setType(const TypeDesiderata &value)
{
    type = value;
}


Dossier *Desiderata::getMyDossier() const
{
    return myDossier;
}

void Desiderata::setMyDossier(Dossier *value)
{
    myDossier = value;
}





