#ifndef SEMESTREDAO_H
#define SEMESTREDAO_H


#include "dossier/Semestre.h"
#include "dao/SqlDAOTemplate.h"
#include "dao/DossierDAO.h"

class SemestreDAO : public SqlDAOTemplate<Semestre, SemestreDAO> {

    friend class Singleton<SemestreDAO>;

public:

    QMap<int, Semestre *> findAll();

    Semestre* find(const int &id);

    Semestre* findByLogin(const QString& login);

    bool update(Semestre* obj);

    bool remove(Semestre* obj);

    bool create(Semestre* obj);

    QStringList getStringListSaison();
    QStringList getStringListAnnee();


protected:

    SemestreDAO(){}
    ~SemestreDAO(){}

};

#endif // SEMESTREDAO_H
