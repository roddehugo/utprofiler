#ifndef SP_h
#define SP_h

#include "CategorieDecorator.h"
#include "Creditable.h"
#include "QString.h"


class SP : public CategorieDecorator {

 public:

    virtual QString getTitre();

    virtual unsigned int getECTS();


 private:
    Creditable &credits;
};

#endif // SP_h

