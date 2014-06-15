#include "Etudiant.h"

Etudiant::Etudiant(const unsigned int id, const QString &login, const QString &prenom, const QString &nom):
    id(id),
    login(login),
    prenom(prenom),
    nom(nom)
{

}

Etudiant::Etudiant(const QString &login, const QString &prenom, const QString &nom):
    login(login),
    prenom(prenom),
    nom(nom)
{

}

Etudiant::~Etudiant()
{

}

unsigned int Etudiant::ID() const
{
    return id;
}

void Etudiant::setID(unsigned int value)
{
    id = value;
}

QString Etudiant::getPrenom() const
{
    return prenom;
}

void Etudiant::setPrenom(const QString &value)
{
    prenom = value;
}

QString Etudiant::getNom() const
{
    return nom;
}

void Etudiant::setNom(const QString &value)
{
    nom = value;
}

bool Etudiant::isAdmin() const
{
    return admin;
}

void Etudiant::setAdmin(bool value)
{
    admin = value;
}

QString Etudiant::getLogin() const
{
    return login;
}

void Etudiant::setLogin(const QString &value)
{
    login = value;
}

