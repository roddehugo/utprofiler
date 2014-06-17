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
/**
 * @brief classe mainwindow
 * @details 
 * @return 
 */
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
/**
 * @brief accede au menu ajouteruv
 * @details 
  */
    void on_ajouteruv();
    /**
 * @brief accede au menu modifieruv
 * @details 
 */
    void modifieruv();
     /**
 * @brief accede au menu suppression uv
 * @details 
 */
    void suppruv();
     /**
 * @brief accede au menu ajoutercursus
 * @details 
 */
    void ajoutercursus();
     /**
 * @brief accede au menu modification cursus
 * @details 
 */
    void modifiercursus();
     /**
 * @brief accede au menu suppression cursus
 * @details 
 */
    void supprcursus();
    /**
     * @brief accede au QDialog remplisagedossier
     * @details 
     */
    void on_remplirDossier_clicked();

    void exigerUV();
    void prefererUV();
    void rejeterUV();
    void retirerpref();
  /**
     * @brief remplis les champs de la MainWindo
     * @details 
     */
    void fillMainWindow();
    void on_ajouterDossier_clicked();
    void on_inscrireSemestre_clicked();
    void on_dossierCombo_currentTextChanged(const QString &arg1);
};

#endif
