#ifndef Dossier_h
#define Dossier_h

#include <vector>
#include <QString>

#include "decorator/Cursus.h"
#include "dossier/Desiderata.h"
#include "dossier/Inscription.h"
#include "dossier/Semestre.h"

class AlgoManager;
class Etudiant;

class Dossier {

 public:

    Dossier();

    void setTitre(const QString& t){titre=t;}

    const QString& getTitre(){return titre;}

    void setSolution(const bool& s){solution=s;}

    const bool& isSolution(){return solution;}


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

