#ifndef AJOUTERUVWINDOW_H
#define AJOUTERUVWINDOW_H

#include <QDialog>
#include "dao/Factories.h"
#include <QString>
#include <QMessageBox>


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
    Factory *fac;

public slots:
    void saveUV();
};

#endif // AJOUTERUVWINDOW_H
