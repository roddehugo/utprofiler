#ifndef AbstractDAOFactory_h
#define AbstractDAOFactory_h

#include "AbstractDAOFactory.h"
#include "DossierDAO.h"
#include "UVDAO.h"

class UTProfiler;

class AbstractDAOFactory {

 public:

    virtual DossierDAO getDossierDAO()  = 0;

    virtual UVDAO getUVDAO()  = 0;

    virtual AbstractDAOFactory &getFactory(int type);

 public:
    int DAO_FACTORY;
    int XML_FACTORY;

 public:

    /**
     * @element-type UTProfiler
     */
    UTProfiler *myUTProfiler;
};

#endif // AbstractDAOFactory_h

