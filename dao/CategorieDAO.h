#ifndef CATEGORIEDAO_H
#define CATEGORIEDAO_H

#include "dao/SqlDAOTemplate.h"
#include "decorator/Creditable.h"
#include "decorator/CS.h"
#include "decorator/TM.h"
#include "decorator/TSH.h"
#include "decorator/SP.h"
#include <QListWidget>


class CategorieDAO : public Singleton<CategorieDAO>{
    friend class Singleton<CategorieDAO>;

public:

    QMap<int, QString> findAll();

    QString find(const int &id);

    int findbyStr(QString str);

    bool update(QString str);

    bool remove(QString str);

    bool create(QString str);

    QString parse(const QString& code,const QString& titre,const unsigned int& ects,const QString& creditable);
    QMap<int, QString> getMap() const{
        return Map;
    }

    void setMap(const QMap<int, QString> &value){
        Map = value;

    }

    CategorieDAO(){}
    ~CategorieDAO(){}

    QStringList getStringList(QString colonne);
    protected:
    QMap<int,QString> Map;

};




















#endif // CATEGORIEDAO_H
