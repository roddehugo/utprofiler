#ifndef MODIFUVWINDOW_H
#define MODIFUVWINDOW_H

#include <QDialog>
#include "dao/Factories.h"

namespace Ui {
class modifUVwindow;
}

class modifUVwindow : public QDialog
{
    Q_OBJECT

public:
    explicit modifUVwindow(Factory* factory,QWidget *parent = 0);
    ~modifUVwindow();

private:
    Ui::modifUVwindow *ui;
    Factory* fac;
};

#endif // MODIFUVWINDOW_H
