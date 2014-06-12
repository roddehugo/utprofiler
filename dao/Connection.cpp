#include "Connection.h"


void Connection::setConnection(){
    db = QSqlDatabase::addDatabase("QSQLITE", "UTProfilerDatabase");
    db.setDatabaseName("database.db");
}
