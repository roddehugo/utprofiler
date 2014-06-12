#ifndef XMLFACTORY_H
#define XMLFACTORY_H

#include "dao/AbstractDAOFactory.h"

class XMLFactory : public AbstractDAOFactory {

public:
    const DossierDAO& getDossierDAO();

    const UVDAO& getUVDAO();
};


#endif // XMLFACTORY_H
