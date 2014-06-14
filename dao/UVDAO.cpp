#include "dao/UVDAO.h"

UVDAO::UVDAO(){}

UVDAO::~UVDAO(){}

QMap<int, UV *> UVDAO::findAll(){
    QSqlQuery query(Connexion::getInstance()->getDataBase());
    if (!query.exec("SELECT * FROM uvs ORDER BY code;")){
        throw UTProfilerException("La requète a échoué : " + query.lastQuery());
    }
    QMap<int,UV*> uvmap;

    while (query.next()){
        QSqlRecord rec = query.record();
        //qDebug() << rec;
        const int id = rec.value("id").toInt();
        const QString c = rec.value("code").toString();
        const QString t = rec.value("titre").toString();
        const int cat = rec.value("categorie").toInt();
        const bool a = rec.value("automne").toBool();
        const bool p = rec.value("printemps").toBool();
        const bool d = rec.value("demiuv").toBool();
        if (uvmap.contains(id)) {
            throw UTProfilerException("L'UV "+c+" existe déjà dans la QMap");
        }else{
            LogWriter::writeln("UVDAO.cpp","Lecture de l'UV : " + c);
            UV* newuv=new UV(c,t,p,a,d,cat,0);
            uvmap.insert(id,newuv);
        }
    }

    return uvmap;
}

UV* UVDAO::find(const unsigned int& id){
    QSqlQuery query(Connexion::getInstance()->getDataBase());
    if (!query.exec("SELECT * FROM uvs WHERE id = " + QString(id) + ";")){
        throw UTProfilerException("La requète a échoué : " + query.lastQuery());
    }
    if(query.first()){
        QSqlRecord rec = query.record();
        const int id = rec.value("id").toInt();
        const QString c = rec.value("code").toString();
        const QString t = rec.value("titre").toString();
        const int cat = rec.value("categorie").toInt();
        const bool a = rec.value("automne").toBool();
        const bool p = rec.value("printemps").toBool();
        const bool d = rec.value("demiuv").toBool();
        LogWriter::writeln("UVDAO.cpp","Lecture de l'UV : " + c);
        return new UV(c,t,p,a,d,cat,0);
    }
}

void UVDAO::update(const UV& obj){


}

void UVDAO::remove(const UV& obj){

}

void UVDAO::create(const UV& obj){
    QSqlQuery query(Connexion::getInstance()->getDataBase());
    query.prepare("INSERT INTO uvs (id, code, titre, categorie, automne, printemps, demiuv) VALUES (:id, :code, :titre, :categorie, :automne, :printemps, :demiuv);");
    query.bindValue(":id", "NULL");
    query.bindValue(":code", obj.getCode() );
    query.bindValue(":titre", obj.getTitre() );
    query.bindValue(":categorie", obj.getCategorie() );
    query.bindValue(":automne", obj.getAutomne() );
    query.bindValue(":printemps", obj.getPrintemps() );
    query.bindValue(":demiuv", obj.getDemiUV() );
    if (!query.exec()){
        throw UTProfilerException("La requète a échoué : " + query.lastQuery());
    }
}
