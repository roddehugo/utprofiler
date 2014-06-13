#include "dao/Connexion.h"
#include <QDebug>

QSqlDatabase Connexion::getDataBase() const{
    return db;
}


void Connexion::setConnexion(const QString& dbfile){
    LogWriter::writeln("Connection.cpp","Ajout de la base de données");
    db = QSqlDatabase::addDatabase("QSQLITE", "UTProfilerDatabase");
    db.setDatabaseName(dbfile);

    if(db.open()){
        LogWriter::writeln("Connexion.cpp","La connexion est active");
    }else{
        LogWriter::writeln("Connexion.cpp","La connexion a échoué");
    }
}
