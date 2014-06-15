#ifndef CATEGORIEDAO_H
#define CATEGORIEDAO_H

#include "dao/SqlDAOTemplate.h"
#include "decorator/Creditable.h"
#include "decorator/CS.h"
#include "decorator/TM.h"
#include "decorator/TSH.h"
#include "decorator/SP.h"

class CategorieDAO : public SqlDAOTemplate<Creditable,CategorieDAO>{
    friend class Singleton<CategorieDAO>;

public:

    QMap<int, Creditable *> findAll();

    Creditable* find(const int &id);

    bool update(Creditable* obj);

    bool remove(Creditable* obj);

    bool create(Creditable* obj);

    Creditable* parse(const QString& code,const QString& titre,const unsigned int& ects,const Creditable& creditable);

    CategorieDAO(){}
    ~CategorieDAO(){}

};




















#endif // CATEGORIEDAO_H
