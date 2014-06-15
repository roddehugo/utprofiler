#include "dao/Factories.h"


const unsigned int AbstractDAOFactory::DAO_FACTORY;

Factory* AbstractDAOFactory::getFactory(const int& type){
    switch (type) {
    case DAO_FACTORY:
        return DAOFactory::getInstance();
        break;
    default:
        return NULL;
        break;
    }
}

UVDAO* DAOFactory::getUVDAO(){
    return UVDAO::getInstance();
}

EtudiantDAO* DAOFactory::getEtudiantDAO(){
    return EtudiantDAO::getInstance();
}

InscriptionDAO *DAOFactory::getInscriptionDAO()
{
    return InscriptionDAO::getInstance();
}

DossierDAO *DAOFactory::getDossierDAO()
{
    return DossierDAO::getInstance();
}

CursusDAO *DAOFactory::getCursusDAO()
{
    return CursusDAO::getInstance();
}

DesiderataDAO *DAOFactory::getDesiderataDAO()
{
    return DesiderataDAO::getInstance();
}

SemestreDAO *DAOFactory::getSemestreDAO()
{
   return SemestreDAO::getInstance();
}


