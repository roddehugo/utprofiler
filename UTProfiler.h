#ifndef UTProfiler_h
#define UTProfiler_h

#include <QString>
#include "dao/AbstractDAOFactory.h"
#include "dao/UVDAO.h"

class UTProfiler{

 public:
    UTProfiler();

    AbstractDAOFactory *getCurrentFactory();

private:
    AbstractDAOFactory *factory;
};

#endif // UTProfiler_h

