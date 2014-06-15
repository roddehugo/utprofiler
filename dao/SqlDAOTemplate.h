#ifndef DAO_h
#define DAO_h

#include <QMap>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QMessageBox>
#include "writers/LogWriter.h"
#include "UTProfilerException.h"
#include "dao/Connexion.h"

template <class T, class DAO>
class SqlDAOTemplate : public Singleton<DAO> {

    friend class Singleton<DAO>;

public:

    virtual QMap<int, T*> findAll() =0;

    virtual T* find(const int& id) =0;

    virtual bool update(T* obj) =0;

    virtual bool remove(T* obj) =0;

    virtual bool create(T* obj) =0;

    QMap<int, T*> getMap() const{
        return Map;
    }
    void setMap(const QMap<int, T*> &value){
        Map = value;
    }

protected:
    SqlDAOTemplate(){}
    ~SqlDAOTemplate(){}

    QMap<int, T*> Map;

};


#endif // DAO_h
