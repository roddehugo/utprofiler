#include "rempliruv.h"
#include "ui_rempliruv.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QtCore/QCoreApplication>
#include <QHeaderView>
#include <QMessageBox>

RemplirUV::RemplirUV(Factory* factory,QWidget *parent) :
    QDialog(parent),
    m_pTableWidget(NULL),
    fac(factory),
    ui(new Ui::RemplirUV)
{
    ui->setupUi(this);

    ui->anneeCombo->addItems(fac->getSemestreDAO()->getStringListAnnee());
    ui->resultatCombo->addItems(fac->getInscriptionDAO()->getStringListResultat());
    ui->saisonCombo->addItems(fac->getSemestreDAO()->getStringListSaison());
    ui->listAll->addItems(fac->getUVDAO()->getStringList("code"));

    m_pTableWidget = new QTableWidget(ui->frame);
    m_pTableWidget->setRowCount(0);
    m_pTableWidget->setColumnCount(4);
    m_pTableWidget->verticalHeader()->setVisible(false);
    m_pTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_pTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_pTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    m_pTableWidget->setShowGrid(true);
    m_pTableWidget->setGeometry(QApplication::desktop()->screenGeometry());
    m_pTableWidget->horizontalHeader()->setStretchLastSection(true);
    QTableWidgetItem *h1 = new QTableWidgetItem("UV");
    h1->setTextAlignment(Qt::AlignLeft);
    QTableWidgetItem *h2 = new QTableWidgetItem("Saison");
    h2->setTextAlignment(Qt::AlignLeft);
    QTableWidgetItem *h3 = new QTableWidgetItem("Année");
    h3->setTextAlignment(Qt::AlignLeft);
    QTableWidgetItem *h4 = new QTableWidgetItem("Résultat");
    h4->setTextAlignment(Qt::AlignLeft);
    m_pTableWidget->setHorizontalHeaderItem(0,h1);
    m_pTableWidget->setHorizontalHeaderItem(1,h2);
    m_pTableWidget->setHorizontalHeaderItem(2,h3);
    m_pTableWidget->setHorizontalHeaderItem(3,h4);
    m_pTableWidget->setFixedSize(425,308);

    connect(ui->ajouterBouton,SIGNAL(clicked()),this, SLOT(on_ajouterItem()));
    connect(ui->retirerBouton,SIGNAL(clicked()),this, SLOT(on_retirerItem()));

}

void RemplirUV::on_ajouterItem()
{

    int row = m_pTableWidget->rowCount();
    m_pTableWidget->setRowCount(row+1);
    m_pTableWidget->setItem(row, 0, new QTableWidgetItem(ui->listAll->currentItem()->text()) );
    m_pTableWidget->setItem(row, 1, new QTableWidgetItem(ui->anneeCombo->currentText()) );
    m_pTableWidget->setItem(row, 2, new QTableWidgetItem(ui->saisonCombo->currentText()) );
    m_pTableWidget->setItem(row, 3, new QTableWidgetItem(ui->resultatCombo->currentText()) );


    delete ui->listAll->currentItem();
}

void RemplirUV::on_retirerItem()
{
    QList<QTableWidgetItem *> l = m_pTableWidget->selectedItems();
    ui->listAll->addItem(l.first()->text());
    m_pTableWidget->removeRow(l.first()->row());

}


RemplirUV::~RemplirUV()
{
    delete ui;
}
