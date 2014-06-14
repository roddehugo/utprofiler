#include "dao/CategorieDAO.h"


Creditable* parse(const QString& code,const QString& t,const unsigned int& c, Creditable& creditable){
    if (code =="TM")
        Creditable* newcreditable=new TM(t,c,creditable);
    if (code=="CS")
        Creditable* newcreditable= new CS(t,c,creditable);
//    if (code=="TSH")
//        Creditable* newcreditable= new TSH(t,c,creditable,col,lig);
    if (code=="SP")
        Creditable* newcreditable= new SP(t,c,creditable);
}


//QMap<int, Creditable *> CategorieDAO::findAll(){
//    LogWriter::writeln("CategorieDAO.cpp","Impossible de récupérer toutes les catégories.");

//    return ;
//}
//Creditable* CategorieDAO::find(const int& id){
//    if (categoriemap.contains(id)) {
//        return categoriemap.value(id);
//    }
//    QSqlQuery query(Connexion::getInstance()->getDataBase());
//    if (!query.exec("SELECT * FROM categories WHERE id = " + QString(id) + ";")){
//        throw UTProfilerException("La requète a échoué : " + query.lastQuery());
//    }
//    if(query.first()){
//        QSqlRecord rec = query.record();
//        const QString c = rec.value("code").toString();
//        const QString t = rec.value("titre").toString();
//        const int e = rec.value("ects").toInt();
//        const int creditable = rec.value("creditable").toInt();
//        LogWriter::writeln("UVDAO.cpp","Lecture de l'UV : " + c);

//        return parse(c,t,e,creditable);
//    }else{
//        throw UTProfilerException("La requète a échoué : " + query.lastQuery());
//    }
//}
void CategorieDAO::create(Creditable* obj){
    QSqlQuery query(Connexion::getInstance()->getDataBase());
    query.prepare("INSERT INTO uvs (id, code, titre) VALUES (:id, :code, :titre, :categorie, :automne, :printemps, :demiuv);");
    query.bindValue(":id", "NULL");
    query.bindValue(":code", obj.getCode() );
    query.bindValue(":titre", obj.getTitre() );
    query.bindValue(":categorie", obj.getCategorie() );
    query.bindValue(":automne", obj.getAutomne() );
    query.bindValue(":printemps", obj.getPrintemps() );
    query.bindValue(":demiuv", obj.getDemiUV() );
    if (!query.exec()){
        throw UTProfilerException("La requète a échoué : " + query.lastQuery());
    }else{
        LogWriter::writeln("UVDAO.cpp","Création de l'UV : " + obj.getCode());
    }
}
