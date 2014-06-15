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
            const int e = rec.value("categorie").toInt();
            const int cred = rec.value("creditable").toInt();
            if (Map.contains(id)) {
                throw UTProfilerException("La categorie "+QString::number(id)+" existe déjà dans la QMap");
            }else{
                LogWriter::writeln("CategorieDAO.cpp","Lecture des categories : " + QString::number(id));
                //Creditable*
                //Map.insert(id,);
            }
        }

        //return Map;
    }catch(UTProfilerException e){
        LogWriter::writeln("CategorieDAO::findAll()",e.getMessage());
    }
}

QString CategorieDAO::find(const int& id){

}

bool CategorieDAO::update(QString str){

    return false;
}

bool CategorieDAO::remove(QString str){

    return false;
}

bool CategorieDAO::create(QString str){

    return false;
}


int CategorieDAO::findByString(QString str)
{

}
