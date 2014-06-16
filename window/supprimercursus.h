#ifndef SUPPRIMERCURSUS_H
#define SUPPRIMERCURSUS_H

#include <QDialog>
#include "dao/Factories.h"

namespace Ui {
class supprimerCursus;
}

class supprimerCursus : public QDialog
{
    Q_OBJECT

public:
    explicit supprimerCursus(Factory* factory,QWidget *parent = 0);
    ~supprimerCursus();

private:
    Ui::supprimerCursus *ui;
    Factory* fac;
public slots:
    void delCursus();
};

#endif // SUPPRIMERCURSUS_H
