#ifndef Mineur_h
#define Mineur_h

#include "decorator/Cursus.h"
#include <QString>


class Mineur : public Cursus {

 public:

    virtual QString getTitre();

    virtual QString getCode();
};

#endif // Mineur_h

