#ifndef CATEGORIEDAO_H
#define CATEGORIEDAO_H

#include "dao/SqlDAOTemplate.h"
#include <QListWidget>
#include <QStringList>
#include <QString>



class CategorieDAO : public Singleton<CategorieDAO>{

    friend class Singleton<CategorieDAO>;

public:

    QStringList getStringList(const QString colonne);

    QMap<int, QString> findAll();

    QString find(const int &id);

    bool update(QString str);

    bool remove(QString str);

    bool create(QString str);

    int findByStr(QString str);

    QMap<int, QString> getMap() const;

    void setMap(const QMap<int, QString> &value);

    CategorieDAO(){}
    ~CategorieDAO(){}

protected:
    QMap<int,QString> Map;

};


#endif // CATEGORIEDAO_H
