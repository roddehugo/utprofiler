#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "writers/LogWriter.h"

struct Factory;

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

private:
    Ui::LoginWindow *ui;
    Factory* fac;
};

#endif // MAINWINDOW_H
