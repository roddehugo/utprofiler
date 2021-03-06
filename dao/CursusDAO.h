#ifndef CURSUSDAO_H
#define CURSUSDAO_H

#include "dossier/Cursus.h"
#include "dao/SqlDAOTemplate.h"
#include "dossier/Dossier.h"
#include <QStringList>

class Dossier;
/**
 * @brief classe gestion cursus dans la base de données
 * @details 
 * 
 * @param colonne QString
 * @return 
 */
class CursusDAO : public SqlDAOTemplate<Cursus, CursusDAO> {

    friend class Singleton<CursusDAO>;

public:

    QMap<int, Cursus *> findAll();

    Cursus* find(const int &id);

    Cursus* findByCode(const QString& str);

    bool update(Cursus *obj);

    bool remove(Cursus* obj);

    bool create(Cursus* obj);

    QStringList getStringList(const QString colonne);

    QMap<QString,int> getEctsMap(const unsigned int id);

    QMap<QString, int> computePercent(unsigned int id);

protected:

    CursusDAO(){}
    ~CursusDAO(){}

};

#endif // CURSUSDAO_H
