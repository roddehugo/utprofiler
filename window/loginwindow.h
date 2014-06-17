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
/**
 * @brief classe loginwindow
 * @details 
 * 
 */
class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
	/**
	 * @brief constructeur loginwindow
	 * @details 
	 * @return 
	 */
    explicit LoginWindow(Factory* factory, QWidget *parent = 0);

    ~LoginWindow();


private slots:
/**
 * @brief slot du login 
 * @details 
 */
    void loginMe();
 /**
  * @brief slot pour afficher mainwindow
  * @details 
  */  
  void setUpMainWindow();
 
    void on_ajouterEtudiant_clicked();

private:
    Ui::LoginWindow *ui;
    Factory* fac;
};

#endif // MAINWINDOW_H
