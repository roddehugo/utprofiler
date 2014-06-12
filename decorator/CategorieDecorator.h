#ifndef CategorieDecorator_h
#define CategorieDecorator_h

#include "decorator/Creditable.h"
#include <QString>


class CategorieDecorator : public Creditable {

 public:

    virtual QString getTitre()  = 0;
};

#endif // CategorieDecorator_h

