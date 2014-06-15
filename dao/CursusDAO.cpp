#include "CursusDAO.h"

QMap<int, Cursus *> CursusDAO::findAll(){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        if (!query.exec("SELECT * FROM cursus;")){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }

        while (query.next()){
            QSqlRecord rec = query.record();
            const int id = rec.value("id").toInt();
            const QString c = rec.value("code").toString();
            const QString t = rec.value("titre").toString();
            const int maxSem = rec.value("maxsemestres").toInt();
            const int ects = rec.value("ects").toInt();
            const int cur = rec.value("current").toBool();
            const int p = rec.value("parent").toInt();
            const int d = rec.value("dossier").toInt();
            if (Map.contains(id)) {
                throw UTProfilerException("Le cursus "+c+" existe déjà dans la QMap");
            }else{
                LogWriter::writeln("Cursus.cpp","Lecture du cursus : " + c);
//                Dossier* dossier = DossierDAO::getInstance()->find(d);
//                Cursus* cursus;
//                if(parent != 0){
//                    Cursus* par = find(p);
//                    cursus=new Cursus(id,c,t,ects,maxSem,cur,dossier,par);
//                }else{
//                    cursus=new Cursus(id,c,t,ects,maxSem,cur,dossier,NULL);
//                }
//                Map.insert(id,cursus);
            }
        }

        return Map;
    }catch(UTProfilerException e){
        LogWriter::writeln("Cursus::findAll()",e.getMessage());
    }
}

Cursus* CursusDAO::find(const int& id){
    try{
        if (Map.contains(id)) {
            return Map.value(id);
        }
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        if (!query.exec("SELECT * FROM cursus WHERE id = " + QString(id) + ";")){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }
        if(query.first()){
            QSqlRecord rec = query.record();
            const int id = rec.value("id").toInt();
            const QString c = rec.value("code").toString();
            const QString t = rec.value("titre").toString();
            const int maxSem = rec.value("maxsemestres").toInt();
            const int ects = rec.value("ects").toInt();
            const int cur = rec.value("current").toBool();
            const int p = rec.value("parent").toInt();
            const int d = rec.value("dossier").toInt();
            LogWriter::writeln("Cursus.cpp","Lecture du cursus : " + c);
//                Dossier* dossier = DossierDAO::getInstance()->find(d);
//                Cursus* cursus;
//                if(parent != 0){
//                    Cursus* par = find(p);
//                    cursus=new Cursus(id,c,t,ects,maxSem,cur,dossier,par);
//                }else{
//                    cursus=new Cursus(id,c,t,ects,maxSem,cur,dossier,NULL);
//                }
//                Map.insert(id,cursus);
        }else{
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("Cursus::find()",e.getMessage());
    }
}

bool CursusDAO::update(Cursus* obj){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("UPDATE cursus SET (code=:code, titre=:titre, maxsemestres=:maxSem, ects=:ects, current=:current, parent=:parent, dossier:dossier) WHERE id = :id ;");
        query.bindValue(":id", obj->ID());
        query.bindValue(":code", obj->getCode() );
        query.bindValue(":titre", obj->getTitre() );
        query.bindValue(":maxsemestres", obj->getMaxSemestres() );
        query.bindValue(":ects", obj->getEcts() );
        query.bindValue(":current", obj->isCurrent() );
        query.bindValue(":dossier", obj->getDossier()->ID() );
        if(obj->getParent()){
            query.bindValue(":parrent", obj->getParent()->ID() );
        }

        if (!query.exec()){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
            return false;
        }else{
            LogWriter::writeln("CursusDAO.cpp","Modification du cursus : " + obj->getCode());
            return true;
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("CursusDAO::update()",e.getMessage());
        return false;
    }
}

bool CursusDAO::remove(Cursus* obj){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("DELETE FROM cursus WHERE id = :id ;");
        query.bindValue(":id", obj->ID());
        if (!query.exec()){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
            return false;
        }else{
            LogWriter::writeln("CursusDAO.cpp","Suprression du cursus : " + obj->getCode());
            Map.erase(Map.find(obj->ID()));
            return true;
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("CursusDAO::remove()",e.getMessage());
        return false;
    }
}

bool CursusDAO::create(Cursus *obj){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("INSERT INTO cursus (code=:code, titre=:titre, maxsemestres=:maxSem, ects=:ects, current=:current, parent=:parent, dossier:dossier) VALUES (NULL, :code, :titre, :categorie, :automne, :printemps, :demiuv);");
        query.bindValue(":code", obj->getCode() );
        query.bindValue(":titre", obj->getTitre() );
        query.bindValue(":maxsemestres", obj->getMaxSemestres() );
        query.bindValue(":ects", obj->getEcts() );
        query.bindValue(":current", obj->isCurrent() );
        query.bindValue(":dossier", obj->getDossier()->ID() );
        if(obj->getParent()){
            query.bindValue(":parrent", obj->getParent()->ID() );
        }
        if (!query.exec()){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
            return false;
        }else{
            int id = query.lastInsertId().toInt();
            obj->setID(id);
            Map.insert(id,obj);
            LogWriter::writeln("CursusDAO.cpp","Création de l'UV : " + obj->getCode());
            return true;
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("CursusDAO::create()",e.getMessage());
    }
}

