#ifndef HuTech_h
#define HuTech_h

#include "decorator/Cursus.h"
#include <QString>


class HuTech : public Cursus {

 public:

    virtual QString getTitre();

    virtual QString getCode();
};

#endif // HuTech_h

