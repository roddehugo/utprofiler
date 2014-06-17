#ifndef AJOUTSEMESTRES_H
#define AJOUTSEMESTRES_H

#include <QDialog>
#include "dao/Factories.h"
#include <QTableWidget>
#include <QListWidget>
#include <QDialog>
#include <QDebug>
namespace Ui {
   
class ajoutSemestres;
}
 /**
     * @brief classe QDialog ajout semestre
     * @details 
     * @return 
     */
class ajoutSemestres : public QDialog
{
    Q_OBJECT

public:
    explicit ajoutSemestres(Factory* factory,QWidget *parent = 0);
    ~ajoutSemestres();

public slots:
    void saveDossier();
    void on_ajouterItem();
    void on_retirerItem();
    void deleteSemestres();
private:

    QTableWidget* m_pTableWidget;

    QStringList m_TableHeader;

    Ui::ajoutSemestres *ui;
    Factory* fac;

    QList<Semestre*> toDelete;
};

#endif // AJOUTSEMESTRES_H
