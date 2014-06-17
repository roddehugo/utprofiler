#include "dao/InscriptionDAO.h"
#include "dao/UVDAO.h"
#include "dao/SemestreDAO.h"
#include "dao/DossierDAO.h"
#include <QDebug>

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
            const unsigned int d = rec.value("dossier").toInt();
            const unsigned int u = rec.value("uv").toInt();
            const QString r = rec.value("resultat").toString();
            if (Map.contains(id)) {
                throw UTProfilerException("L'inscription' " + QString::number(id) + " existe déjà dans la QMap");
            }else{
                LogWriter::writeln("Inscription.cpp","Lecture de l'inscription' : " + QString::number(id));
                UV* uv = UVDAO::getInstance()->find(u);
                Semestre* semestre = SemestreDAO::getInstance()->find(s);
                Dossier* dossier = DossierDAO::getInstance()->find(d);
                Inscription* inscription=new Inscription(uv,semestre,Inscription::str2resultat(r),dossier);
                Map.insert(id,inscription);

            }
            return Map;
        }

    }catch(UTProfilerException e){
        LogWriter::writeln("InscriptionDAO::findAll()",e.getMessage());
    }
}


QList<Semestre *> InscriptionDAO::findSemestresByDossier(const int dossier){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        if (!query.exec("SELECT DISTINCT semestre FROM inscriptions WHERE dossier = "+QString::number(dossier)+";")){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }
        QList<Semestre *> sem;
        while (query.next()){
            QSqlRecord rec = query.record();
            const unsigned int s = rec.value("semestre").toInt();
            LogWriter::writeln("Inscription.cpp","Lecture du semestre depuis les inscriptions : " + QString::number(s));
            sem << SemestreDAO::getInstance()->find(s);
        }
        return sem;

    }catch(UTProfilerException e){
        LogWriter::writeln("InscriptionDAO::findAll()",e.getMessage());
    }
}


QList<UV *> InscriptionDAO::findUvsBySemestre(const int semestre){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        if (!query.exec("SELECT DISTINCT uv FROM inscriptions WHERE semestre = "+QString::number(semestre)+";")){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }
        QList<UV *> uvs;
        while (query.next()){
            QSqlRecord rec = query.record();
            const unsigned int u = rec.value("uv").toInt();
            LogWriter::writeln("Inscription.cpp","Lecture des uvs avec semestre : " + QString::number(semestre));
            uvs << UVDAO::getInstance()->find(u);
        }
        return uvs;

    }catch(UTProfilerException e){
        LogWriter::writeln("InscriptionDAO::findAll()",e.getMessage());
    }
}


Inscription* InscriptionDAO::find(const int& id){
    try{
        if (Map.contains(id)) {
            LogWriter::writeln("Inscription.cpp","Lecture de l'inscription depuis la map : " + QString::number(id));
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
            const unsigned int d = rec.value("dossier").toInt();
            const unsigned int u = rec.value("uv").toInt();
            const QString r = rec.value("resultat").toString();
            LogWriter::writeln("Inscription.cpp","Lecture de l'inscription : " + QString::number(id));
            UV* uv = UVDAO::getInstance()->find(u);
            Semestre* semestre = SemestreDAO::getInstance()->find(s);
            Dossier* dossier = DossierDAO::getInstance()->find(d);
            Inscription* inscription=new Inscription(uv,semestre,Inscription::str2resultat(r),dossier);
            Map.insert(id,inscription);
            return Map.value(id);
        }else{
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("InscriptionDAO::find()",e.getMessage());
    }
}


bool InscriptionDAO::update(Inscription* obj){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("UPDATE inscriptions SET (resultat=:resultat, semestre=:semestre, uv=:uv, dossier=:dossier) WHERE id = :id ;");
        query.bindValue(":id", obj->ID());
        query.bindValue(":resultat", Inscription::resultat2str(obj->getResultat()) );
        query.bindValue(":semestre", obj->getSemestre()->ID() );
        query.bindValue(":dossier", obj->getDossier()->ID() );
        query.bindValue(":uv", obj->getUv()->ID() );
        if (!query.exec()){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
            return false;
        }else{
            LogWriter::writeln("InscriptionDAO.cpp","Modification de l'inscription' : " + QString::number(obj->ID()) );
            return true;
        }

    }catch(UTProfilerException e){
        LogWriter::writeln("InscriptionsDAO::update()",e.getMessage());
        return false;
    }

}

bool InscriptionDAO::remove(Inscription* obj){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("DELETE FROM inscriptions WHERE id = :id ;");
        query.bindValue(":id", obj->ID());
        if (!query.exec()){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
            return false;
        }else{
            LogWriter::writeln("InscriptionDAO.cpp","Suppression de l'inscription' : " + QString::number(obj->ID()));
            Map.erase(Map.find(obj->ID()));
            return true;
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("InscriptionDAO::remove()",e.getMessage());
        return false;
    }
}

bool InscriptionDAO::create(Inscription* obj){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("INSERT INTO inscriptions (id, resultat, semestre, uv, dossier) VALUES (NULL, :resultat, :semestre, :uv, :dossier);");
        query.bindValue(":resultat", Inscription::resultat2str(obj->getResultat()) );
        query.bindValue(":semestre", obj->getSemestre()->ID() );
        query.bindValue(":dossier", obj->getDossier()->ID() );
        query.bindValue(":uv", obj->getUv()->ID() );
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
        return false;
    }
}

QStringList InscriptionDAO::getStringListResultat()
{
    QStringList liste;
    liste << "A" << "B"<<"C"<<"D"<<"E"<<"F"<<"FX"<<"ABS"<<"RES"<<"EC"<<"EQU";
    return liste;
}

QString InscriptionDAO::getResultat(unsigned int dossier, unsigned int semestre, unsigned int uv)
{
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("SELECT id, resultat FROM inscriptions WHERE dossier = :d AND semestre = :s AND uv = :u;");
        query.bindValue(":d",dossier);
        query.bindValue(":s",semestre);
        query.bindValue(":u",uv);
        if (!query.exec()){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }
        if(query.first()){
            QSqlRecord rec = query.record();
            const int id = rec.value("id").toInt();
            const QString r = rec.value("resultat").toString();
            LogWriter::writeln("Inscription.cpp","Lecture du resultat : " + QString::number(id));
            return r;
        }else{
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("InscriptionDAO::find()",e.getMessage());
    }
}

