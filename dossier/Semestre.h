#ifndef Semestre_h
#define Semestre_h

#include <QMap>
#include <QString>
#include "UTProfilerException.h"

class Cursus;
class Inscription;

enum Saison{
    Printemps,
    Automne
};

class Semestre {

 public:
    Semestre(const unsigned int id, const QString& titre, const Saison& saison, unsigned int annee, bool etranger, Cursus* cursus);
    Semestre(const QString& titre, const Saison& saison, unsigned int annee, bool etranger, Cursus* cursus);

    ~Semestre();

    Saison getSaison() const;
    void setSaison(const Saison &value);

    unsigned int getAnnee() const;
    void setAnnee(unsigned int value);

    QMap<int, Inscription *> getInscriptions() const;
    void setInscriptions(const QMap<int, Inscription *> &value);

    Cursus *getCursus() const;
    void setCursus(Cursus *value);

    bool isEtranger() const;
    void setEtranger(bool value);

    static Saison str2saison(const QString& str);
    static QString saison2str(Saison saison);

    unsigned int ID() const;

    void setID(unsigned int value);

    QString getTitre() const;
    void setTitre(const QString &value);


private:
    unsigned int id;
    QString titre;
    Saison saison;
    unsigned int annee;
    bool etranger;
    QMap<int, Inscription *> inscriptions;
    Cursus* cursus;

};

#endif // Semestre_h

