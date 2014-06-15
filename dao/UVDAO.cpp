#include "dao/UVDAO.h"

QMap<int, Creditable *> UVDAO::findAll(){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        if (!query.exec("SELECT u.id as uvid, u.code as codeuv, u.titre as titreuv, u.automne, u.printemps, u.demiuv, c.id as categorieid, c.titre as categorietitre, cud.ects FROM uvs u INNER JOIN categorie_uv_decorator cud ON u.id = cud.iduv INNER JOIN categories c ON c.id = cud.idcategorie;")){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }
        Creditable* uv;

        if(query.first()){
            QSqlRecord rec = query.record();
            const int uvid = rec.value("uvid").toInt();
            const QString codeuv = rec.value("codeuv").toString();
            const QString titreuv = rec.value("titreuv").toString();
            const bool automne = rec.value("automne").toBool();
            const bool printemps = rec.value("printemps").toBool();
            const bool demiuv = rec.value("demiuv").toBool();
            if (Map.contains(uvid)) {
                throw UTProfilerException("L'UV "+codeuv+" existe déjà dans la QMap");
            }else{
                LogWriter::write("UVDAO.cpp","Lecture de l'UV : " + uvid);

                uv = new UV(uvid,codeuv,titreuv,printemps,automne,demiuv);

                while (query.next()){
                    if(rec.value("uvid").toInt() != uvid){
                        throw UTProfilerException("Erreur grave lors de la lecture des categories sur "+codeuv);
                    }
                    const int categorieid = rec.value("categorieid").toInt();
                    const QString categorietitre = rec.value("categorietitre").toString();
                    const int ects = rec.value("ects").toInt();
                    uv = parse(categorieid,categorietitre,ects,uv);
                }
                qDebug() << uv->getTitre();

                Map.insert(uvid,uv);
            }
        }


        return Map;
    }catch(UTProfilerException e){
        LogWriter::writeln("UVDAO::findAll()",e.getMessage());
    }
}

Creditable* UVDAO::find(const int& id){
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

bool UVDAO::update(Creditable* obj){
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

bool UVDAO::remove(Creditable* obj){
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

bool UVDAO::create(Creditable *obj){
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

Creditable *UVDAO::parse(const int cid, const QString &ctitre, const int ects, Creditable *cre)
{
    if(ctitre=="SP")
        return new SP(cid,ctitre,ects,cre);
    else if(ctitre=="TM")
        return new TM(cid,ctitre,ects,cre);
    else if(ctitre=="CS")
        return new CS(cid,ctitre,ects,cre);
    else if(ctitre=="TSH")
        return new TSH(cid,ctitre,ects,cre);
    else
        throw UTProfilerException("Impossible de convertir le string de la categorie en class concrete");
}
