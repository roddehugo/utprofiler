#ifndef AbstractDAOFactory_h
#define AbstractDAOFactory_h

#include "UTProfilerException.h"
#include "dao/UVDAO.h"
#include "dao/DossierDAO.h"
#include "dao/EtudiantDAO.h"

#define DAO_FACTORY_DEFINE 0

struct Factory{
    virtual UVDAO* getUVDAO() =0;
    virtual EtudiantDAO* getEtudiantDAO() = 0;
};

class DAOFactory : public Factory, public Singleton<DAOFactory>
{

public:
    UVDAO* getUVDAO();

    EtudiantDAO* getEtudiantDAO();

};

class AbstractDAOFactory : public Factory
{
public:

    static Factory* getFactory(const int& type);

    static const unsigned int DAO_FACTORY = 0;
};

#endif // AbstractDAOFactory_h

