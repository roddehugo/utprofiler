#ifndef Dossier_h
#define Dossier_h

#include <vector>
#include <QString>

#include "decorator/Cursus.h"
#include "dossier/Inscription.h"
#include "dossier/Semestre.h"

//class AlgoManager;
class Etudiant;

class Dossier {

 public:

    Dossier(const QString& titre, bool solution,Etudiant* etudiant);
    ~Dossier();

    Etudiant *getEtudiant() const;
    void setEtudiant(Etudiant *value);

    bool getSolution() const;
    void setSolution(bool value);

    QString getTitre() const;
    void setTitre(const QString &value);

private:
    QString titre;
    bool solution;
    Etudiant* etudiant;

};

#endif // Dossier_h

