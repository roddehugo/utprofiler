#ifndef DAOFACTORY_H
#define DAOFACTORY_H

#include "dao/AbstractDAOFactory.h"
#include "dao/UVDAO.h"

class DAOFactory : public AbstractDAOFactory {

 public:
//    const DossierDAO& getDossierDAO();

    UVDAO* getUVDAO(){return new UVDAO;}

};

#endif // DAOFACTORY_H
