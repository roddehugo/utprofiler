#include "dao/UVDAO.h"

UVDAO::UVDAO(){

}

UVDAO::~UVDAO(){

}

QMap<int, UV *> UVDAO::findAll(){
    QSqlQuery query(Connexion::getInstance()->getDataBase());
    if (!query.exec("SELECT * FROM uvs ORDER BY code;")){
        throw UTProfilerException("La requète a échoué : " + query.lastQuery());
    }
    QMap<int,UV*> uvmap;

    while (query.next()){
        QSqlRecord rec = query.record();
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
            UV* newuv=new UV(c,t,p,a,d,cat);
            uvmap.insert(id,newuv);
            LogWriter::write("UVDAO.cpp","Ajout de l'UV : " + c);
        }
    }

    return uvmap;
}

UV* UVDAO::find(const unsigned int& id){

}

void UVDAO::update(const UV& obj){

}

void UVDAO::remove(const UV& obj){

}

void UVDAO::create(const UV& obj){

}
