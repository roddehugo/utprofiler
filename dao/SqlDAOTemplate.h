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

template <class T>
class SqlDAOTemplate {

 public:

    SqlDAOTemplate();

    virtual QMap<int,T*> findAll() =0;

    virtual T* find(const int& id) =0;

    virtual void update(const int& id, const T& obj) =0;

    virtual void remove(const int& id, T* obj) =0;

    virtual void create(const T& obj) =0;

    virtual ~SqlDAOTemplate();

};

template <class T>
SqlDAOTemplate<T>::SqlDAOTemplate() {}

template <class T>
SqlDAOTemplate<T>::~SqlDAOTemplate() {}

#endif // DAO_h

