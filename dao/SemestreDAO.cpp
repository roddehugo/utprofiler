#include "dao/SemestreDAO.h"
#include "dao/CursusDAO.h"
#include <QDebug>

QMap<int, Semestre *> SemestreDAO::findAll(){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        if (!query.exec("SELECT * FROM semestres;")){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }

        while (query.next()){
            QSqlRecord rec = query.record();
            const int id = rec.value("id").toInt();
            const QString t = rec.value("titre").toString();
            const QString s = rec.value("saison").toString();
            const unsigned int a = rec.value("annee").toInt();
            const bool e = rec.value("isetranger").toBool();
            const unsigned int d = rec.value("cursus").toInt();
            if (Map.contains(id)) {
                throw UTProfilerException("Le semestre " + QString::number(id) + " existe déjà dans la QMap");
            }else{
                LogWriter::writeln("Semestre.cpp","Lecture du semestre : " + QString::number(id));
                Cursus* cursus = CursusDAO::getInstance()->find(d);
                Semestre* newsemestre=new Semestre(id,t,Semestre::str2saison(s),a,e,cursus);
                Map.insert(id,newsemestre);
            }
        }

    }catch(UTProfilerException e){
        LogWriter::writeln("SemestreDAO::findAll()",e.getMessage());
    }
}

Semestre* SemestreDAO::find(const int &id){
    try{
        if (Map.contains(id)) {
            LogWriter::writeln("SemestreDAO.cpp","Lecture du semestre depuis la map: " + QString::number(id));
            return Map.value(id);
        }
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("SELECT * FROM semestres WHERE id = :id;");
        query.bindValue(":id",id);
        if (!query.exec()){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }
        if(query.first()){
            QSqlRecord rec = query.record();
            const int id = rec.value("id").toInt();
            const QString t = rec.value("titre").toString();
            const QString s = rec.value("saison").toString();
            const unsigned int a = rec.value("annee").toInt();
            const bool e = rec.value("isetranger").toBool();
            const unsigned int d = rec.value("cursus").toInt();
            LogWriter::writeln("SemestreDAO.cpp","Lecture du semestre : " + QString::number(id));
            Cursus* cursus = CursusDAO::getInstance()->find(d);
            Semestre* newsemestre=new Semestre(id,t,Semestre::str2saison(s),a,e,cursus);
            Map.insert(id,newsemestre);
            return newsemestre;
        }else{
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("SemestreDAO::find()",e.getMessage());
    }
}

Semestre *SemestreDAO::findByStr(const QString &str)
{
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("SELECT * FROM semestres WHERE titre = :titre;");
        query.bindValue(":titre",str);

        if (!query.exec()){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }
        if(query.first()){
            QSqlRecord rec = query.record();
            const int id = rec.value("id").toInt();
            const QString t = rec.value("titre").toString();
            const QString s = rec.value("saison").toString();
            const unsigned int a = rec.value("annee").toInt();
            const bool e = rec.value("isetranger").toBool();
            const unsigned int d = rec.value("cursus").toInt();

            if (Map.contains(id)) {
                LogWriter::writeln("Semestre.cpp","Lecture du semestre depuis la map: " + QString::number(id));
                return Map.value(id);
            }
            LogWriter::writeln("Semestre.cpp","Lecture du semestre : " + QString::number(id));
            Cursus* cursus = CursusDAO::getInstance()->find(d);
            Semestre* newsemestre=new Semestre(id,t,Semestre::str2saison(s),a,e,cursus);
            Map.insert(id,newsemestre);
            return newsemestre;
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
        query.prepare("UPDATE semestres SET (titre=:titre,saison=:saison, annee=:annee, isetranger=:isetranger, cursus=:cursus) WHERE id = :id ;");
        query.bindValue(":id", obj->ID());
        query.bindValue(":titre", obj->getTitre() );
        query.bindValue(":saison", obj->getSaison() );
        query.bindValue(":annee", obj->getAnnee() );
        query.bindValue(":isetranger", obj->isEtranger() );
        query.bindValue(":cursus", obj->getCursus()->ID() );
        if (!query.exec()){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
            return false;
        }else{
            LogWriter::writeln("SemestreDAO.cpp","Modification de lu semestre : " + QString::number(obj->ID()) );
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
        query.prepare("INSERT INTO semestres (id, titre, saison, annee, isetranger, cursus) VALUES (NULL, :titre, :saison, :annee, :isetranger, :cursus);");
        query.bindValue(":titre", obj->getTitre() );
        query.bindValue(":saison", Semestre::saison2str(obj->getSaison()) );
        query.bindValue(":annee", obj->getAnnee() );
        query.bindValue(":isetranger", obj->isEtranger() );
        query.bindValue(":cursus", obj->getCursus()->ID() );
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

QStringList SemestreDAO::getStringListSaison()
{
    QStringList liste;
    liste << "Automne" << "Printemps";
    return liste;
}

QStringList SemestreDAO::getStringListAnnee()
{
    QDate now = QDate::currentDate();
    QDate less = now.addYears(-4);
    QDate more = now.addYears(4);

    QStringList liste;
    for (int var = less.year(); var < more.year(); ++var) {
        liste << QString::number(var);
    }
    return liste;
}

QStringList SemestreDAO::getStringList()
{
    QStringList liste;

    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());

        if(!query.exec("SELECT titre FROM semestres;"))
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        while (query.next()) {
            QSqlRecord rec = query.record();
            liste<<rec.value("titre").toString();
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("UVDAO::getStringList()",e.getMessage());
    }
    return liste;
}

int SemestreDAO::calculEcts(const int id){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        if (!query.exec("SELECT ins.semestre, SUM(ects) as ects FROM inscriptions ins LEFT JOIN categorie_uv_decorator cud ON cud.iduv = ins.uv WHERE ins.semestre = "+ QString::number(id) +";")){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
            return false;
        }else{
            if(query.first()){
                QSqlRecord rec = query.record();
                LogWriter::writeln("SemestreDAO.cpp","Calcul des crédits du semestre : " + QString::number(id));
                int res = rec.value("ects").toInt();
                SemestreDAO::getInstance()->find(id)->setComputedEcts(res);
                return res;
            }
        }

    }catch(UTProfilerException e){
        LogWriter::writeln("SemestreDAO::create()",e.getMessage());
    }

}
