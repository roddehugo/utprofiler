#ifndef DAO_h
#define DAO_h

#include <QMap>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include "writers/LogWriter.h"
#include "UTProfilerException.h"
#include "dao/Connexion.h"

template <class T, class DAO>
class SqlDAOTemplate : public Singleton<DAO> {

    friend class Singleton<DAO>;

 public:

    virtual QMap<int,T*> findAll() =0;

    virtual T* find(const int& id) =0;

    virtual bool update(const int& id, T* obj) =0;

    virtual bool remove(const int& id, T* obj) =0;

    virtual bool create(T* obj) =0;

protected:
    SqlDAOTemplate(){}

    ~SqlDAOTemplate(){}

};


#endif // DAO_h

