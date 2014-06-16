#include "dao/UVDAO.h"
#include <QDebug>

QMap<int, UV *> UVDAO::findAll(){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());

        if (!query.exec("SELECT * FROM uvs;") ){
            throw UTProfilerException("La requête a échoué : " + query.lastQuery());
        }

        while (query.next()){
            QSqlRecord rec = query.record();
            const int id = rec.value("uid").toInt();
            const QString code = rec.value("code").toString();
            const QString titre = rec.value("titre").toString();
            const bool automne = rec.value("automne").toBool();
            const bool printemps = rec.value("printemps").toBool();
            const bool demiuv = rec.value("demiuv").toBool();

            if (Map.contains(id)) {
                throw UTProfilerException("L'UV "+code+" existe déjà dans la QMap");
            }else{
                LogWriter::writeln("UVDAO.cpp","Lecture de l'UV : " + code);
                QMap<QString,int> ectsmap = getEctsMap(id);
                QList<Cursus*> cursuslist = getCursusList(id);

                UV* newetu=new UV(id,code,titre,automne,printemps,demiuv,ectsmap,cursuslist);

                Map.insert(id,newetu);
            }
        }

    }catch(UTProfilerException e){
        LogWriter::writeln("UVDAO::findAll()",e.getMessage());
    }
}

UV* UVDAO::find(const int& id){
    try{
        if(Map.contains(id)){
             return Map.value(id);
        }
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("SELECT * FROM uvs WHERE id = :id;");
        query.bindValue(":id",id);
        if (!query.exec() ){
            throw UTProfilerException("La requête a échoué : " + query.lastQuery());
        }

        if(query.first()){
            QSqlRecord rec = query.record();

            const int id = rec.value("uid").toInt();
            const QString code = rec.value("code").toString();
            const QString titre = rec.value("titre").toString();
            const bool automne = rec.value("automne").toBool();
            const bool printemps = rec.value("printemps").toBool();
            const bool demiuv = rec.value("demiuv").toBool();

            LogWriter::write("UVDAO.cpp","Lecture de l'UV : " + code);
            QMap<QString,int> ectsmap = getEctsMap(id);
            QList<Cursus*> cursuslist = getCursusList(id);

            UV* uv = new UV(id,code,titre,printemps,automne,demiuv,ectsmap,cursuslist);
            Map.insert(id,uv);
            return uv;
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("UVDAO::find()",e.getMessage());
    }

}

UV *UVDAO::findByCode(const QString str)
{
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("SELECT u.id as uid, u.titre as utitre, code, automne, printemps, demiuv, c.id as cid, c.titre as ctitre, ects FROM uvs u INNER JOIN categorie_uv_decorator cud ON cud.iduv = uid INNER JOIN categories c ON cud.idcategorie = cid WHERE code = :titre;");
        query.bindValue(":titre",str);
        if (!query.exec() ){
            throw UTProfilerException("La requête a échoué : " + query.lastQuery());
        }

        if(query.first()){
            QSqlRecord rec = query.record();

            const int uid = rec.value("uid").toInt();
            const QString code = rec.value("code").toString();
            const QString utitre = rec.value("utitre").toString();
            const bool automne = rec.value("automne").toBool();
            const bool printemps = rec.value("printemps").toBool();
            const bool demiuv = rec.value("demiuv").toBool();

            LogWriter::write("UVDAO.cpp","Lecture de l'UV : " + code);
            UV* uv = new UV(uid,code,utitre,printemps,automne,demiuv);

            const QString ctitre = rec.value("ctitre").toString();
            const int ects = rec.value("ects").toInt();

            LogWriter::append(ctitre+":"+QString::number(ects)+"...");
            QMap<QString,int> credits;

            while(query.next()){
                rec = query.record();
                const QString ctitre = rec.value("ctitre").toString();
                const int ects = rec.value("ects").toInt();

                LogWriter::append(ctitre+":"+QString::number(ects)+"...");
                credits.insert(ctitre,ects);
            }
            uv->setCredits(credits);
            LogWriter::endl();
            Map.insert(uid,uv);
            return uv;
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("UVDAO::find()",e.getMessage());
    }
}

bool UVDAO::update(UV* obj){

    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("UPDATE uvs SET (code=:code, titre=:titre, automne=:automne, printemps=:printemps, demiuv=:demiuv) WHERE id = :id ;");
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
        return false;
    }

}

bool UVDAO::remove(UV* obj){
    QMessageBox msgBox;
    msgBox.setText("L'UV "+ obj->getCode() + " ainsi que les entrées associées vont êtres supprimées.");
    msgBox.setInformativeText("Voulez-vous vraiment continuer?");
    msgBox.setStandardButtons(QMessageBox::Discard | QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Discard);
    if(msgBox.exec()){
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
            return false;
        }
    }
}

