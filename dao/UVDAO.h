#ifndef UVDAO_h
#define UVDAO_h

#include "decorator/UV.h"
#include <dao/SqlDAOTemplate.h>

class UVDAO : public SqlDAOTemplate<UV> {

public:

    UVDAO();

    QMap<int, UV *> findAll();

    UV* find(const unsigned int& id);

    void update(const UV& obj);

    void remove(const UV& obj);

    void create(const UV& obj);

    ~UVDAO();

private:
    QSqlDatabase db;

};

#endif // UVDAO_h

