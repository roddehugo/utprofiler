#ifndef UVDAO_h
#define UVDAO_h

#include "decorator/UV.h"
#include "dao/SqlDAOTemplate.h"

class UVDAO : public SqlDAOTemplate<UV> {

public:

    UVDAO();

    QMap<int, UV *> findAll();

    UV* find(const int &id);

    void update(const int& id, const UV& obj);

    void remove(const int& id, UV* obj);

    void create(const UV& obj);

    ~UVDAO();

private:
    //QSqlDatabase db;
    QMap<int, UV *> uvmap;
};

#endif // UVDAO_h

