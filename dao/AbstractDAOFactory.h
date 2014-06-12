#ifndef AbstractDAOFactory_h
#define AbstractDAOFactory_h

#include "UTProfilerException.h"
#include "dao/UVDAO.h"

class DAOFactory;

class AbstractDAOFactory {

 public:

//    virtual const DossierDAO& getDossierDAO()  = 0;

    virtual UVDAO* getUVDAO() = 0;

    static AbstractDAOFactory* getFactory(const int &type);

 public:
    static const int DAO_FACTORY = 0;
    static const int XML_FACTORY = 1;

};

#endif // AbstractDAOFactory_h

