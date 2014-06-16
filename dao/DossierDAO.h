#ifndef DossierDAO_h
#define DossierDAO_h

#include "dossier/Dossier.h"
#include "dao/SqlDAOTemplate.h"

class DossierDAO : public SqlDAOTemplate<Dossier, DossierDAO> {

    friend class Singleton<DossierDAO>;

public:

    QMap<int, Dossier *> findAll();

    Dossier* find(const int& id);

    bool update(Dossier* obj);

    bool remove(Dossier* obj);

    bool create(Dossier* obj);

protected:

    ~DossierDAO(){}
    DossierDAO(){}

};

#endif // DossierDAO_h

