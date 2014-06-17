#include "dao/CursusDAO.h"
#include "dao/CategorieDAO.h"
#include <QDebug>

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
            const int p = rec.value("parent").toInt();
            const int prevSem = rec.value("previsionsemestres").toInt();
            if (!Map.contains(id)) {
                QMap<QString,int> ectsmap = getEctsMap(id);

                LogWriter::writeln("Cursus.cpp","Lecture du cursus : " + c);

                Cursus* cursus;
                if(p != 0){
                    Cursus* par = find(p);
                    cursus=new Cursus(id,c,t,ects,maxSem,prevSem,par,ectsmap);
                }else{
                    cursus=new Cursus(id,c,t,ects,maxSem,prevSem,NULL,ectsmap);
                }
                Map.insert(id,cursus);
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
            LogWriter::writeln("Cursus.cpp","Lecture du cursus depuis la map : " + Map.value(id)->getCode());
            return Map.value(id);
        }
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("SELECT * FROM cursus WHERE id = :id;");
        query.bindValue(":id",id);
        if (!query.exec()){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }
        if(query.first()){
            QSqlRecord rec = query.record();

            const int id = rec.value("id").toInt();
            const QString c = rec.value("code").toString();
            const QString t = rec.value("titre").toString();
            const int cects = rec.value("ects").toInt();
            const int maxSem = rec.value("maxsemestres").toInt();
            const int prevSem = rec.value("previsionsemestres").toInt();
            const int p = rec.value("parent").toInt();

            LogWriter::writeln("Cursus.cpp","Lecture du cursus : " + c);
            QMap<QString,int> ectsmap = getEctsMap(id);
            Cursus* cursus;

            if(p != 0){
                Cursus* par = find(p);
                cursus=new Cursus(id,c,t,cects,maxSem,prevSem,par,ectsmap);
            }else{
                cursus=new Cursus(id,c,t,cects,maxSem,prevSem,NULL,ectsmap);
            }

            Map.insert(id,cursus);
            return cursus;
        }else{
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("Cursus::find()",e.getMessage());
    }
}

