#ifndef SUPPRIMERUVWINDOW_H
#define SUPPRIMERUVWINDOW_H

#include <QDialog>
#include "dao/Factories.h"

namespace Ui {
class supprimerUVwindow;
}

class supprimerUVwindow : public QDialog
{
    Q_OBJECT

public:
    explicit supprimerUVwindow(Factory* factory,QWidget *parent = 0);
    ~supprimerUVwindow();

private:
    Ui::supprimerUVwindow *ui;
    Factory* fac;
};

#endif // SUPPRIMERUVWINDOW_H
