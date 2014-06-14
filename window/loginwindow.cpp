#include "window/loginwindow.h"
#include "ui_loginwindow.h"
#include <QDebug>

LoginWindow::LoginWindow(Factory *factory, QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::LoginWindow()),
    fac(factory)
{
    ui->setupUi(this);

    QObject::connect(ui->seConnecter, SIGNAL(clicked()), this, SLOT(loginMe()));
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::loginMe(){
    LogWriter::writeln("LoginWindow.cpp","Login action");


}
