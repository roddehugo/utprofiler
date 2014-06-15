#include "InscriptionDAO.h"

QMap<int, Inscription *> InscriptionDAO::findAll(){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        if (!query.exec("SELECT * FROM inscriptions;")){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }

        while (query.next()){
            QSqlRecord rec = query.record();
            const int id = rec.value("id").toInt();
            const unsigned int s = rec.value("semestre").toInt();
            const unsigned int u = rec.value("uv").toInt();
            const QString r = rec.value("resultat").toString();
            if (Map.contains(id)) {
                throw UTProfilerException("L'inscription' " + QString::number(id) + " existe déjà dans la QMap");
            }else{
                LogWriter::writeln("Inscription.cpp","Lecture de l'inscription' : " + QString::number(id));
//                UV* uv = UVDAO::getInstance()->find(u);
//                Semestre* semestre = SemestreDAO::getInstance()->find(s);
//                Inscription* inscription=new Inscription(uv,semestre,Inscription::resultat2str(r));
//                Map.insert(id,inscription);
            }
        }

    }catch(UTProfilerException e){
        LogWriter::writeln("InscriptionDAO::findAll()",e.getMessage());
    }
}

Inscription* InscriptionDAO::find(const int& id){
    try{
        if (Map.contains(id)) {
            return Map.value(id);
        }
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        if (!query.exec("SELECT * FROM inscriptions WHERE id = " + QString(id) + ";")){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }
        if(query.first()){
            QSqlRecord rec = query.record();
            const int id = rec.value("id").toInt();
            const unsigned int s = rec.value("semestre").toInt();
            const unsigned int u = rec.value("uv").toInt();
            const QString r = rec.value("resultat").toString();
            LogWriter::writeln("Inscription.cpp","Lecture de l'inscription' : " + QString::number(id));
//                UV* uv = UVDAO::getInstance()->find(u);
//                Semestre* semestre = SemestreDAO::getInstance()->find(s);
//                Inscription* inscription=new Inscription(uv,semestre,Inscription::str2resultat(r));
//                Map.insert(id,inscription);
        }else{
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("SemestreDAO::find()",e.getMessage());
    }
}

bool InscriptionDAO::update(Inscription* obj){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("UPDATE inscriptions SET (resultat=:resultat, semestre=:semestre, uv=:uv) WHERE id = :id ;");
        query.bindValue(":id", obj->ID());
        query.bindValue(":resultat", Inscription::resultat2str(obj->getResultat()) );
        query.bindValue(":semestre", obj->getSemestre()->ID() );
        query.bindValue(":uv", obj->getUv()->ID() );
        if (!query.exec()){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
            return false;
        }else{
            LogWriter::writeln("InscriptionsDAO.cpp","Modification de l'inscription' : " + QString::number(obj->ID()) );
            return true;
        }

    }catch(UTProfilerException e){
        LogWriter::writeln("InscriptionsDAO::update()",e.getMessage());
    }
}

bool InscriptionDAO::remove(Inscription* obj){

}

bool InscriptionDAO::create(Inscription* obj){

}

