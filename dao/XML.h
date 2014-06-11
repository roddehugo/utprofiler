#ifndef XML<T>_h
#define XML<T>_h

#include "T.h"


class XML<T> {

 public:

    virtual T find(unsigned int id);

    virtual void update(T obj);

    virtual void delete(T obj);

    virtual void create(T obj);
};

#endif // XML<T>_h

