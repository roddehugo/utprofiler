#ifndef CURSUSDAO_H
#define CURSUSDAO_H

#include "dossier/Cursus.h"
#include "dao/SqlDAOTemplate.h"
#include "dossier/Dossier.h"

class Dossier;

class CursusDAO : public SqlDAOTemplate<Cursus, CursusDAO> {

    friend class Singleton<CursusDAO>;

public:

    QMap<int, Cursus *> findAll();

    Cursus* find(const int &id);

    Cursus* findByLogin(const QString& login);

    bool update(Cursus *obj);

    bool remove(Cursus* obj);

    bool create(Cursus* obj);

    CursusDAO(){}
    ~CursusDAO(){}

};

#endif // CURSUSDAO_H
