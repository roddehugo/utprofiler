#ifndef CS_h
#define CS_h

#include "CategorieDecorator.h"
#include "Creditable.h"
#include "QString.h"


class CS : public CategorieDecorator {

 public:

    virtual QString getTitre();

    virtual unsigned int getESCTS();


 private:
    Creditable &credit;
};

#endif // CS_h

