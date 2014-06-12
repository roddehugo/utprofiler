#ifndef Desiderata_h
#define Desiderata_h

#include <QString>

class Dossier;

enum TypeDesiderata {
    Preference,
    Exigence,
    Rejet
};

class Desiderata {

 public:

    virtual void setType(QString t);

    virtual QString getType();


 private:
    int id;
    TypeDesiderata type;

 public:

    /**
     * @element-type Dossier
     */
    Dossier *myDossier;
};

#endif // Desiderata_h

