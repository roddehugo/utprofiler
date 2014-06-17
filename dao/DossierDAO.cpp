#include "dao/DossierDAO.h"
#include "dao/EtudiantDAO.h"


Dossier *DossierDAO::getCurrent() const
{
    return current;
}

void DossierDAO::setCurrent(Dossier *value)
{
    current = value;
}
QMap<int, Dossier *> DossierDAO::findAll(){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        if (!query.exec("SELECT * FROM dossiers;")){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }

        while (query.next()){
            QSqlRecord rec = query.record();
            const int id = rec.value("id").toInt();
            const QString t = rec.value("titre").toString();
            const int e = rec.value("etudiant").toInt();
            const bool s = rec.value("issolution").toBool();
            if (Map.contains(id)) {
                throw UTProfilerException("Le dossier " + QString::number(id) + " existe déjà dans la QMap");
            }else{
                LogWriter::writeln("dossier.cpp","Lecture du dossier : " + QString::number(id));
                Etudiant* etu=EtudiantDAO::getInstance()->find(e);
                Dossier* dossier=new Dossier(id,t,s,etu);
                Map.insert(id,dossier);
            }
        }

    }catch(UTProfilerException e){
        LogWriter::writeln("DossierDAO::findAll()",e.getMessage());
    }
}
QStringList DossierDAO::findByEtudiant(const int etu){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        if (!query.exec("SELECT * FROM dossiers WHERE etudiant = "+QString::number(etu)+";")){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }
        QStringList list;
        while (query.next()){
            QSqlRecord rec = query.record();
            const int id = rec.value("id").toInt();
            const QString t = rec.value("titre").toString();
            const bool s = rec.value("issolution").toBool();
            if (Map.contains(id)) {
                list << Map.value(id)->getTitre();
            }else{
                LogWriter::writeln("dossier.cpp","Lecture du dossier : " + QString::number(id));
                Etudiant* etudiant=EtudiantDAO::getInstance()->find(etu);
                Dossier* dossier=new Dossier(id,t,s,etudiant);
                Map.insert(id,dossier);
                list << dossier->getTitre();
            }
        }
        return list;

    }catch(UTProfilerException e){
        LogWriter::writeln("DossierDAO::findAll()",e.getMessage());
    }
}

Dossier *DossierDAO::findByStr(const QString &str)
{
    try{

        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("SELECT * FROM dossiers WHERE titre = :titre;");
        query.bindValue(":titre",str);
        if (!query.exec()){
            throw UTProfilerException("La requête a échoué : " + query.lastQuery());
        }
        if(query.first()){
            QSqlRecord rec = query.record();
            const int id = rec.value("id").toInt();
            const QString t = rec.value("titre").toString();
            const unsigned int e = rec.value("etudiant").toInt();
            const bool s = rec.value("issolution").toBool();
            if (Map.contains(id)) {
                return Map.value(id);
            }
            LogWriter::writeln("Dossier.cpp","Lecture du dossier : " + QString::number(id));
            Etudiant* etudiant = EtudiantDAO::getInstance()->find(e);
            Dossier* dossier = new Dossier(id,t,s,etudiant);
            return dossier;
        }else{
            throw UTProfilerException("La requete a échoué : " + query.lastQuery());
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("DossierDAO::findByStr()",e.getMessage());
    }
}

Dossier* DossierDAO::find(const int& id){
    try{
        if (Map.contains(id)) {
            return Map.value(id);
        }
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("SELECT * FROM dossiers WHERE id = :id;");
        query.bindValue(":id",id);
        if (!query.exec()){
            throw UTProfilerException("La requête a échoué : " + query.lastQuery());
        }
        if(query.first()){
            QSqlRecord rec = query.record();
            const int id = rec.value("id").toInt();
            const QString t = rec.value("titre").toString();
            const unsigned int e = rec.value("etudiant").toInt();
            const bool s = rec.value("issolution").toBool();
            LogWriter::writeln("Dossier.cpp","Lecture du dossier : " + QString::number(id));
            Etudiant* etudiant = EtudiantDAO::getInstance()->find(e);
            Dossier* dossier = new Dossier(id,t,s,etudiant);
            return dossier;
        }else{
            throw UTProfilerException("La requete a échoué : " + query.lastQuery());
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("DossierDAO::find()",e.getMessage());
    }
}

bool DossierDAO::update(Dossier* obj){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("UPDATE dosssiers SET (titre=:titre, issolution=:issolution, etudiant=:etudiant) WHERE id = :id ;");
        query.bindValue(":id", obj->ID());
        query.bindValue(":titre", obj->getTitre() );
        query.bindValue(":issolution", obj->isSolution() );
        query.bindValue(":etudiant", obj->getEtudiant()->ID() );
        if (!query.exec()){
            throw UTProfilerException("La requete a échoué : " + query.lastQuery());
            return false;
        }else{
            LogWriter::writeln("DossierDAO.cpp","Modification de l'UV : " + QString::number(obj->ID()) );
            return true;
        }

    }catch(UTProfilerException e){
        LogWriter::writeln("DossierDAO::update()",e.getMessage());
    }
}

bool DossierDAO::remove(Dossier* obj){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("DELETE FROM dossiers WHERE id = :id ;");
        query.bindValue(":id", obj->ID());
        if (!query.exec()){
            throw UTProfilerException("La requete a échoué : " + query.lastQuery());
            return false;
        }else{
            LogWriter::writeln("Dossier.cpp","Suppression du dossier : " + QString::number(obj->ID()));
            Map.erase(Map.find(obj->ID()));
            return true;
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("DossierDAO::remove()",e.getMessage());
        return false;
    }
}

bool DossierDAO::create(Dossier* obj){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("INSERT INTO dossiers (id, titre,etudiant,issolution) VALUES (NULL, :titre, :etudiant, :issolution);");
        query.bindValue(":titre", obj->getTitre());
        query.bindValue(":etudiant", obj->getEtudiant()->ID());
        query.bindValue(":issolution", obj->isSolution());
        if (!query.exec()){
            throw UTProfilerException("La requete a échoué : " + query.lastQuery());
            return false;
        }else{
            int i=query.lastInsertId().toInt();
            obj->setID(i);
            Map.insert(i,obj);
            LogWriter::writeln("DossierDAO.cpp","Création du dossier : " + QString::number(obj->ID()));
            return true;
        }

    }catch(UTProfilerException e){
        LogWriter::writeln("DossierDAO::create()",e.getMessage());
        return false;
    }
}

QMap<QString, int> DossierDAO::getCursusMap(unsigned int id)
{

    QMap<QString,int> cursusmap;
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("SELECT d.id ,cur.code, current FROM dossiers d JOIN cursus_dossiers cd ON cd.iddossier = d.id JOIN cursus cur ON cur.id = cd.idcursus WHERE d.id = :id;");
        query.bindValue(":id",id);
        if (!query.exec()){
            throw UTProfilerException("La requête a échoué : " + query.lastQuery());
        }
        while (query.next()){
            QSqlRecord rec = query.record();
            cursusmap.insert(rec.value("titre").toString(),rec.value("current").toInt());
        }
        return cursusmap;

    }catch(UTProfilerException e){
        LogWriter::writeln("UVDAO::getCursusMap()",e.getMessage());}


}

