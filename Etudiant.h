#ifndef Etudiant_h
#define Etudiant_h

#include <QString>

class Etudiant
{

private:
   QString login;
   QString prenom;
   QString nom;
   bool admin;
   unsigned int id;


public:

    Etudiant(const unsigned int id, const QString& login, const QString& prenom, const QString& nom);
    Etudiant(const QString& login, const QString& prenom, const QString& nom);

    ~Etudiant();

    unsigned int ID() const;
    void setID(unsigned int value);

    QString getLogin() const;
    void setLogin(const QString &value);

    QString getPrenom() const;
    void setPrenom(const QString &value);

    QString getNom() const;
    void setNom(const QString &value);

    bool isAdmin() const;
    void setAdmin(bool value);
};

#endif // Etudiant_h

