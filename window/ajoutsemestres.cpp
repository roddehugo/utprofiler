#include "ajoutsemestres.h"
#include "ui_ajoutsemestres.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QtCore/QCoreApplication>
#include <QHeaderView>
#include <QMessageBox>

ajoutSemestres::ajoutSemestres(Factory* factory,QWidget *parent) :
    QDialog(parent),
    m_pTableWidget(NULL),
    ui(new Ui::ajoutSemestres),
    fac(factory)
{
    ui->setupUi(this);
    ui->cursusCombo->addItems(fac->getCursusDAO()->getStringList("code"));
    ui->anneeCombo->addItems(fac->getSemestreDAO()->getStringListAnnee());
    ui->saisonCombo->addItems(fac->getSemestreDAO()->getStringListSaison());

    m_pTableWidget = new QTableWidget(ui->frame);
    m_pTableWidget->setRowCount(0);
    m_pTableWidget->setColumnCount(6);
    m_pTableWidget->verticalHeader()->setVisible(false);
    m_pTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_pTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_pTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    m_pTableWidget->setShowGrid(true);
    m_pTableWidget->setGeometry(QApplication::desktop()->screenGeometry());
    m_pTableWidget->horizontalHeader()->setStretchLastSection(true);
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
    QTableWidgetItem *h6 = new QTableWidgetItem("Dossier");
    h6->setTextAlignment(Qt::AlignLeft);
    m_pTableWidget->setHorizontalHeaderItem(0,h1);
    m_pTableWidget->setHorizontalHeaderItem(1,h2);
    m_pTableWidget->setHorizontalHeaderItem(2,h3);
    m_pTableWidget->setHorizontalHeaderItem(3,h4);
    m_pTableWidget->setHorizontalHeaderItem(4,h5);
    m_pTableWidget->setHorizontalHeaderItem(4,h6);
    m_pTableWidget->setFixedSize(553,370);

    connect(ui->ajouterBouton,SIGNAL(clicked()),this, SLOT(on_ajouterItem()));
    connect(ui->retirerBouton,SIGNAL(clicked()),this, SLOT(on_retirerItem()));
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(saveDossier()));
}

void ajoutSemestres::on_ajouterItem()
{
    int row = m_pTableWidget->rowCount();
    m_pTableWidget->setRowCount(row+1);
    m_pTableWidget->setItem(row, 4, new QTableWidgetItem(ui->cursusCombo->currentText()) );
    m_pTableWidget->setItem(row, 3, new QTableWidgetItem(ui->etrangerRadio->isChecked() ? "oui" : "non") );
    m_pTableWidget->setItem(row, 2, new QTableWidgetItem(ui->anneeCombo->currentText()) );
    m_pTableWidget->setItem(row, 1, new QTableWidgetItem(ui->saisonCombo->currentText()) );
    m_pTableWidget->setItem(row, 0, new QTableWidgetItem(ui->titreEdit->text()) );
}

void ajoutSemestres::on_retirerItem()
{
    QList<QTableWidgetItem *> l = m_pTableWidget->selectedItems();
    if(!l.empty()){
        m_pTableWidget->removeRow(l.first()->row());
    }

}

ajoutSemestres::~ajoutSemestres()
{
    delete ui;
}

void ajoutSemestres::saveDossier()
{
    int row = m_pTableWidget->rowCount();
    for (int i = 0; i < row ; ++i)
    {
        const QString titre = m_pTableWidget->item(i,0)->text();
        const Saison saison = Semestre::str2saison(m_pTableWidget->item(i,1)->text());
        const int annee = m_pTableWidget->item(i,2)->text().toInt();
        const bool etranger = (m_pTableWidget->item(i,3)->text() == "oui" ? true : false);
        const QString code = m_pTableWidget->item(i,4)->text();

        Cursus* cursus = fac->getCursusDAO()->findByCode(code);
        fac->getSemestreDAO()->create(new Semestre(titre,saison,annee,etranger,cursus));
    }
}
