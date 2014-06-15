#include "dao/CategorieDAO.h"

QMap<int, Creditable *> CategorieDAO::findAll(){
    LogWriter::writeln("CategorieDAO.cpp","Impossible de récupérer toutes les catégories.");

    return Map;
}

Creditable* CategorieDAO::find(const int& id){

}

bool CategorieDAO::update(Creditable* obj){

    return false;
}

bool CategorieDAO::remove(Creditable* obj){

    return false;
}

bool CategorieDAO::create(Creditable* obj){

    return false;
}
