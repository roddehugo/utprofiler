#ifndef Dossier_h
#define Dossier_h

#include <vector>
#include <QString>

#include "dossier/Cursus.h"
#include "dossier/Inscription.h"
#include "dossier/Semestre.h"

//class AlgoManager;
class Etudiant;

class Dossier {

 public:

    Dossier(const unsigned int id, const QString& titre, bool solution,Etudiant* etudiant);
    Dossier(const QString &titre, bool solution, Etudiant *etudiant);
    ~Dossier();

    Etudiant *getEtudiant() const;
    void setEtudiant(Etudiant *value);

    bool isSolution() const;
    void setSolution(bool value);

    QString getTitre() const;
    void setTitre(const QString &value);

    unsigned int ID() const;

    void setID(unsigned int id);

private:
    unsigned int id;
    QString titre;
    bool solution;
    Etudiant* etudiant;

};

#endif // Dossier_h

