#include "UTProfiler.h"

UTProfiler::UTProfiler(){
    factory = AbstractDAOFactory::getFactory(AbstractDAOFactory::DAO_FACTORY);
    UVDAO* uvDao = factory->getUVDAO();
}

AbstractDAOFactory* UTProfiler::getCurrentFactory(){
    return factory;
}

