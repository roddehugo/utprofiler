#include "ajoutsemestres.h"
#include "ui_ajoutsemestres.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QtCore/QCoreApplication>
#include <QHeaderView>
#include <QMessageBox>

ajoutSemestres::ajoutSemestres(Factory* factory,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajoutSemestres),
    fac(factory)
{
    ui->setupUi(this);
    ui->cursusCombo->addItems(fac->getCursusDAO()->getStringList("code"));
    ui->anneeCombo->addItems(fac->getSemestreDAO()->getStringListAnnee());
    ui->saisonCombo->addItems(fac->getSemestreDAO()->getStringListSaison());

    ui->m_pTableWidget->setRowCount(0);
    ui->m_pTableWidget->setColumnCount(5);
    ui->m_pTableWidget->verticalHeader()->setVisible(false);
    ui->m_pTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->m_pTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->m_pTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->m_pTableWidget->setShowGrid(true);
    ui->m_pTableWidget->setGeometry(QApplication::desktop()->screenGeometry());
    ui->m_pTableWidget->horizontalHeader()->setStretchLastSection(true);
    QTableWidgetItem *h1 = new QTableWidgetItem("Titre");
    h1->setTextAlignment(Qt::AlignLeft);
    QTableWidgetItem *h2 = new QTableWidgetItem("Saison");
    h2->setTextAlignment(Qt::AlignLeft);
    QTableWidgetItem *h3 = new QTableWidgetItem("Année");
    h3->setTextAlignment(Qt::AlignLeft);
    QTableWidgetItem *h4 = new QTableWidgetItem("Etranger");
    h4->setTextAlignment(Qt::AlignLeft);
    QTableWidgetItem *h5 = new QTableWidgetItem("Cursus");
    h5->setTextAlignment(Qt::AlignLeft);
    ui->m_pTableWidget->setHorizontalHeaderItem(0,h1);
    ui->m_pTableWidget->setHorizontalHeaderItem(1,h2);
    ui->m_pTableWidget->setHorizontalHeaderItem(2,h3);
    ui->m_pTableWidget->setHorizontalHeaderItem(3,h4);
    ui->m_pTableWidget->setHorizontalHeaderItem(4,h5);

    QMap<int,Semestre*> all = fac->getSemestreDAO()->findAll();
    int row = ui->m_pTableWidget->rowCount();

    for(QMap<int,Semestre*>::const_iterator i = all.begin(); i != all.end(); ++i){
        ui->m_pTableWidget->setRowCount(row+1);
        ui->m_pTableWidget->setItem(row, 4, new QTableWidgetItem(i.value()->getCursus()->getCode()) );
        ui->m_pTableWidget->setItem(row, 3, new QTableWidgetItem(i.value()->isEtranger() ? "oui" : "non") );
        ui->m_pTableWidget->setItem(row, 2, new QTableWidgetItem( QString::number(i.value()->getAnnee()) ) );
        ui->m_pTableWidget->setItem(row, 1, new QTableWidgetItem( Semestre::saison2str(i.value()->getSaison()) ) );
        ui->m_pTableWidget->setItem(row, 0, new QTableWidgetItem(i.value()->getTitre()) );
        row++;
    }


    connect(ui->ajouterBouton,SIGNAL(clicked()),this, SLOT(on_ajouterItem()));
    connect(ui->retirerBouton,SIGNAL(clicked()),this, SLOT(on_retirerItem()));
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(saveDossier()));
    connect(ui->buttonBox,SIGNAL(rejected()),this,SLOT(deleteSemestres()));
}

void ajoutSemestres::on_ajouterItem()
{
    int row = ui->m_pTableWidget->rowCount();
    ui->m_pTableWidget->setRowCount(row+1);
    ui->m_pTableWidget->setItem(row, 4, new QTableWidgetItem(ui->cursusCombo->currentText()) );
    ui->m_pTableWidget->setItem(row, 3, new QTableWidgetItem(ui->etrangerRadio->isChecked() ? "oui" : "non") );
    ui->m_pTableWidget->setItem(row, 2, new QTableWidgetItem(ui->anneeCombo->currentText()) );
    ui->m_pTableWidget->setItem(row, 1, new QTableWidgetItem(ui->saisonCombo->currentText()) );
    ui->m_pTableWidget->setItem(row, 0, new QTableWidgetItem(ui->titreEdit->text()) );
}

void ajoutSemestres::on_retirerItem()
{
    QList<QTableWidgetItem *> l = ui->m_pTableWidget->selectedItems();
    if(!l.empty()){
        ui->m_pTableWidget->removeRow(l.first()->row());
        toDelete << fac->getSemestreDAO()->findByStr(l.first()->text());
    }

}

ajoutSemestres::~ajoutSemestres()
{
    delete ui;
}

void ajoutSemestres::saveDossier()
{
    deleteSemestres();
    int row = ui->m_pTableWidget->rowCount();
    for (int i = 0; i < row ; ++i)
    {
        const QString titre = ui->m_pTableWidget->item(i,0)->text();
        const Saison saison = Semestre::str2saison(ui->m_pTableWidget->item(i,1)->text());
        const int annee = ui->m_pTableWidget->item(i,2)->text().toInt();
        const bool etranger = (ui->m_pTableWidget->item(i,3)->text() == "oui" ? true : false);
        const QString code = ui->m_pTableWidget->item(i,4)->text();

        Cursus* cursus = fac->getCursusDAO()->findByCode(code);
        fac->getSemestreDAO()->create(new Semestre(titre,saison,annee,etranger,cursus));
    }
}

void ajoutSemestres::deleteSemestres(){

    for(QList<Semestre *>::const_iterator s = toDelete.begin(); s != toDelete.end(); ++s){
        fac->getSemestreDAO()->remove( (*s) );
    }

    toDelete.clear();
}
