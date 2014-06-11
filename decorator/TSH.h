#ifndef TSH_h
#define TSH_h

#include "CategorieDecorator.h"
#include "Creditable.h"


class TSH : public CategorieDecorator {

 public:

    virtual int getX();

    virtual int getY();


 private:
    Creditable &credits;
    int x;
    int y;
};

#endif // TSH_h

