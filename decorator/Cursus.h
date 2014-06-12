#ifndef Cursus_h
#define Cursus_h

#include "decorator/Creditable.h"
#include <QString>

class Dossier;

class Cursus : public Creditable {

 public:

    virtual QString getTitre()  = 0;

    virtual QString getCode()  = 0;

    virtual int newOperation();


 private:
    QString code;
    QString titre;
    int maxSemestres;
    unsigned int current;

 public:

    /**
     * @element-type Dossier
     */
    Dossier *myDossier;
};

#endif // Cursus_h

