#ifndef CS_h
#define CS_h

#include "decorator/CategorieDecorator.h"
#include "decorator/Creditable.h"
#include <QString>


class CS : public CategorieDecorator {

 public:

    virtual QString getTitre();

    virtual unsigned int getESCTS();


 private:
    Creditable &credit;
};

#endif // CS_h

