#ifndef Connection_h
#define Connection_h

#include "Connection.h"


class Connection {

 public:

    virtual Connection getInstance();

 private:

    virtual Connection();


 private:
    Connection instance;
};

#endif // Connection_h

