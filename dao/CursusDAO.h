#ifndef CURSUSDAO_H
#define CURSUSDAO_H

#include "decorator/Creditable.h"
#include "decorator/Cursus.h"
#include "decorator/SP.h"
#include "decorator/TM.h"
#include "decorator/TSH.h"
#include "decorator/CS.h"
#include "dao/SqlDAOTemplate.h"
#include "dossier/Dossier.h"
#include <QStringList>

class Dossier;

class CursusDAO : public SqlDAOTemplate<Creditable, CursusDAO> {

    friend class Singleton<CursusDAO>;

public:

    QMap<int, Creditable *> findAll();

    Creditable* find(const int &id);

    Creditable* findByLogin(const QString& login);

    bool update(Creditable* obj);

    bool remove(Creditable* obj);

    bool create(Creditable* obj);

    QStringList getStringList(const QString colonne);

    CursusDAO(){}
    ~CursusDAO(){}

};

#endif // CURSUSDAO_H
