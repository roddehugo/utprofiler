#include "loginwindow.h"
#include "mainwindow.h"
#include "ui_loginwindow.h"
#include <QApplication>
#include <QMessageBox>

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

void LoginWindow::setUpMainWindow(){
    LoginWindow::hide();
    MainWindow* m= new MainWindow(fac);
    m->show();
}

void LoginWindow::loginMe(){
    LogWriter::writeln("LoginWindow.cpp","Login action");
    EtudiantDAO* etudao = fac->getEtudiantDAO();
    Etudiant* me = etudao->findByLogin(ui->loginEdit->text());
    if(!me){
        QMessageBox msgBox;
        msgBox.setText("Aucun utilisateur trouvé.");
        msgBox.exec();
    }else{
        etudao->setCurrent(me);
        setUpMainWindow();
    }
}

void LoginWindow::on_ajouterEtudiant_clicked()
{
    LogWriter::writeln("LoginWindow.cpp","Ajouter étudiant action");
    const QString login = ui->newLogin->text();
    const QString prenom = ui->newPrenom->text();
    const QString nom = ui->newNom->text();
    EtudiantDAO* etudao = fac->getEtudiantDAO();
    Etudiant* me=new Etudiant(login,prenom,nom);
    if(etudao->create(new Etudiant(login,prenom,nom))){
        etudao->setCurrent(me);
        setUpMainWindow();
    }else{
        QMessageBox msgBox;
        msgBox.setText("Impossible d'ajouter l'utilisateur.");
        msgBox.exec();
    }
}
