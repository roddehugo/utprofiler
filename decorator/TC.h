#ifndef TC_h
#define TC_h

#include "Cursus.h"
#include "QString.h"


class TC : public Cursus {

 public:

    virtual QString getTitre();

    virtual QString getCode();
};

#endif // TC_h