bool UVDAO::create(UV *obj){
    QSqlQuery query(Connexion::getInstance()->getDataBase());
    try{
        if (!query.exec("BEGIN;"))
            throw UTProfilerException("La requète a échoué : " + query.lastQuery() );

        query.prepare("INSERT INTO uvs (code, titre, automne, printemps, demiuv) VALUES (:code, :titre, :automne, :printemps, :demiuv);");
        query.bindValue(":code", obj->getCode() );
        query.bindValue(":titre", obj->getTitre() );
        query.bindValue(":automne", obj->isAutomne() );
        query.bindValue(":printemps", obj->isPrintemps() );
        query.bindValue(":demiuv", obj->isDemiUV() );

        if (!query.exec()){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }else{
            int id = query.lastInsertId().toInt();
            obj->setID(id);
            Map.insert(id,obj);
            LogWriter::writeln("UVDAO.cpp","Création de l'UV : " + obj->getCode());
        }

        QMap<QString,int> cats = obj->getCredits();
        for(QMap<QString,int>::const_iterator i = cats.begin(); i!= cats.constEnd(); ++i){
            query.prepare("INSERT INTO categorie_uv_decorator (iduv, idcategorie, ects) VALUES (:iduv, :idcat, :ects);");
            query.bindValue(":iduv", obj->ID() );
            query.bindValue(":idcat", CategorieDAO::getInstance()->findByStr(i.key()) );
            query.bindValue(":ects", i.value() );
        }
        if (!query.exec("COMMIT;"))
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());

    }catch(UTProfilerException e){
        query.exec("ROLLBACK;");
        LogWriter::writeln("UVDAO::create()",e.getMessage());
        return false;
    }
}

QStringList UVDAO::getStringList(const QString &colonne)
{
    QStringList liste;

    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());

        if(!query.exec("SELECT "+colonne+" FROM uvs;"))
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        while (query.next()) {
            QSqlRecord rec = query.record();
            liste<<rec.value(colonne).toString();
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("UVDAO::getStringList()",e.getMessage());
    }
    return liste;
}


QMap<QString, int> UVDAO::getEctsMap(const unsigned int id)
{
    QMap<QString,int> ectsmap;
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("SELECT u.id ,cat.titre, cud.ects FROM uvs u JOIN categorie_uv_decorator cud ON cud.iduv = u.id JOIN categories cat ON cat.id = cud.idcategorie WHERE u.id = :id;");
        query.bindValue(":id",id);
        if (!query.exec()){
            throw UTProfilerException("La requête a échoué : " + query.lastQuery());
        }
        while (query.next()){
            QSqlRecord rec = query.record();
            ectsmap.insert(rec.value("titre").toString(),rec.value("ects").toInt());
        }
        return ectsmap;

    }catch(UTProfilerException e){
        LogWriter::writeln("UVDAO::getEctsMap()",e.getMessage());}
}

QMap<QString, bool> UVDAO::getCursusMap(unsigned int id)
{
    QMap<QString,bool> cursusmap;
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("SELECT u.id ,cur.code, obligatoire FROM uvs u JOIN uvs_cursus uc ON uc.iduv = u.id JOIN cursus cur ON cur.id = uc.idcursus WHERE u.id = :id;");
        query.bindValue(":id",id);
        if (!query.exec()){
            throw UTProfilerException("La requête a échoué : " + query.lastQuery());
        }
        while (query.next()){
            QSqlRecord rec = query.record();
            cursusmap.insert(rec.value("code").toString(),rec.value("obligatoire").toBool());
        }
        return cursusmap;

    }catch(UTProfilerException e){
        LogWriter::writeln("UVDAO::getCursusMap()",e.getMessage());}
}

QList<Cursus *> UVDAO::getCursusList(unsigned int id)
{
    QList<Cursus *> list;
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("SELECT cur.id FROM uvs u JOIN uvs_cursus uc ON uc.iduv = u.id JOIN cursus cur ON cur.id = uc.idcursus WHERE u.id = :id;");
        query.bindValue(":id",id);
        if (!query.exec()){
            throw UTProfilerException("La requête a échoué : " + query.lastQuery());
        }
        while (query.next()){
            QSqlRecord rec = query.record();
            int id = rec.value("id").toInt();

            list << CursusDAO::getInstance()->find(id);
        }
        return list;

    }catch(UTProfilerException e){
        LogWriter::writeln("UVDAO::getCursusMap()",e.getMessage());}
}

