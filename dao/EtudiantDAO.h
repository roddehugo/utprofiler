#ifndef ETUDIANTDAO_H
#define ETUDIANTDAO_H

#include "Etudiant.h"
#include "dao/SqlDAOTemplate.h"

class EtudiantDAO : public SqlDAOTemplate<Etudiant, EtudiantDAO> {

    friend class Singleton<EtudiantDAO>;

public:

    QMap<int, Etudiant *> findAll();

    Etudiant* find(const int &id);

    void update(const int& id, const Etudiant& obj);

    void remove(const int& id, Etudiant* obj);

    void create(const Etudiant& obj);

    EtudiantDAO();
    ~EtudiantDAO();

private:
    QMap<int, Etudiant *> etumap;
};

#endif // ETUDIANTDAO_H