Cursus *CursusDAO::findByCode(const QString &str)
{
    try{

        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("SELECT * FROM cursus WHERE code = :code;");
        query.bindValue(":code",str);
        if (!query.exec()){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }
        if(query.first()){
            QSqlRecord rec = query.record();
            const int id = rec.value("id").toInt();
            const QString c = rec.value("code").toString();
            const QString t = rec.value("titre").toString();
            const int ects = rec.value("ects").toInt();
            const int maxSem = rec.value("maxsemestres").toInt();
            const int prevSem = rec.value("previsionsemestres").toInt();
            const int p = rec.value("parent").toInt();
            if (Map.contains(id)) {
                LogWriter::writeln("Cursus.cpp","Lecture du cursus depuis la map : " + str);

                return Map.value(id);
            }
            LogWriter::writeln("Cursus.cpp","Lecture du cursus : " + c);
            QMap<QString,int> ectsmap = getEctsMap(id);
            Cursus* cursus;
            if(p != 0){
               Cursus* par = find(p);
                cursus=new Cursus(id,c,t,ects,maxSem,prevSem,par,ectsmap);

            }else{
                cursus=new Cursus(id,c,t,ects,maxSem,prevSem,NULL,ectsmap);

            }
            Map.insert(id,cursus);
            return cursus;

        }else{
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("CursusDAO::findByCode()",e.getMessage());
    }
}

bool CursusDAO::update(Cursus* obj){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("UPDATE cursus SET (code=:code, titre=:titre, ects=:ects, maxsemestres=:maxsemestres, previsionsemestres=:previsionsemestres, parent=:parent) WHERE id = :id ;");
        query.bindValue(":id", obj->ID());
        query.bindValue(":code", obj->getCode() );
        query.bindValue(":titre", obj->getTitre() );
        query.bindValue(":maxsemestres", obj->getMaxSemestres() );
        query.bindValue(":previsionsemestres", obj->getPrevisionSemestres() );
        query.bindValue(":ects", obj->getEcts() );
        if(obj->getParent()){
            query.bindValue(":parrent", obj->getParent()->ID() );
        }else{
            query.bindValue(":parrent", 0 );
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
            query.prepare("DELETE FROM categorie_cursus_decorator WHERE idcursus = :id ;");
            query.bindValue(":id", obj->ID());
            if (!query.exec()){
                throw UTProfilerException("La requète a échoué : " + query.lastQuery());
            }
            Map.erase(Map.find(obj->ID()));
            return true;
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("CursusDAO::remove()",e.getMessage());
        return false;
    }
}

bool CursusDAO::create(Cursus *obj){
    QSqlQuery query(Connexion::getInstance()->getDataBase());
    try{
        query.prepare("INSERT INTO cursus (code, titre, ects, maxsemestres, previsionsemestres, parent) VALUES (:code, :titre, :ects, :maxsemestres, :previsionsemestres, :parent);");
        query.bindValue(":code", obj->getCode() );
        query.bindValue(":titre", obj->getTitre() );
        query.bindValue(":ects", obj->getEcts() );
        query.bindValue(":maxsemestres", obj->getMaxSemestres() );
        query.bindValue(":previsionsemestres", obj->getPrevisionSemestres() );
        if(obj->getParent()){
            query.bindValue(":parrent", obj->getParent()->ID() );
        }else{
            query.bindValue(":parrent", 0 );
        }
        if (!query.exec()){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
            return false;
        }else{

            int id = query.lastInsertId().toInt();
            obj->setID(id);

            Map.insert(id,obj);
            LogWriter::writeln("CursusDAO.cpp","Création du cursus : " + obj->getCode());

            QMap<QString, int> cat = obj->getCredits();
            query.prepare("INSERT INTO categorie_cursus_decorator (idcursus, idcategorie, ects) VALUES (:idcursus, :idcategorie, :ects);");

            for (QMap<QString, int>::const_iterator i = cat.begin(); i != cat.end(); ++i) {
                int idcat = CategorieDAO::getInstance()->findByStr(i.key());
                query.bindValue(":idcursus", obj->ID() );
                query.bindValue(":idcategorie", idcat );
                query.bindValue(":ects", i.value() );
                if (!query.exec()){
                    throw UTProfilerException("La requète a échoué : " + query.lastQuery());
                }
                LogWriter::writeln("CursusDAO.cpp","Ajout de la reference categorie : " + QString::number(idcat));
            }
            return true;
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("CursusDAO::create()",e.getMessage());
    }
}

QStringList CursusDAO::getStringList(const QString colonne)
{
    QStringList liste;
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("SELECT "+colonne+" FROM cursus;");
        if (!query.exec()){
            throw UTProfilerException("La requête a échoué : " + query.lastQuery());
        }
        while (query.next()){
            QSqlRecord rec = query.record();
            liste<<(rec.value(colonne).toString());
        }

    }catch(UTProfilerException e){
        LogWriter::writeln("Categorie::getColonne()",e.getMessage());}
    return liste;
}

QMap<QString, int> CursusDAO::getEctsMap(const unsigned int id)
{
    QMap<QString,int> ectsmap;
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("SELECT c.id ,cat.titre, ccd.ects FROM cursus c JOIN categorie_cursus_decorator ccd ON ccd.idcursus = c.id JOIN categories cat ON cat.id = ccd.idcategorie WHERE c.id = :id;");
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
        LogWriter::writeln("CursusDAO::getEctsMap()",e.getMessage());}
}

QMap<QString, int > CursusDAO::computePercent(unsigned int id)
{
    QMap<QString,int > ectsmap;
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("SELECT categories.titre, SUM(cud.ects) as somme "
                      "FROM cursus LEFT JOIN uvs_cursus ON cursus.id = uvs_cursus.idcursus "
                      "LEFT JOIN inscriptions ON inscriptions.uv = uvs_cursus.iduv "
                      "LEFT JOIN categorie_uv_decorator cud ON cud.iduv = uvs_cursus.iduv "
                      "LEFT JOIN categories ON categories.id = cud.idcategorie "
                      "WHERE inscriptions.resultat IN ('A','B','C','D','E') "
                      "AND cursus.id = :id GROUP BY categories.titre;");
        query.bindValue(":id",id);
        if (!query.exec()){
            throw UTProfilerException("La requête a échoué : " + query.lastQuery());
        }
        while (query.next()){
            QSqlRecord rec = query.record();
            ectsmap.insert(rec.value("titre").toString(), rec.value("somme").toInt());
        }
        return ectsmap;

    }catch(UTProfilerException e){
        LogWriter::writeln("CusrsusDAO::computePercent()",e.getMessage());}
}

