#ifndef AJOUTUVWINDOW_H
#define AJOUTUVWINDOW_H

#include <QMainWindow>
#include "dao/Factories.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Factory* factory,QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    Factory* fac;

private slots :
     void on_ajouteruv();
     void modifieruv();
    void suppruv();
    void ajoutercursus();
    void modifiercursus();
    void supprcursus();
    void on_remplirDossier_clicked();
};

#endif
