#ifndef SEMESTREDAO_H
#define SEMESTREDAO_H


#include "dossier/Semestre.h"
#include "dao/SqlDAOTemplate.h"

class SemestreDAO : public SqlDAOTemplate<Semestre, SemestreDAO> {

    friend class Singleton<SemestreDAO>;

public:

    QMap<int, Semestre *> findAll();

    Semestre* find(const int &id);

    Semestre* findByLogin(const QString& login);

    bool update(const int& id, Semestre* obj);

    bool remove(const int& id, Semestre* obj);

    bool create(Semestre* obj);

    SemestreDAO(){}
    ~SemestreDAO(){}

};

#endif // SEMESTREDAO_H
