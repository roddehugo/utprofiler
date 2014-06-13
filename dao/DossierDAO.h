#ifndef DossierDAO_h
#define DossierDAO_h

#include "dao/SqlDAOTemplate.h"
#include "dossier/Dossier.h"

class DossierDAO : public SqlDAOTemplate<Dossier>
{

public:

    DossierDAO();

    QMap<int, Dossier *> findAll();

    Dossier* find(const unsigned int& id);

    void update(const Dossier& obj);

    void remove(const Dossier& obj);

    void create(const Dossier& obj);

    ~DossierDAO();

private:
    QSqlDatabase db;
};

#endif // DossierDAO_h

