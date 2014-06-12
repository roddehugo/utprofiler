#ifndef TC_h
#define TC_h

#include "decorator/Cursus.h"
#include <QString>


class TC : public Cursus {

 public:

    virtual QString getTitre();

    virtual QString getCode();
};

#endif // TC_h

