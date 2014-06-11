#ifndef Dossier_h
#define Dossier_h

#include <vector>

#include "Cursus.h"
#include "Desiderata.h"
#include "Inscription.h"
#include "QString.h"
#include "Semestre.h"

class AlgoManager;
class Etudiant;

class Dossier {

 public:

    virtual void setTitre(QString t);

    virtual QString getTitre();

    virtual void setSolution(bool s);

    virtual bool isSolution();


 private:
    QString titre;
    bool solution;

 public:

    Cursus &myCursus;

    /**
     * @element-type Inscription
     */
    std::vector< Inscription > myInscription;

    /**
     * @element-type AlgoManager
     */
    AlgoManager *myAlgoManager;

    /**
     * @element-type Semestre
     */
    std::vector< Semestre > mySemestre;

    /**
     * @element-type Etudiant
     */
    Etudiant *myEtudiant;

    /**
     * @element-type Desiderata
     */
    std::vector< Desiderata > myDesiderata;
};

#endif // Dossier_h

