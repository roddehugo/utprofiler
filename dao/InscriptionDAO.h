#ifndef INSCRIPTIONDAO_H
#define INSCRIPTIONDAO_H

#include "dossier/Inscription.h"
#include "dao/SqlDAOTemplate.h"
#include "dossier/UV.h"
#include "dossier/Semestre.h"

class InscriptionDAO : public SqlDAOTemplate<Inscription, InscriptionDAO> {

    friend class Singleton<InscriptionDAO>;

public:

    QMap<int, Inscription *> findAll();

    Inscription* find(const int &id);

    Inscription* findByStr(const QString& str);

    bool update(Inscription* obj);

    bool remove(Inscription* obj);

    bool create(Inscription* obj);

    QStringList getStringListResultat();

    Inscription *findByUVandSemestre(UV *uv, Semestre *sem);
protected:

    InscriptionDAO(){}
    ~InscriptionDAO(){}

};

#endif // INSCRIPTIONDAO_H
