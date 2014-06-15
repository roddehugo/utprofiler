#ifndef AJOUTERUVWINDOW_H
#define AJOUTERUVWINDOW_H

#include <QDialog>
#include "dao/Factories.h"
#include <QString>
#include <QMessageBox>
#include <QListWidget>
#include <QTableView>
#include <QStandardItemModel>


namespace Ui {
class ajouterUVwindow;
}

class ajouterUVwindow : public QDialog
{
    Q_OBJECT

public:
    explicit ajouterUVwindow(Factory* factory,QWidget *parent = 0);
    ~ajouterUVwindow();
//    static void ajoutItem(QListWidget *liste1,  QListWidget *liste2) ;
    void ajoutCategorie(QListWidget *listCat,  QListWidget* listeCategorieCol, QListWidget *listeCreditCol, QString  valcredit);
    void ajoutCursus(QListWidget *listCursus,  QListWidget* listeCursusAjoute);
    void retraitCategorie(QListWidget *listCat,  QListWidget* listeCategorieCol, QListWidget *listeCreditCol);
    void retraitCursus(QListWidget *listCursus,  QListWidget* listeCursusAjoute);
private:
    Ui::ajouterUVwindow *ui;
    Factory *fac;

public slots:
    void saveUV();
    void addcursus();
    void addcredit();
    void removecredit();
    void removecursus();
    void valcredit();

};

#endif // AJOUTERUVWINDOW_H
