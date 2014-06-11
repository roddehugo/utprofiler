#ifndef Cursus_h
#define Cursus_h

#include "Creditable.h"
#include "QString.h"
#include "Qstring.h"

class Dossier;

class Cursus : public Creditable {

 public:

    virtual QString getTitre()  = 0;

    virtual QString getCode()  = 0;

    virtual int newOperation();


 private:
    Qstring code;
    Qstring titre;
    int maxSemestres;
    unsigned int current;

 public:

    /**
     * @element-type Dossier
     */
    Dossier *myDossier;
};

#endif // Cursus_h

