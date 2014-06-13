#include "dao/Connexion.h"

QSqlDatabase Connexion::getDataBase() const{
    return db;
}


void Connexion::setConnexion(const QString& dbfile){
    LogWriter::write("Connection.cpp","Ajout de la base de données");
    db = QSqlDatabase::addDatabase("QSQLITE", "UTProfilerDatabase");
    db.setDatabaseName(dbfile);

    if(db.open()){
        LogWriter::write("Connexion.cpp","La connexion est active");
    }else{
        LogWriter::write("Connexion.cpp","La connexion a échoué");
    }
}
