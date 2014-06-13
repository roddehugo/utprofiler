#ifndef AbstractDAOFactory_h
#define AbstractDAOFactory_h

#include "UTProfilerException.h"
#include "dao/UVDAO.h"
#include "dao/DossierDAO.h"

#define DAO_FACTORY_DEFINE 1

struct Factory{
    virtual UVDAO* getUVDAO() =0;
    virtual DossierDAO* getDossierDAO() =0;
};

class DAOFactory : public Factory
{

public:
    virtual UVDAO* getUVDAO(){
        return new UVDAO();
    }

    virtual DossierDAO* getDossierDAO(){

    }

private:
    UVDAO* uvdao;
    DossierDAO* dossierdao;

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

