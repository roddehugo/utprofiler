#ifndef Semestre_h
#define Semestre_h

#include <vector>

#include "QString.h"

class Inscription;
class Inscription;
class Dossier;

class Semestre {

 public:

    virtual void Semestre(QString s, QString a);

    virtual QString getSaison();

    virtual unsigned int getAnnee();

    virtual QString getCode();

    virtual void setSaison(QString s);

    virtual void setCode(QString c);

    virtual void setAnnee(unsigned int a);


 private:
    QString saison;
    unsigned int annee;

 public:

    /**
     * @element-type Inscription
     */
    Inscription *myInscription;

    /**
     * @element-type UV
     */
    std::vector< Inscription* > InscriptionAssoc;

    /**
     * @element-type Dossier
     */
    Dossier *myDossier;
};

#endif // Semestre_h

