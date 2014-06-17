#ifndef INSCRIPTIONDAO_H
#define INSCRIPTIONDAO_H

#include "dossier/Inscription.h"
#include "dao/SqlDAOTemplate.h"
#include "dossier/UV.h"
#include "dossier/Semestre.h"
/**
 * @brief classe manage inscription dans la BDD
 * @details 
 * @return 
 */
class InscriptionDAO : public SqlDAOTemplate<Inscription, InscriptionDAO> {

    friend class Singleton<InscriptionDAO>;

public:

    QMap<int, Inscription *> findAll();

    QList<Semestre *> findSemestresByDossier(const int dossier);

    QList<UV *> findUvsBySemestre(const int semestre);

    Inscription* find(const int &id);

    Inscription* findByStr(const QString& str);

    bool update(Inscription* obj);

    bool remove(Inscription* obj);

    bool create(Inscription* obj);

    QStringList getStringListResultat();

    QString getResultat(unsigned int dossier, unsigned int semestre, unsigned int uv);

protected:

    InscriptionDAO(){}
    ~InscriptionDAO(){}

};

#endif // INSCRIPTIONDAO_H
