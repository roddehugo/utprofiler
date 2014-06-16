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
            const int prevSem = rec.value("previsionssemestres").toInt();
            if (Map.contains(id)) {
                throw UTProfilerException("Le cursus "+c+" existe déjà dans la QMap");
            }else{
                LogWriter::writeln("Cursus.cpp","Lecture du cursus : " + c);
                Cursus* cursus;
                if(p != 0){
                    Cursus* par = find(p);
                    cursus=new Cursus(id,c,t,ects,maxSem,prevSem,par);
                }else{
                    cursus=new Cursus(id,c,t,ects,maxSem,prevSem,NULL);
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
            return Map.value(id);
        }
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("SELECT c.id as cid , c.titre as ctitre, c.code as ccode, c.ects as cetcs, c.maxsemestres, c.previsionsemestres, c.parent, cat.titre as cattitre, ccd.ects FROM cursus c JOIN categorie_cursus_decorator ccd ON ccd.idcursus = cid JOIN categories cat ON cat.id = ccd.idcategorie WHERE cid = :id;");
        query.bindValue(":id",id);
        if (!query.exec()){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }
        if(query.first()){
            QSqlRecord rec = query.record();

            const int id = rec.value("cid").toInt();
            const QString c = rec.value("ccode").toString();
            const QString t = rec.value("ctitre").toString();
            const int cects = rec.value("cects").toInt();
            const int maxSem = rec.value("maxsemestres").toInt();
            const int prevSem = rec.value("previsionssemestres").toInt();
            const int p = rec.value("parent").toInt();

            LogWriter::writeln("Cursus.cpp","Lecture du cursus : " + c);
            Cursus* cursus;

            if(p != 0){
                Cursus* par = find(p);
                cursus=new Cursus(id,c,t,cects,maxSem,prevSem,par);
            }else{
                cursus=new Cursus(id,c,t,cects,maxSem,prevSem,NULL);
            }

            const QString catitre = rec.value("catitre").toString();
            const int ects = rec.value("ects").toInt();

            LogWriter::append(catitre+":"+QString::number(ects)+"...");
            QMap<QString,int> credits;

            while(query.next()){
                rec = query.record();
                const QString ctitre = rec.value("catitre").toString();
                const int ects = rec.value("ects").toInt();

                LogWriter::append(catitre+":"+QString::number(ects)+"...");
                credits.insert(catitre,ects);
            }
            cursus->setCredits(credits);
            LogWriter::endl();
            Map.insert(id,cursus);
        }else{
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("Cursus::find()",e.getMessage());
    }
}

Cursus *CursusDAO::findByLogin(const QString &login)
{
    try{

        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("SELECT c.id as cid , c.titre as ctitre, c.code as ccode, c.ects as cetcs, c.maxsemestres, c.previsionsemestres, c.parent, cat.titre as cattitre, ccd.ects FROM cursus c JOIN categorie_cursus_decorator ccd ON ccd.idcursus = cid JOIN categories cat ON cat.id = ccd.idcategorie WHERE ctitre = :titre;");
        query.bindValue(":titre",login);
        if (!query.exec()){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }
        if(query.first()){
            QSqlRecord rec = query.record();
            const int id = rec.value("cid").toInt();
            const QString c = rec.value("ccode").toString();
            const QString t = rec.value("ctitre").toString();
            const int cects = rec.value("cects").toInt();
            const int maxSem = rec.value("maxsemestres").toInt();
            const int prevSem = rec.value("previsionssemestres").toInt();
            const int p = rec.value("parent").toInt();

            LogWriter::writeln("Cursus.cpp","Lecture du cursus : " + c);
            Cursus* cursus;

            if(p != 0){
                Cursus* par = find(p);
                cursus=new Cursus(id,c,t,cects,maxSem,prevSem,par);
            }else{
                cursus=new Cursus(id,c,t,cects,maxSem,prevSem,NULL);
            }

            const QString catitre = rec.value("catitre").toString();
            const int ects = rec.value("ects").toInt();

            LogWriter::append(catitre+":"+QString::number(ects)+"...");
            QMap<QString,int> credits;

            while(query.next()){
                rec = query.record();
                const QString ctitre = rec.value("catitre").toString();
                const int ects = rec.value("ects").toInt();

                LogWriter::append(catitre+":"+QString::number(ects)+"...");
                credits.insert(catitre,ects);
            }
            cursus->setCredits(credits);
            LogWriter::endl();
            Map.insert(id,cursus);
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
        query.prepare("UPDATE cursus SET (code=:code, titre=:titre, ects=:ects, maxsemestres=:maxsemestres, previsionssemestres=:previsionssemestres, parent=:parent) WHERE id = :id ;");
        query.bindValue(":id", obj->ID());
        query.bindValue(":code", obj->getCode() );
        query.bindValue(":titre", obj->getTitre() );
        query.bindValue(":maxsemestres", obj->getMaxSemestres() );
        query.bindValue(":previsionssemestres", obj->getPrevisionsSemestres() );
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
        query.prepare("INSERT INTO cursus (id, code, titre, ects, maxsemestres, previsionssemestres, parent) VALUES (NULL, :code, :titre, :maxsemestres, :previsionssemestres, :parent);");
        query.bindValue(":code", obj->getCode() );
        query.bindValue(":titre", obj->getTitre() );
        query.bindValue(":ects", obj->getEcts() );
        query.bindValue(":maxsemestres", obj->getMaxSemestres() );
        query.bindValue(":previsionssemestres", obj->getPrevisionsSemestres() );
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
            LogWriter::writeln("CursusDAO.cpp","Création de l'UV : " + obj->getCode());
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
        LogWriter::writeln("CategorieDAO::getEctsMap()",e.getMessage());}
}

