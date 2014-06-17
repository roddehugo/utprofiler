#ifndef REMPLIRUV_H
#define REMPLIRUV_H

#include "dao/Factories.h"
#include <QTableWidget>
#include <QListWidget>
#include <QDialog>
#include <QDebug>

namespace Ui {
class saisirinscription;
}

class saisirinscription : public QDialog
{
    Q_OBJECT

public:
    explicit saisirinscription(Factory* factory,QWidget *parent = 0);
    ~saisirinscription();

public slots:
    void on_ajouterItem();
    void on_retirerItem();
    void saveInscription();

private:
    Ui::saisirinscription *ui;
    Factory* fac;
};

#endif // REMPLIRUV_H
