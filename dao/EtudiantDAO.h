#ifndef ETUDIANTDAO_H
#define ETUDIANTDAO_H

#include "Etudiant.h"
#include "dao/SqlDAOTemplate.h"

class EtudiantDAO :public SqlDAOTemplate<Etudiant, EtudiantDAO> {

    friend class Singleton<EtudiantDAO>;
private:
    Etudiant* current;
public:

    QMap<int, Etudiant *> findAll();

    Etudiant* find(const int &id);

    Etudiant* findByLogin(const QString& login);

    bool update(Etudiant* obj);

    bool remove(Etudiant* obj);

    bool create(Etudiant* obj);

    Etudiant *getCurrent() const;
    void setCurrent(Etudiant *value);

protected:

    EtudiantDAO(){}
    ~EtudiantDAO(){}

};

#endif // ETUDIANTDAO_H

