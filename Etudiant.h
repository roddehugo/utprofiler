#ifndef Etudiant_h
#define Etudiant_h

#include <QString>

class Etudiant
{
 public:

    Etudiant(const QString& login, const QString& prenom, const QString& nom)
        :login(login), prenom(prenom), nom(nom)
    {}

    ~Etudiant(){}

    QString getPrenom() const {return prenom;}

    QString getNom() const {return nom;}

    QString getLogin() const {return login;}

    bool isAdmin() const {return admin;}

    void setPrenom(const QString & p){prenom = p;}

    void setNom(const QString & n){nom = n;}

    void setLogin(const QString & l){login=l;}

    void setAdmin(const bool & a){admin=a;}

    bool isCurrent() const{return current;}

    void setCurrent(const bool& v){current=v;}

 private:
    QString login;
    QString prenom;
    QString nom;
    bool admin;
    bool current;

 public:


};

#endif // Etudiant_h

