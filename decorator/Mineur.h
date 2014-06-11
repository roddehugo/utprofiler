#ifndef Mineur_h
#define Mineur_h

#include "Cursus.h"
#include "QString.h"


class Mineur : public Cursus {

 public:

    virtual QString getTitre();

    virtual QString getCode();
};

#endif // Mineur_h

