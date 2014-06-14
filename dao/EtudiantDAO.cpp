#include "dao/EtudiantDAO.h"

EtudiantDAO::EtudiantDAO(){}

EtudiantDAO::~EtudiantDAO(){}

QMap<int, Etudiant *> EtudiantDAO::findAll(){
    QSqlQuery query(Connexion::getInstance()->getDataBase());
    if (!query.exec("SELECT * FROM etudiants ORDER BY login;")){
        throw UTProfilerException("La requète a échoué : " + query.lastQuery());
    }

    while (query.next()){
        QSqlRecord rec = query.record();
        const int id = rec.value("id").toInt();
        const QString p = rec.value("prenom").toString();
        const QString n = rec.value("nom").toString();
        const QString l = rec.value("login").toString();
        if (etumap.contains(id)) {
            throw UTProfilerException("L'étudiant "+l+" existe déjà dans la QMap");
        }else{
            LogWriter::writeln("EtudiantDAO.cpp","Lecture de l'étudiant : " + l);
            Etudiant* newetu=new Etudiant(l,p,n);
            etumap.insert(id,newetu);
        }
    }

    return etumap;
}

Etudiant* EtudiantDAO::find(const int& id){
    if (etumap.contains(id)) {
        return etumap.value(id);
    }
    QSqlQuery query(Connexion::getInstance()->getDataBase());
    if (!query.exec("SELECT * FROM etudiants WHERE id = " + QString(id) + ";")){
        throw UTProfilerException("La requète a échoué : " + query.lastQuery());
    }
    if(query.first()){
        QSqlRecord rec = query.record();
        const QString l = rec.value("login").toString();
        const QString p = rec.value("prenom").toString();
        const QString n = rec.value("nom").toString();
        LogWriter::writeln("EtudiantDAO.cpp","Lecture de l'UV : " + l);
        return new Etudiant(l,p,n);
    }
}

void EtudiantDAO::update(const int& id, const Etudiant& obj){
    QSqlQuery query(Connexion::getInstance()->getDataBase());
    query.prepare("UPDATE etudiants SET (login=:login, prenom=:prenom, nom=:nom) WHERE id = :id ;");
    query.bindValue(":id", id);
    query.bindValue(":login", obj.getLogin() );
    query.bindValue(":prenom", obj.getPrenom() );
    query.bindValue(":nom", obj.getNom() );
    if (!query.exec()){
        throw UTProfilerException("La requète a échoué : " + query.lastQuery());
    }else{
        LogWriter::writeln("EtudiantDAO.cpp","Lecture de l'UV : " + obj.getLogin());
    }

}

void EtudiantDAO::remove(const int& id, Etudiant* obj){
    QSqlQuery query(Connexion::getInstance()->getDataBase());
    query.prepare("DELETE FROM etudiants WHERE id = :id ;");
    query.bindValue(":id", id);
    if (!query.exec()){
        throw UTProfilerException("La requète a échoué : " + query.lastQuery());
    }else{
        LogWriter::writeln("EtudiantDAO.cpp","Suprression de l'étudiant : " + obj->getLogin());
        delete obj;
   }
}

void EtudiantDAO::create(const Etudiant& obj){
    QSqlQuery query(Connexion::getInstance()->getDataBase());
    query.prepare("INSERT INTO etudiants (id, login, prenom, nom) VALUES (:id, :login, :prenom, :nom);");
    query.bindValue(":id", "NULL");
    query.bindValue(":login", obj.getLogin() );
    query.bindValue(":prenom", obj.getPrenom() );
    query.bindValue(":nom", obj.getNom() );
    if (!query.exec()){
        throw UTProfilerException("La requète a échoué : " + query.lastQuery());
    }else{
        LogWriter::writeln("Etudiant.cpp","Création de l'étudiant : " + obj.getLogin());
    }
}

