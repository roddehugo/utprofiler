#ifndef UVDAO_h
#define UVDAO_h

#include "dossier/UV.h"
#include "dao/SqlDAOTemplate.h"
#include "dao/CategorieDAO.h"

class UVDAO : public SqlDAOTemplate<UV, UVDAO> {

    friend class Singleton<UV>;

public:

    QMap<int, UV *> findAll();

    UV *find(const int &id);

    bool update(UV* obj);

    bool remove(UV* obj);

    bool create(UV* obj);

    ~UVDAO(){}
    UVDAO(){}
};

#endif // UVDAO_h

