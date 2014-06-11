#ifndef UV_h
#define UV_h

#include "Creditable.h"
#include "QString.h"
#include "Saison.h"

class Inscription;
class Inscription;

class UV : public Creditable {

 public:

    virtual QString getCode();

    virtual QString getTitre();

    virtual Saison getSaisons();

    virtual void setCode(QString c);

    virtual void setTitre(QString t);

    virtual void setSaison(int s);

    virtual int getSaison();

 public:
    int SAISON_PRINTEMPS;
    int SAISON_AUTOMNE;
    int SAISON_NULL;
    int SAISON_BOTH;

 private:
    QString code;
    QString titre;

 public:

    /**
     * @element-type Inscription
     */
    Inscription *myInscription;

    /**
     * @element-type Semestre
     */
    Inscription *InscriptionAssoc;
};

#endif // UV_h

