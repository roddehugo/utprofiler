#ifndef Filiere_h
#define Filiere_h

#include "decorator/Cursus.h"
#include <QString>

class Branche;

class Filiere : public Cursus {

 public:

    virtual QString getTitre();

    virtual QString getCode();

 public:
    QString codeBranche;

 public:

    /**
     * @element-type Branche
     */
    Branche *myBranche;
};

#endif // Filiere_h

