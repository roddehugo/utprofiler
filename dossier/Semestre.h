#ifndef Semestre_h
#define Semestre_h

#include <QMap>
#include <QString>
#include "UTProfilerException.h"

class Dossier;
class Inscription;

enum Saison{
    Printemps,
    Automne
};

class Semestre {

 public:
    Semestre(const unsigned int id, const Saison& saison, unsigned int annee, bool etranger, Dossier* dossier, const QMap<int, Inscription*>& inscriptions);
    Semestre(const unsigned int id, const Saison& saison, unsigned int annee, bool etranger, Dossier* dossier);
    Semestre(const Saison& saison, unsigned int annee, bool etranger, Dossier* dossier);
    ~Semestre();

    Saison getSaison() const;
    void setSaison(const Saison &value);

    unsigned int getAnnee() const;
    void setAnnee(unsigned int value);

    QMap<int, Inscription *> getInscriptions() const;
    void setInscriptions(const QMap<int, Inscription *> &value);

    Dossier *getDossier() const;
    void setDossier(Dossier *value);

    bool isEtranger() const;
    void setEtranger(bool value);

    static Saison str2saison(const QString& str);
    static QString saison2str(Saison saison);

    unsigned int ID() const;

    void setID(unsigned int value);

private:
    Saison saison;
    unsigned int annee;
    bool etranger;
    unsigned int id;
    QMap<int, Inscription *> inscriptions;
    Dossier* dossier;

};

#endif // Semestre_h

