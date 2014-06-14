#ifndef DESIDERATADAO_H
#define DESIDERATADAO_H

#include "dossier/Desiderata.h"
#include "dao/SqlDAOTemplate.h"

class DesiderataDAO : public SqlDAOTemplate<Desiderata, DesiderataDAO> {

    friend class Singleton<DesiderataDAO>;

public:

    QMap<int, Desiderata *> findAll();

    Desiderata* find(const int &id);

    Desiderata* findByLogin(const QString& login);

    bool update(const int& id, Desiderata* obj);

    bool remove(const int& id, Desiderata* obj);

    bool create(Desiderata* obj);

    DesiderataDAO(){}
    ~DesiderataDAO(){}

};

#endif // DESIDERATADAO_H
