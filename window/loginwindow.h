#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include "writers/LogWriter.h"
#include "dao/Factories.h"

struct Factory;
class EtudiantDAO;

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(Factory* factory, QWidget *parent = 0);

    ~LoginWindow();


private slots:
    void loginMe();
    void setUpMainWindow();
    void on_ajouterEtudiant_clicked();

private:
    Ui::LoginWindow *ui;
    Factory* fac;
};

#endif // MAINWINDOW_H
