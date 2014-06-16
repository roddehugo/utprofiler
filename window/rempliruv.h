#ifndef REMPLIRUV_H
#define REMPLIRUV_H

#include "dao/Factories.h"
#include <QTableWidget>
#include <QListWidget>
#include <QDialog>
#include <QDebug>

namespace Ui {
class RemplirUV;
}

class RemplirUV : public QDialog
{
    Q_OBJECT

public:
    explicit RemplirUV(Factory* factory,QWidget *parent = 0);
    ~RemplirUV();

public slots:
    void on_ajouterItem();
    void on_retirerItem();

private:

    QTableWidget* m_pTableWidget;

    QStringList m_TableHeader;

    Ui::RemplirUV *ui;
    Factory* fac;
};

#endif // REMPLIRUV_H
