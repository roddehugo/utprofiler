#ifndef AJOUTDOSSIER_H
#define AJOUTDOSSIER_H

#include <QDialog>
#include "dao/Factories.h"
#include <QTableWidget>
#include <QListWidget>
#include <QDialog>
#include <QDebug>
namespace Ui {
class ajoutDossier;
}

class ajoutDossier : public QDialog
{
    Q_OBJECT

public:
    explicit ajoutDossier(Factory* factory,QWidget *parent = 0);
    ~ajoutDossier();

public slots:
    void saveDossier();
    void on_ajouterItem();
    void on_retirerItem();
private:

    QTableWidget* m_pTableWidget;

    QStringList m_TableHeader;

    Ui::ajoutDossier *ui;
    Factory* fac;
};

#endif // AJOUTDOSSIER_H
