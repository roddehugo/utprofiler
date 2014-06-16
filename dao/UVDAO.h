#ifndef UVDAO_h
#define UVDAO_h

#include "dossier/UV.h"
#include "dao/SqlDAOTemplate.h"
#include "dao/CategorieDAO.h"
#include "dao/CursusDAO.h"

#include <QStringList>

class UVDAO : public SqlDAOTemplate<UV, UVDAO> {

    friend class Singleton<UVDAO>;

public:

    QMap<int, UV *> findAll();

    UV *find(const int &id);

    bool update(UV* obj);

    bool remove(UV* obj);

    bool create(UV* obj);

    QStringList getStringList(const QString& colonne);

    QMap<QString, int> getEctsMap(unsigned int id);

    QMap<QString, bool> getCursusMap(unsigned int id);

    QList<Cursus*> getCursusList(unsigned int id);

protected:

    ~UVDAO(){}

    UVDAO(){}

private:



};

#endif // UVDAO_h

