#ifndef DossierDAO_h
#define DossierDAO_h

#include "dossier/Dossier.h"
#include "dao/SqlDAOTemplate.h"

class DossierDAO : public SqlDAOTemplate<Dossier, DossierDAO> {

    friend class Singleton<DossierDAO>;

public:

    QMap<int, Dossier *> findAll();

    Dossier* find(const int& id);

    bool update(const int& id, Dossier* obj);

    bool remove(const int& id, Dossier* obj);

    bool create(Dossier* obj);

    ~DossierDAO(){}
    DossierDAO(){}

private:
    QMap<int, UV *> dossiermap;
};

#endif // DossierDAO_h

