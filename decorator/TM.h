#ifndef TM_h
#define TM_h

#include "CategorieDecorator.h"
#include "Creditable.h"
#include "QString.h"


class TM : public CategorieDecorator {

 public:

    virtual QString getTitre();

    virtual unsigned int getECTS();


 private:
    Creditable &credit;
};

#endif // TM_h

