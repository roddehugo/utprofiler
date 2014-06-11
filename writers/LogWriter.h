#ifndef LogWriter_h
#define LogWriter_h

#include "Observer.h"


class LogWriter : virtual public Observer {

 public:

    virtual void update();
};

#endif // LogWriter_h

