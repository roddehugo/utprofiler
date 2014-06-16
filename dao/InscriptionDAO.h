#ifndef INSCRIPTIONDAO_H
#define INSCRIPTIONDAO_H

#include "dossier/Inscription.h"
#include "dao/SqlDAOTemplate.h"

class InscriptionDAO : public SqlDAOTemplate<Inscription, InscriptionDAO> {

    friend class Singleton<InscriptionDAO>;

public:

    QMap<int, Inscription *> findAll();

    Inscription* find(const int &id);

    Inscription* findByLogin(const QString& login);

    bool update(Inscription* obj);

    bool remove(Inscription* obj);

    bool create(Inscription* obj);

    QStringList getStringListResultat();


protected:

    InscriptionDAO(){}
    ~InscriptionDAO(){}

};

#endif // INSCRIPTIONDAO_H
