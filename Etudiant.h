#ifndef Etudiant_h
#define Etudiant_h

#include <QString>

class Etudiant
{

private:
   unsigned int id;
   QString login;
   QString prenom;
   QString nom;


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
};

#endif // Etudiant_h

