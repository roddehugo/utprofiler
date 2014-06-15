#ifndef CATEGORIEDAO_H
#define CATEGORIEDAO_H

#include "dao/SqlDAOTemplate.h"

class CategorieDAO : public Singleton<CategorieDAO>{
    friend class Singleton<QString>;

public:

    QMap<int, QString> findAll();

    QString* find(const int &id);

    bool update(QString str);

    bool remove(QString str);

    bool create(QString str);

    int findByString(QString str);

    CategorieDAO(){}
    ~CategorieDAO(){}

};




















#endif // CATEGORIEDAO_H
