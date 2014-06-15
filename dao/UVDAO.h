#ifndef UVDAO_h
#define UVDAO_h

#include "decorator/Creditable.h"
#include "decorator/UV.h"
#include "decorator/SP.h"
#include "decorator/TM.h"
#include "decorator/TSH.h"
#include "decorator/CS.h"
#include "dao/SqlDAOTemplate.h"

class UVDAO : public SqlDAOTemplate<Creditable, UVDAO> {

    friend class Singleton<UVDAO>;

public:

    QMap<int, Creditable *> findAll();

    Creditable *find(const int &id);

    bool update(Creditable* obj);

    bool remove(Creditable* obj);

    bool create(Creditable* obj);

    Creditable* parse(const int cid, const QString& ctitre, const int ects,Creditable* cre );

    ~UVDAO(){}
    UVDAO(){}
};

#endif // UVDAO_h

