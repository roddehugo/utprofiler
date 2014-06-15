#ifndef MODIFIERCURSUSWINDOW_H
#define MODIFIERCURSUSWINDOW_H

#include <QDialog>
#include "dao/Factories.h"

namespace Ui {
class modifiercursuswindow;
}

class modifiercursuswindow : public QDialog
{
    Q_OBJECT

public:
    explicit modifiercursuswindow(Factory* factory,QWidget *parent = 0);
    ~modifiercursuswindow();

private:
    Ui::modifiercursuswindow *ui;
    Factory* fac;
};

#endif // MODIFIERCURSUSWINDOW_H
