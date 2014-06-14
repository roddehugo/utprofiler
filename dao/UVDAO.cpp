#include "dao/UVDAO.h"

QMap<int, UV *> UVDAO::findAll(){
    QSqlQuery query(Connexion::getInstance()->getDataBase());
    if (!query.exec("SELECT * FROM uvs ORDER BY code;")){
        throw UTProfilerException("La requète a échoué : " + query.lastQuery());
    }

    while (query.next()){
        QSqlRecord rec = query.record();
        const int id = rec.value("id").toInt();
        const QString c = rec.value("code").toString();
        const QString t = rec.value("titre").toString();
        const int cat = rec.value("categorie").toInt();
        const bool a = rec.value("automne").toBool();
        const bool p = rec.value("printemps").toBool();
        const bool d = rec.value("demiuv").toBool();
        if (Map.contains(id)) {
            throw UTProfilerException("L'UV "+c+" existe déjà dans la QMap");
        }else{
            LogWriter::writeln("UVDAO.cpp","Lecture de l'UV : " + c);
            UV* newuv=new UV(c,t,p,a,d);
            Map.insert(id,newuv);
        }
    }

    return Map;
}

UV* UVDAO::find(const int& id){
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
        const int cat = rec.value("categorie").toInt();
        const bool a = rec.value("automne").toBool();
        const bool p = rec.value("printemps").toBool();
        const bool d = rec.value("demiuv").toBool();
        LogWriter::writeln("UVDAO.cpp","Lecture de l'UV : " + c);
        return new UV(c,t,p,a,d);
    }else{
        throw UTProfilerException("La requète a échoué : " + query.lastQuery());
    }
}

bool UVDAO::update(const int& id, UV* obj){
    QSqlQuery query(Connexion::getInstance()->getDataBase());
    query.prepare("UPDATE uvs SET (code=:code, titre=:titre, categorie=:categorie, automne=:automne, printemps=:printemps, demiuv=:demiuv) WHERE id = :id ;");
    query.bindValue(":id", id);
    query.bindValue(":code", obj->getCode() );
    query.bindValue(":titre", obj->getTitre() );
    query.bindValue(":categorie", obj->getCategorie() );
    query.bindValue(":automne", obj->getAutomne() );
    query.bindValue(":printemps", obj->getPrintemps() );
    query.bindValue(":demiuv", obj->getDemiUV() );
    if (!query.exec()){
        throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        return false;
    }else{
        LogWriter::writeln("UVDAO.cpp","Modification de l'UV : " + obj->getCode());
        return true;
    }

}

bool UVDAO::remove(const int& id, UV* obj){
    QSqlQuery query(Connexion::getInstance()->getDataBase());
    query.prepare("DELETE FROM uvs WHERE id = :id ;");
    query.bindValue(":id", id);
    if (!query.exec()){
        throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        return false;
    }else{
        LogWriter::writeln("UVDAO.cpp","Suprression de l'UV : " + obj->getCode());
        delete obj;
        return true;
    }
}

bool UVDAO::create(UV *obj){
    QSqlQuery query(Connexion::getInstance()->getDataBase());
    query.prepare("INSERT INTO uvs (id, code, titre, categorie, automne, printemps, demiuv) VALUES (:id, :code, :titre, :categorie, :automne, :printemps, :demiuv);");
    query.bindValue(":id", "NULL");
    query.bindValue(":code", obj->getCode() );
    query.bindValue(":titre", obj->getTitre() );
    query.bindValue(":categorie", obj->getCategorie() );
    query.bindValue(":automne", obj->getAutomne() );
    query.bindValue(":printemps", obj->getPrintemps() );
    query.bindValue(":demiuv", obj->getDemiUV() );
    if (!query.exec()){
        throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        return false;
    }else{
        Map.insert(query.lastInsertId().toInt(),obj);
        LogWriter::writeln("UVDAO.cpp","Création de l'UV : " + obj->getCode());
        return true;
    }
}
