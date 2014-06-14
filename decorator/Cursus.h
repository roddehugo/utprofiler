#ifndef Cursus_h
#define Cursus_h

#include "decorator/Creditable.h"
#include <QString>

class Dossier;

class Cursus : public Creditable {

 public:
    Cursus(const QString& c, const QString& titre, const int& cat, const unsigned int& ects,const unsigned int m,const unsigned int cur, const unsigned int idparent )
        :Creditable(titre,ects),code(c),categorie(cat)
    {}

    ~Cursus(){}

 protected:
    QString code;
    QString titre;
    unsigned int maxSemestres;
    unsigned int current;
    unsigned int categorie;
    Cursus* parent;

 public:

    QString getCode() const { return code; }


    QString getTitre() const { return titre; }

    int getCategorie() const { return categorie; }

    void setCode(const QString& c) { code=c; }

    void setTitre(const QString& t) { titre=titre; }

    void setCategorie(int cat){ categorie = cat; }

    unsigned int getECTS() const {return ects;}


    /**
     * @element-type Dossier
     */
    Dossier *myDossier;
};



#endif // Cursus_h

