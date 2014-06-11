#ifndef HuTech_h
#define HuTech_h

#include "Cursus.h"
#include "QString.h"


class HuTech : public Cursus {

 public:

    virtual QString getTitre();

    virtual QString getCode();
};

#endif // HuTech_h

