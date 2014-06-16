#include "dao/CategorieDAO.h"



QMap<int, QString> CategorieDAO::findAll(){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        if (!query.exec("SELECT * FROM categories;")){
            throw UTProfilerException("La requète a échoué : " + query.lastQuery());
        }

        while (query.next()){
            QSqlRecord rec = query.record();
            const int id = rec.value("id").toInt();
            const QString t = rec.value("titre").toString();
            if (Map.contains(id)) {
                throw UTProfilerException("La categorie "+QString::number(id)+" existe déjà dans la QMap");
            }else{
                LogWriter::writeln("CategorieDAO.cpp","Lecture des categories : " + QString::number(id));


            }
        }

        return Map;
    }catch(UTProfilerException e){
        LogWriter::writeln("CategorieDAO::findAll()",e.getMessage());
    }
}

QString CategorieDAO::find(const int& id){
    try{
        if (Map.contains(id)) {
            return Map.value(id);
        }
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        if (!query.exec("SELECT * FROM cursus WHERE id = " + QString(id) + ";")){
            throw UTProfilerException("La requete a échoué : " + query.lastQuery());
        }
        if(query.first()){
            QSqlRecord rec = query.record();
            const int id = rec.value("id").toInt();
            const QString t = rec.value("titre").toString();

            LogWriter::writeln("Categorie.cpp","Lecture de l categorie : " + t);
            Map.insert(id,t);
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("CategorieDAO::find()",e.getMessage());
    }
}

bool CategorieDAO::update(QString str){

    return false;
}
int CategorieDAO::findByStr(QString str){
    try {

        if (!Map.key(str)){
            QSqlQuery query(Connexion::getInstance()->getDataBase());
            query.prepare("SELECT id FROM categories WHERE titre = :s ;");
            query.bindValue(":s", str);
            if (!query.exec()){
                throw UTProfilerException("La requete a échoué : " + query.lastQuery());
                return false;}
            if(query.first()){
                QSqlRecord rec = query.record();
                const int id = rec.value("id").toInt();
                const QString t = rec.value("titre").toString();
                LogWriter::writeln("Categorie.cpp","Lecture de la categorie : " + str);
                Map.insert(id,t);
            }
        }
        else{
            LogWriter::writeln("Categorie.cpp","Lecture de la categorie depuis la map: " + str);
            return Map.key(str);
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("CategorieDAO::findbyStr()",e.getMessage());
    }
}

bool CategorieDAO::remove(QString str){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("DELETE FROM categories WHERE id = :id ;");
        query.bindValue(":s", str);
        if (!query.exec()){
            throw UTProfilerException("La requete a échoué : " + query.lastQuery());
            return false;
        }else{
            LogWriter::writeln("categories.cpp","Suppression de la categorie : " + str);
            Map.erase(Map.find(Map.key(str)));
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("DesiderataDAO::remove()",e.getMessage());
    }
    return false;
}

bool CategorieDAO::create(QString str){
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("INSERT INTO categories (id, titre) VALUES (NULL, :titre);");
        query.bindValue(":titre",str );
        if (!query.exec()){
            throw UTProfilerException("La requête a échoué : " + query.lastQuery());
            return false;
        }else{
            int i=query.lastInsertId().toInt();
            Map.insert(i,str);
            LogWriter::writeln("categorie.cpp","Création de la categorie : " + str);
            return true;
        }

    }catch(UTProfilerException e){
        LogWriter::writeln("Categorie::create()",e.getMessage());
    }
    return false;
}


QStringList CategorieDAO::getStringList(const QString colonne)
{
    QStringList liste;
    try{
        QSqlQuery query(Connexion::getInstance()->getDataBase());
        query.prepare("SELECT "+colonne+" FROM categories;");
        if (!query.exec()){
            throw UTProfilerException("La requête a échoué : " + query.lastQuery());
        }
        while (query.next()){
            QSqlRecord rec = query.record();
            liste<<(rec.value(0).toString());
        }
    }catch(UTProfilerException e){
        LogWriter::writeln("Categorie::getColonne()",e.getMessage());}

    return liste;
}


QMap<int, QString> CategorieDAO::getMap() const
{
    return Map;
}

void CategorieDAO::setMap(const QMap<int, QString> &value)
{
    Map = value;
}


