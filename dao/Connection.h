#ifndef Connection_h
#define Connection_h

#include <QSqlDatabase>
#include "Singleton.h"

class Connection : public Singleton<Connection> {

    friend class Singleton<Connection>;

 public:
    const QSqlDatabase& getDataBase(){return db;}
    void setConnection();

 private:
    QSqlDatabase db;

};

#endif // Connection_h

