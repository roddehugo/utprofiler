#ifndef Filiere_h
#define Filiere_h

#include "Cursus.h"
#include "QString.h"
#include "Qstring.h"

class Branche;

class Filiere : public Cursus {

 public:

    virtual QString getTitre();

    virtual QString getCode();

 public:
    Qstring codeBranche;

 public:

    /**
     * @element-type Branche
     */
    Branche *myBranche;
};

#endif // Filiere_h

