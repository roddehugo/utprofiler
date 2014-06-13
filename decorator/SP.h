#ifndef SP_h
#define SP_h

#include "decorator/Creditable.h"
#include <QString>


class SP : public CategorieDecorator {

 public:

    virtual QString getTitre();

    virtual unsigned int getECTS();


 private:
    Creditable &credits;
};

#endif // SP_h

