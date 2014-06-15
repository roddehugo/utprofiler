#ifndef AJOUTERUVWINDOW_H
#define AJOUTERUVWINDOW_H

#include <QDialog>
#include "dao/Factories.h"


namespace Ui {
class ajouterUVwindow;
}

class ajouterUVwindow : public QDialog
{
    Q_OBJECT

public:
    explicit ajouterUVwindow(Factory* factory,QWidget *parent = 0);
    ~ajouterUVwindow();

private:
    Ui::ajouterUVwindow *ui;
    Factory* fac;

};

#endif // AJOUTERUVWINDOW_H
