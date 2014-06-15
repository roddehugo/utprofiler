#ifndef AJOUTDOSSIER_H
#define AJOUTDOSSIER_H

#include <QDialog>
#include "dao/Factories.h"

namespace Ui {
class ajoutDossier;
}

class ajoutDossier : public QDialog
{
    Q_OBJECT

public:
    explicit ajoutDossier(Factory* factory,QWidget *parent = 0);
    ~ajoutDossier();

private:
    Ui::ajoutDossier *ui;
    Factory* fac;
};

#endif // AJOUTDOSSIER_H
