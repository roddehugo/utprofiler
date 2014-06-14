#ifndef ETUDIANTDAO_H
#define ETUDIANTDAO_H

#include "Etudiant.h"
#include "dao/SqlDAOTemplate.h"

class EtudiantDAO : public SqlDAOTemplate<Etudiant, EtudiantDAO> {

    friend class Singleton<EtudiantDAO>;

public:

    QMap<int, Etudiant *> findAll();

    Etudiant* find(const int &id);

    Etudiant* findByLogin(const QString& login);

    bool update(const int& id, Etudiant* obj);

    bool remove(const int& id, Etudiant* obj);

    bool create(Etudiant* obj);

    EtudiantDAO(){}
    ~EtudiantDAO(){}

};

#endif // ETUDIANTDAO_H

