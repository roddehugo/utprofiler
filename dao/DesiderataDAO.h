#ifndef DESIDERATADAO_H
#define DESIDERATADAO_H

#include "dossier/Desiderata.h"
#include "dao/SqlDAOTemplate.h"
#include "dao/DossierDAO.h"
#include "dao/UVDAO.h"

class DesiderataDAO : public SqlDAOTemplate<Desiderata, DesiderataDAO> {

    friend class Singleton<DesiderataDAO>;

public:

    QMap<int, Desiderata *> findAll();

    Desiderata* find(const int &id);

    Desiderata* findByLogin(const QString& login);

    bool update(Desiderata* obj);

    bool remove(Desiderata* obj);

    bool create(Desiderata* obj);

protected:

    DesiderataDAO(){}
    ~DesiderataDAO(){}

};

#endif // DESIDERATADAO_H
