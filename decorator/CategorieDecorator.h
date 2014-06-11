#ifndef CategorieDecorator_h
#define CategorieDecorator_h

#include "Creditable.h"
#include "QString.h"


class CategorieDecorator : public Creditable {

 public:

    virtual QString getTitre()  = 0;
};

#endif // CategorieDecorator_h

