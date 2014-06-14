#ifndef DossierDAO_h
#define DossierDAO_h

#include "dossier/Dossier.h"
#include "dao/SqlDAOTemplate.h"

class DossierDAO : public SqlDAOTemplate<Dossier> {

public:

    DossierDAO();

    QMap<int, Dossier *> findAll();

    Dossier* find(const int& id);

    void update(const int& id, const Dossier& obj);

    void remove(const int& id, Dossier* obj);

    void create(const Dossier& obj);

    ~DossierDAO();

private:
    QSqlDatabase db;
};

#endif // DossierDAO_h

