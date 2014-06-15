#include "dao/EtudiantDAO.h"
#include <QDebug>


Etudiant *EtudiantDAO::getCurrent() const
{
    return current;
}

void EtudiantDAO::setCurrent(Etudiant *value)
{
    current = value;
}

QMap<int, Etudiant*> EtudiantDAO::findAll(){
    try{

        QSqlQuery query(Connexion::getInstance()->getDataBase());
        if (!query.exec("SELECT * FROM etudiants;")){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }

        while (query.next()){
            QSqlRecord rec = query.record();
            const int id = rec.value("id").toInt();
            const QString p = rec.value("prenom").toString();
            const QString n = rec.value("nom").toString();
            const QString l = rec.value("login").toString();
            if (Map.contains(id)) {
                throw UTProfilerException("L'étudiant "+l+" existe déjà dans la QMap");
            }else{
                LogWriter::writeln("EtudiantDAO.cpp","Lecture de l'étudiant : " + l);
                Etudiant* newetu=new Etudiant(l,p,n);
                Map.insert(id,newetu);
            }
        }
    }catch(UTProfilerException *e){
        LogWriter::writeln("EtudiantDAO::findAll()",e->getMessage());
    }

    return Map;
}

Etudiant* EtudiantDAO::findByLogin(const QString& login){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        if (!query.exec("SELECT * FROM etudiants WHERE login = '" + login + "' ;")){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }

        if(query.first()){
            QSqlRecord rec = query.record();
            const int id = rec.value("id").toInt();
            if (Map.value(id)) {
                return Map.value(id);
            }else{
                const QString l = rec.value("login").toString();
                const QString p = rec.value("prenom").toString();
                const QString n = rec.value("nom").toString();
                LogWriter::writeln("EtudiantDAO.cpp","Lecture de l'étudiant : " + l);
                return new Etudiant(l,p,n);
            }
        }else{
            return NULL;
        }
    }catch(UTProfilerException *e){
        LogWriter::writeln("EtudiantDAO::findByLogin()",e->getMessage());
    }
}


Etudiant* EtudiantDAO::find(const int& id){
    try{
        if (Map.contains(id)) {
            return Map.value(id);
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
            LogWriter::writeln("EtudiantDAO.cpp","Lecture de l'étudiant : " + l);
            return new Etudiant(l,p,n);
        }
    }catch(UTProfilerException *e){
        LogWriter::writeln("EtudiantDAO::find()",e->getMessage());
    }
}

bool EtudiantDAO::update(const int& id, Etudiant *obj){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("UPDATE etudiants SET (login=:login, prenom=:prenom, nom=:nom) WHERE id = :id ;");
        query.bindValue(":id", id);
        query.bindValue(":login", obj->getLogin() );
        query.bindValue(":prenom", obj->getPrenom() );
        query.bindValue(":nom", obj->getNom() );
        if (!query.exec()){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
            return false;
        }else{
            LogWriter::writeln("EtudiantDAO.cpp","Lecture de l'étudiant : " + obj->getLogin());
            return true;
        }
    }catch(UTProfilerException *e){
        LogWriter::writeln("EtudiantDAO::update()",e->getMessage());
    }
}

bool EtudiantDAO::remove(const int& id, Etudiant* obj){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("DELETE FROM etudiants WHERE id = :id ;");
        query.bindValue(":id", id);
        if (!query.exec()){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
            return false;
        }else{
            LogWriter::writeln("EtudiantDAO.cpp","Suprression de l'étudiant : " + obj->getLogin());
            delete obj;
            return true;
        }
    }catch(UTProfilerException *e){
        LogWriter::writeln("EtudiantDAO::remove()",e->getMessage());
    }
}

bool EtudiantDAO::create(Etudiant *obj){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("INSERT INTO etudiants (id, login, prenom, nom, admin) VALUES (NULL, :login, :prenom, :nom, 1);");
        query.bindValue(":login", obj->getLogin() );
        query.bindValue(":prenom", obj->getPrenom() );
        query.bindValue(":nom", obj->getNom() );
        if (!query.exec()){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
            return false;
        }else{
            Map.insert(query.lastInsertId().toInt(),obj);
            LogWriter::writeln("Etudiant.cpp","Création de l'étudiant : " + obj->getLogin());
            return true;
        }
    }catch(UTProfilerException *e){
        LogWriter::writeln("EtudiantDAO::create()",e->getMessage());
    }
}

