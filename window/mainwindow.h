#ifndef AJOUTUVWINDOW_H
#define AJOUTUVWINDOW_H

#include <QMainWindow>
#include<QTableWidget>
#include "dao/Factories.h"
#include <QTableView>

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
    QTableWidget* m_pTableWidget;
    QStringList m_TableHeader;

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
};

#endif
