#ifndef DossierDAO_h
#define DossierDAO_h

#include "dossier/Dossier.h"
#include "dao/SqlDAOTemplate.h"

class DossierDAO : public SqlDAOTemplate<Dossier, DossierDAO> {

    friend class Singleton<DossierDAO>;

public:

    QMap<int, Dossier *> findAll();

    Dossier* find(const int& id);

    void update(const int& id, const Dossier& obj);

    void remove(const int& id, Dossier* obj);

    void create(const Dossier& obj);

    ~DossierDAO(){}
    DossierDAO(){}

private:
    QMap<int, UV *> dossiermap;
};

#endif // DossierDAO_h

