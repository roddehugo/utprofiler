#include "dao/DesiderataDAO.h"

QMap<int, Desiderata *> DesiderataDAO::findAll(){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        if (!query.exec("SELECT * FROM desiderata;")){
            throw UTProfilerException("La requête a échoué : " + query.lastQuery());
        }

        while (query.next()){
            QSqlRecord rec = query.record();
            const unsigned int id = rec.value("id").toInt();
            const QString t = rec.value("type").toString();
            const unsigned int uv = rec.value("uv").toInt();
            const unsigned int d = rec.value("dossier").toInt();

            if (Map.contains(id)) {
                throw UTProfilerException("La desiderata " + QString::number(id) + " existe déjà dans la QMap");
            }else{
                LogWriter::writeln("Desiderata.cpp","Lecture du desiderata : " + QString::number(id));
                Dossier* dossier = DossierDAO::getInstance()->find(d);
                UV* newuv = UVDAO::getInstance()->find(uv);
                Desiderata* newd =new Desiderata(id,Desiderata::str2typeD(t),dossier,newuv);
                Map.insert(id,newd);

            }
        }
        return Map;


    }
    catch(UTProfilerException e){
        LogWriter::writeln("DesiderataDAO::findAll()",e.getMessage());
    }
}

Desiderata* DesiderataDAO::find(const int& id){
    try{
        if (Map.contains(id)) {
            return Map.value(id);
        }
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        if (!query.exec("SELECT * FROM desiderata WHERE id = " + QString(id) + ";")){
            throw UTProfilerException("La requete a échoué : " + query.lastQuery());
        }
        if(query.first()){
            QSqlRecord rec = query.record();
            const unsigned int id = rec.value("id").toInt();
            const QString t = rec.value("type").toString();
            const unsigned int uv = rec.value("uv").toInt();
            const unsigned int d = rec.value("dossier").toInt();

            LogWriter::writeln("Desiderata.cpp","Lecture du desiderata : " + QString::number(id));
            Dossier* dossier = DossierDAO::getInstance()->find(d);
            UV* newuv = UVDAO::getInstance()->find(uv);
            Desiderata* newd =new Desiderata(id,Desiderata::str2typeD(t),dossier,newuv);

            Map.insert(id,newd);
            return newd;
        }else{
            throw UTProfilerException("La requete a échoué : " + query.lastQuery());
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("DesiderataDAO::find()",e.getMessage());
    }
}

bool DesiderataDAO::update(Desiderata* obj){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("UPDATE desiderata SET (type=:type, uv=:uv, dossier=:dossier) WHERE id = :id ;");
        query.bindValue(":id", obj->getId());
        query.bindValue(":type", obj->getType() );
        query.bindValue(":uv", obj->getUv()->ID() );
        query.bindValue(":dossier", obj->getMyDossier()->ID() );
        if (!query.exec()){
            throw UTProfilerException("La requete a échoué : " + query.lastQuery());
            return false;
        }else{
            LogWriter::writeln("DesiderataDAO.cpp","Modification des desiderata : " + QString::number(obj->getId()) );
            return true;
        }

    }catch(UTProfilerException e){
        LogWriter::writeln("Desiderata::update()",e.getMessage());
    }
}

bool DesiderataDAO::remove(Desiderata* obj){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("DELETE FROM desiderata WHERE id = :id ;");
        query.bindValue(":id", obj->getId());
        if (!query.exec()){
            throw UTProfilerException("La requete a échoué : " + query.lastQuery());
            return false;
        }else{
            LogWriter::writeln("Desiderata.cpp","Suppression du desiderata : " + QString::number(obj->getId()));
            Map.erase(Map.find(obj->getId()));
            return true;
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("DesiderataDAO::remove()",e.getMessage());
    }
}

bool DesiderataDAO::create(Desiderata* obj){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("INSERT INTO desiderata (id, type,uv, dossier) VALUES (NULL, :type, :uv, :dossier);");
        query.bindValue(":type", Desiderata::typeD2str(obj->getType()) );
        query.bindValue(":uv", obj->getUv()->ID() );
        query.bindValue(":dossier", obj->getMyDossier()->ID() );
        if (!query.exec()){
            throw UTProfilerException("La requête a échoué : " + query.lastQuery());
            return false;
        }else{
            int i=query.lastInsertId().toInt();
            Map.insert(i,obj);
            LogWriter::writeln("Desiderata.cpp","Création du desiderata : " + QString::number(obj->getId()));
            return true;
        }

    }catch(UTProfilerException e){
        LogWriter::writeln("Desiderata::create()",e.getMessage());
    }
}
