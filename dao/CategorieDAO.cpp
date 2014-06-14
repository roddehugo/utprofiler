#include "dao/CategorieDAO.h"

QMap<int, Creditable *> CategorieDAO::findAll(){
    LogWriter::writeln("CategorieDAO.cpp","Impossible de récupérer toutes les catégories.");

    return Map;
}

Creditable* CategorieDAO::find(const int& id){

}

bool CategorieDAO::update(const int& id, Creditable* obj){

    return false;
}

bool CategorieDAO::remove(const int& id, Creditable* obj){

    return false;
}

bool CategorieDAO::create(Creditable* obj){

    return false;
}
