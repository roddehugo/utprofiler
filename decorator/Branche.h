#ifndef Branche_h
#define Branche_h

#include <vector>

#include "Cursus.h"
#include "Filiere.h"
#include "QString.h"


class Branche : public Cursus {

 public:

    virtual QString getTitre();

    virtual QString getCode();

 public:

    /**
     * @element-type Filiere
     */
    std::vector< Filiere > myFiliere;
};

#endif // Branche_h

