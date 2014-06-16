#include "window/saisirinscription.h"
#include "ui_saisirinscription.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QtCore/QCoreApplication>
#include <QHeaderView>
#include <QMessageBox>

saisirinscription::saisirinscription(Factory* factory,QWidget *parent) :
    QDialog(parent),
    m_pTableWidget(NULL),
    ui(new Ui::saisirinscription),
    fac(factory)
{
    ui->setupUi(this);

    ui->resultatCombo->addItems(fac->getInscriptionDAO()->getStringListResultat());
    ui->listAll->addItems(fac->getUVDAO()->getStringList("code"));

    m_pTableWidget = new QTableWidget(ui->frame);
    m_pTableWidget->setRowCount(0);
    m_pTableWidget->setColumnCount(3);
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
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(saveDossier()));

}

void saisirinscription::on_ajouterItem()
{

    int row = m_pTableWidget->rowCount();
    m_pTableWidget->setRowCount(row+1);
    m_pTableWidget->setItem(row, 0, new QTableWidgetItem(ui->listAll->currentItem()->text()) );
    m_pTableWidget->setItem(row, 1, new QTableWidgetItem(ui->semestreCombo->currentText()) );
    m_pTableWidget->setItem(row, 2, new QTableWidgetItem(ui->resultatCombo->currentText()) );


    delete ui->listAll->currentItem();
}

void saisirinscription::on_retirerItem()
{
    QList<QTableWidgetItem *> l = m_pTableWidget->selectedItems();
    ui->listAll->addItem(l.first()->text());
    m_pTableWidget->removeRow(l.first()->row());

}

void saisirinscription::saveDossier()
{

}


saisirinscription::~saisirinscription()
{
    delete ui;
}
