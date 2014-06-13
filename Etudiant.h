#ifndef Etudiant_h
#define Etudiant_h

#include <QString>

class Etudiant
{
 public:

    const QString& getPrenom() {return prenom;}

    const QString& getNom() {return nom;}

    const QString& getLogin() {return login;}

    const bool& isAdmin() {return admin;}

    void setPrenom(const QString & p){prenom = p;}

    void setNom(const QString & n){nom = n;}

    void setLogin(const QString & l){login=l;}

    void setAdmin(const bool & a){admin=a;}

 private:
    unsigned int id;
    QString prenom;
    QString nom;
    QString login;
    bool admin;

 public:

};

#endif // Etudiant_h

