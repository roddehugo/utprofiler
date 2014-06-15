#include "Dossier.h"

Dossier::Dossier(const unsigned int id, const QString &titre, bool solution, Etudiant *etudiant):
    id(id),
    titre(titre),
    solution(solution),
    etudiant(etudiant)
{

}

Dossier::Dossier(const QString &titre, bool solution, Etudiant *etudiant):
    titre(titre),
    solution(solution),
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
bool Dossier::isSolution() const
{
    return solution;
}

void Dossier::setSolution(bool value)
{
    solution = value;
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

