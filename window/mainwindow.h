#ifndef AJOUTUVWINDOW_H
#define AJOUTUVWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
private slots :
     void on_ajouteruv();
     void modifieruv();
    void suppruv();
    void ajoutercursus();
    void modifiercursus();
    void supprcursus();

};

#endif
