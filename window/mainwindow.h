#ifndef AJOUTUVWINDOW_H
#define AJOUTUVWINDOW_H

#include "dao/Factories.h"
#include <QMainWindow>
#include <QTableWidget>
#include <QTreeWidget>
#include <QTableView>
#include <QInputDialog>

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
    Etudiant* currentEtudiant;
    Dossier* currentDossier;
    QStringList listDossiers;

private slots :
    void on_ajouteruv();
    void modifieruv();
    void suppruv();
    void ajoutercursus();
    void modifiercursus();
    void supprcursus();
    void on_remplirDossier_clicked();
    void exigerUV();
    void prefererUV();
    void rejeterUV();
    void retirerpref();

    void fillMainWindow();
    void on_ajouterDossier_clicked();
    void on_inscrireSemestre_clicked();
    void on_dossierCombo_currentTextChanged(const QString &arg1);
};

#endif
