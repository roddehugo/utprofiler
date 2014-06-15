#ifndef REMPLIRDOSSIER_H
#define REMPLIRDOSSIER_H

#include <QDialog>
#include "dao/Factories.h"

namespace Ui {
class remplirDossier;
}

class remplirDossier : public QDialog
{
    Q_OBJECT

public:
    explicit remplirDossier(Factory* factory,QWidget *parent = 0);
    ~remplirDossier();

private:
    Ui::remplirDossier *ui;
    Factory* fac;
};

#endif // REMPLIRDOSSIER_H
