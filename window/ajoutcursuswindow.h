#ifndef AJOUTCURSUSWINDOW_H
#define AJOUTCURSUSWINDOW_H

#include <QDialog>
#include "dao/Factories.h"
#include "dossier/Cursus.h"

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
public slots:
    void saveCursus();
    void ajoutCat();
    void retireCat();

};

#endif // AJOUTCURSUSWINDOW_H
