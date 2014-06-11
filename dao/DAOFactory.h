#ifndef DAOFactory_h
#define DAOFactory_h

#include "AbstractDAOFactory.h"
#include "Connection.h"


class DAOFactory : public AbstractDAOFactory {

 public:

    virtual Connection getConnection();


 private:
    Connection connection;
};

#endif // DAOFactory_h

