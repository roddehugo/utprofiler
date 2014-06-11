#ifndef DAO<T>_h
#define DAO<T>_h

#include "Connection.h"
#include "T.h"


class DAO<T> {

 public:

    virtual T find(unsigned int id);

    virtual void update(T obj);

    virtual void delete(T obj);

    virtual void create(T obj);

 public:
    Connection connection;
};

#endif // DAO<T>_h

