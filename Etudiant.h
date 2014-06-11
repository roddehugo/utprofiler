#ifndef Etudiant_h
#define Etudiant_h

#include "Dossier.h"
#include "QString.h"

class UTProfiler;

class Etudiant {

 public:

    virtual QString getPrenom();

    virtual QString getNom();

    virtual QString getLogin();

    virtual bool isAdmin();

    virtual void setPrenom(QString p);

    virtual void setNom(QString s);

    virtual void setLogin(QString l);

    virtual void setAdmin(bool a);


 private:
    QString prenom;
    QString nom;
    unsigned int id;
    QString login;
    bool admin;

 public:

    /**
     * @element-type UTProfiler
     */
    UTProfiler *myUTProfiler;

    Dossier myDossier;
};

#endif // Etudiant_h

