#ifndef TM_h
#define TM_h

#include "decorator/CategorieDecorator.h"
#include "decorator/Creditable.h"
#include <QString>


class TM : public CategorieDecorator {

 public:

    virtual QString getTitre();

    virtual unsigned int getECTS();


 private:
    Creditable &credit;
};

#endif // TM_h

