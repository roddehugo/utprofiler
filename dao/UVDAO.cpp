#include "dao/UVDAO.h"

QMap<int, UV *> UVDAO::findAll(){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        if (!query.exec("SELECT * FROM uvs ORDER BY code;")){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }

        while (query.next()){
            QSqlRecord rec = query.record();
            const int id = rec.value("id").toInt();
            const QString c = rec.value("code").toString();
            const QString t = rec.value("titre").toString();
            const bool a = rec.value("automne").toBool();
            const bool p = rec.value("printemps").toBool();
            const bool d = rec.value("demiuv").toBool();
            if (Map.contains(id)) {
                throw UTProfilerException("L'UV "+c+" existe déjà dans la QMap");
            }else{
                LogWriter::writeln("UVDAO.cpp","Lecture de l'UV : " + c);
                UV* newuv=new UV(id,c,t,p,a,d);
                Map.insert(id,newuv);
            }
        }

        return Map;
    }catch(UTProfilerException e){
        LogWriter::writeln("UVDAO::findAll()",e.getMessage());
    }
}

UV* UVDAO::find(const int& id){
    try{
        if (Map.contains(id)) {
            return Map.value(id);
        }
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        if (!query.exec("SELECT * FROM uvs WHERE id = " + QString(id) + ";")){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }
        if(query.first()){
            QSqlRecord rec = query.record();
            const QString c = rec.value("code").toString();
            const QString t = rec.value("titre").toString();
            const bool a = rec.value("automne").toBool();
            const bool p = rec.value("printemps").toBool();
            const bool d = rec.value("demiuv").toBool();
            LogWriter::writeln("UVDAO.cpp","Lecture de l'UV : " + c);
            UV* newuv = new UV(id,c,t,p,a,d);
            Map.insert(id,newuv);
            return newuv;
        }else{
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("UVDAO::find()",e.getMessage());
    }
}

bool UVDAO::update(UV* obj){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("UPDATE uvs SET (code=:code, titre=:titre, categorie=:categorie, automne=:automne, printemps=:printemps, demiuv=:demiuv) WHERE id = :id ;");
        query.bindValue(":id", obj->ID());
        query.bindValue(":code", obj->getCode() );
        query.bindValue(":titre", obj->getTitre() );
        query.bindValue(":automne", obj->isAutomne() );
        query.bindValue(":printemps", obj->isPrintemps() );
        query.bindValue(":demiuv", obj->isDemiUV() );
        if (!query.exec()){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
            return false;
        }else{
            LogWriter::writeln("UVDAO.cpp","Modification de l'UV : " + obj->getCode());
            return true;
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("UVDAO::update()",e.getMessage());
    }

}

bool UVDAO::remove(UV* obj){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("DELETE FROM uvs WHERE id = :id ;");
        query.bindValue(":id", obj->ID());
        if (!query.exec()){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
            return false;
        }else{
            LogWriter::writeln("UVDAO.cpp","Suprression de l'UV : " + obj->getCode());
            Map.erase(Map.find(obj->ID()));
            return true;
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("UVDAO::remove()",e.getMessage());
    }
}

bool UVDAO::create(UV *obj){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("INSERT INTO uvs (id, code, titre, categorie, automne, printemps, demiuv) VALUES (NULL, :code, :titre, :categorie, :automne, :printemps, :demiuv);");
        query.bindValue(":code", obj->getCode() );
        query.bindValue(":titre", obj->getTitre() );
        query.bindValue(":automne", obj->isAutomne() );
        query.bindValue(":printemps", obj->isPrintemps() );
        query.bindValue(":demiuv", obj->isDemiUV() );
        if (!query.exec()){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
            return false;
        }else{
            int id = query.lastInsertId().toInt();
            obj->setID(id);
            Map.insert(id,obj);
            LogWriter::writeln("UVDAO.cpp","Création de l'UV : " + obj->getCode());
            return true;
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("UVDAO::create()",e.getMessage());
    }
}
