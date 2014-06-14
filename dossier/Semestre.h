#ifndef Semestre_h
#define Semestre_h

#include <QMap>
#include <QString>

class Dossier;
class Inscription;

enum Saison{
    Printemps,
    Automne
};

class Semestre {

 public:
    Semestre(const Saison& saison, const unsigned int annee, Dossier* dossier, const QMap<int, Inscription*>& inscriptions);
    Semestre(const Saison& saison, const unsigned int annee, Dossier* dossier);
    ~Semestre();

    Saison getSaison() const;
    void setSaison(const Saison &value);

    unsigned int getAnnee() const;
    void setAnnee(unsigned int value);

    QMap<int, Inscription *> getInscriptions() const;
    void setInscriptions(const QMap<int, Inscription *> &value);

    Dossier *getDossier() const;
    void setDossier(Dossier *value);

private:
    Saison saison;
    unsigned int annee;
    QMap<int, Inscription *> inscriptions;
    Dossier* dossier;

};

#endif // Semestre_h

