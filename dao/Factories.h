#ifndef AbstractDAOFactory_h
#define AbstractDAOFactory_h

#include "UTProfilerException.h"
#include "dao/UVDAO.h"
#include "dao/DossierDAO.h"
#include "dao/EtudiantDAO.h"

#define DAO_FACTORY_DEFINE 0

struct Factory{
    virtual UVDAO* getUVDAO() =0;
    virtual DossierDAO* getDossierDAO() =0;
};

class DAOFactory : public Factory
{

public:
    UVDAO* getUVDAO(){
        return new UVDAO();
    }

    DossierDAO* getDossierDAO(){
        //return new DossierDAO();
    }

};

class AbstractDAOFactory : public Factory
{
public:

    static Factory* getFactory(const int& type){
        switch (type) {
        case DAO_FACTORY:
            return new DAOFactory();
            break;
        default:
            return NULL;
            break;
        }
    }

    static const unsigned int DAO_FACTORY = 0;
};

const unsigned int AbstractDAOFactory::DAO_FACTORY;

#endif // AbstractDAOFactory_h

