#ifndef UVDAO_h
#define UVDAO_h

#include "decorator/UV.h"
#include "dao/SqlDAOTemplate.h"

class UVDAO : public SqlDAOTemplate<UV, UVDAO> {

    friend class Singleton<UVDAO>;

public:

    QMap<int, UV *> findAll();

    UV* find(const int &id);

    bool update(const int& id, UV* obj);

    bool remove(const int& id, UV* obj);

    bool create(UV* obj);

    ~UVDAO(){}
    UVDAO(){}

private:
    QMap<int, UV *> uvmap;
};

#endif // UVDAO_h

