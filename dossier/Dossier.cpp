#include "Dossier.h"

Dossier::Dossier(const unsigned int id, const QString &titre, bool current, Etudiant *etudiant):
    id(id),
    titre(titre),
    current(current),
    etudiant(etudiant)
{

}

Dossier::Dossier(const QString &titre, bool current, Etudiant *etudiant):
    titre(titre),
    current(current),
    etudiant(etudiant)
{

}

Etudiant *Dossier::getEtudiant() const
{
    return etudiant;
}

void Dossier::setEtudiant(Etudiant *value)
{
    etudiant = value;
}
bool Dossier::isCurrent() const
{
    return current;
}

void Dossier::setCurrent(bool value)
{
    current = value;
}
QString Dossier::getTitre() const
{
    return titre;
}

void Dossier::setTitre(const QString &value)
{
    titre = value;
}
unsigned int Dossier::ID() const
{
    return id;
}

void Dossier::setID(unsigned int value)
{
    id = value;
}

