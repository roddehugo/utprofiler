#ifndef AJOUTCURSUSWINDOW_H
#define AJOUTCURSUSWINDOW_H

#include <QDialog>
#include "dao/Factories.h"

namespace Ui {
class ajoutcursuswindow;
}

class ajoutcursuswindow : public QDialog
{
    Q_OBJECT

public:
    explicit ajoutcursuswindow(Factory* factory,QWidget *parent = 0);
    ~ajoutcursuswindow();

private:
    Ui::ajoutcursuswindow *ui;
    Factory* fac;
};

#endif // AJOUTCURSUSWINDOW_H
