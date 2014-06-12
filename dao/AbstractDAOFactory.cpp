#include "dao/AbstractDAOFactory.h"
#include "dao/DAOFactory.h"

AbstractDAOFactory* AbstractDAOFactory::getFactory(const int& type)
{
    switch (type) {
    case AbstractDAOFactory::DAO_FACTORY:
        return new DAOFactory();
        break;
//    case AbstractDAOFactory::XML_FACTORY:
//        return new XMLFactory();
//        break;
    default:
        throw UTProfilerException("Missing type param");
        break;
    }
}

