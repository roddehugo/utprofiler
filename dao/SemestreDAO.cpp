#include "SemestreDAO.h"

QMap<int, Semestre *> SemestreDAO::findAll(){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        if (!query.exec("SELECT * FROM semestres;")){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }

        while (query.next()){
            QSqlRecord rec = query.record();
            const int id = rec.value("id").toInt();
            const QString s = rec.value("saison").toString();
            const unsigned int a = rec.value("annee").toInt();
            const bool e = rec.value("isetranger").toBool();
            const unsigned int d = rec.value("dossier").toInt();
            if (Map.contains(id)) {
                throw UTProfilerException("Le semestre " + QString::number(id) + " existe déjà dans la QMap");
            }else{
                LogWriter::writeln("Semestre.cpp","Lecture du semestre : " + QString::number(id));
//                Dossier* dossier = DossierDAO::getInstance()->find(d);
//                Semestre* newsemestre=new Semestre(id,Semestre::str2saison(s),a,e,dossier);
//                Map.insert(id,newsemestre);
            }
        }

    }catch(UTProfilerException e){
        LogWriter::writeln("SemestreDAO::findAll()",e.getMessage());
    }
}

Semestre* SemestreDAO::find(const int& id){
    try{
        if (Map.contains(id)) {
            return Map.value(id);
        }
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        if (!query.exec("SELECT * FROM semestres WHERE id = " + QString(id) + ";")){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }
        if(query.first()){
            QSqlRecord rec = query.record();
            const int id = rec.value("id").toInt();
            const QString s = rec.value("saison").toString();
            const unsigned int a = rec.value("annee").toInt();
            const bool e = rec.value("isetranger").toBool();
            const unsigned int d = rec.value("dossier").toInt();
            LogWriter::writeln("Semestre.cpp","Lecture du semestre : " + QString::number(id));
            //        Dossier* dossier = DossierDAO::getInstance()->find(d);
            //        Semestre* newsemestre=new Semestre(Semestre::str2saison(s),a,e,dossier);
            //        Map.insert(id,newsemestre);
        }else{
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("SemestreDAO::find()",e.getMessage());
    }
}

bool SemestreDAO::update(Semestre* obj){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("UPDATE semestres SET (saison=:saison, annee=:annee, isetranger=:isetranger, dossier=:dossier) WHERE id = :id ;");
        query.bindValue(":id", obj->ID());
        query.bindValue(":saison", obj->getSaison() );
        query.bindValue(":annee", obj->getAnnee() );
        query.bindValue(":isetranger", obj->isEtranger() );
        query.bindValue(":dossier", obj->getDossier()->ID() );
        if (!query.exec()){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
            return false;
        }else{
            LogWriter::writeln("UVDAO.cpp","Modification de l'UV : " + QString::number(obj->ID()) );
            return true;
        }

    }catch(UTProfilerException e){
        LogWriter::writeln("SemestreDAO::update()",e.getMessage());
    }
}

bool SemestreDAO::remove(Semestre* obj){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("DELETE FROM semestres WHERE id = :id ;");
        query.bindValue(":id", obj->ID());
        if (!query.exec()){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
            return false;
        }else{
            LogWriter::writeln("Semestre.cpp","Suppression du semestre : " + QString::number(obj->ID()));
            Map.erase(Map.find(obj->ID()));
            return true;
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("SemestreDAO::remove()",e.getMessage());
    }
}

bool SemestreDAO::create(Semestre* obj){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("INSERT INTO semestres (id, saison, annee, isetranger, dossier) VALUES (NULL, :saison, :annee, :isetranger, :dossier);");
        query.bindValue(":saison", Semestre::saison2str(obj->getSaison()) );
        query.bindValue(":annee", obj->getAnnee() );
        query.bindValue(":isetranger", obj->isEtranger() );
        query.bindValue(":dossier", obj->getDossier()->ID() );
        if (!query.exec()){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
            return false;
        }else{
            int id =query.lastInsertId().toInt();
            obj->setID(id);
            Map.insert(id,obj);
            LogWriter::writeln("SemestreDAO.cpp","Création du semestre : " + QString::number(obj->ID()));
            return true;
        }

    }catch(UTProfilerException e){
        LogWriter::writeln("SemestreDAO::create()",e.getMessage());
    }
}

