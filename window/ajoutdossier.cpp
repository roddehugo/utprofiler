#include "ajoutdossier.h"
#include "ui_ajoutdossier.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QtCore/QCoreApplication>
#include <QHeaderView>
#include <QMessageBox>

ajoutDossier::ajoutDossier(Factory* factory,QWidget *parent) :
    QDialog(parent),
    m_pTableWidget(NULL),
    ui(new Ui::ajoutDossier),
    fac(factory)
{
    ui->setupUi(this);
    ui->listAll->addItems(fac->getCursusDAO()->getStringList("code"));
    ui->anneeCombo->addItems(fac->getSemestreDAO()->getStringListAnnee());
    ui->saisonCombo->addItems(fac->getSemestreDAO()->getStringListSaison());

    m_pTableWidget = new QTableWidget(ui->frame);
    m_pTableWidget->setRowCount(0);
    m_pTableWidget->setColumnCount(5);
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
    m_pTableWidget->setHorizontalHeaderItem(0,h1);
    m_pTableWidget->setHorizontalHeaderItem(1,h2);
    m_pTableWidget->setHorizontalHeaderItem(2,h3);
    m_pTableWidget->setHorizontalHeaderItem(3,h4);
    m_pTableWidget->setHorizontalHeaderItem(4,h5);
    m_pTableWidget->setFixedSize(493,370);

    connect(ui->ajouterBouton,SIGNAL(clicked()),this, SLOT(on_ajouterItem()));
    connect(ui->retirerBouton,SIGNAL(clicked()),this, SLOT(on_retirerItem()));
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(saveDossier()));
}

void ajoutDossier::on_ajouterItem()
{
    if(ui->listAll->currentItem()!=NULL){
        int row = m_pTableWidget->rowCount();
        m_pTableWidget->setRowCount(row+1);
        m_pTableWidget->setItem(row, 4, new QTableWidgetItem(ui->listAll->currentItem()->text()) );
        m_pTableWidget->setItem(row, 3, new QTableWidgetItem(ui->etrangerRadio->isChecked()) );
        m_pTableWidget->setItem(row, 2, new QTableWidgetItem(ui->anneeCombo->currentText()) );
        m_pTableWidget->setItem(row, 1, new QTableWidgetItem(ui->saisonCombo->currentText()) );
        m_pTableWidget->setItem(row, 0, new QTableWidgetItem(ui->titreEdit->text()) );

        delete ui->listAll->currentItem();
    }
}

void ajoutDossier::on_retirerItem()
{
    QList<QTableWidgetItem *> l = m_pTableWidget->selectedItems();
    if(!l.empty()){
        ui->listAll->addItem(l.last()->text());
        m_pTableWidget->removeRow(l.first()->row());
    }

}

ajoutDossier::~ajoutDossier()
{
    delete ui;
}

void ajoutDossier::saveDossier()
{
    int row = m_pTableWidget->rowCount();
    for (int i = 0; i < row ; ++i)
    {
        fac->getSemestreDAO()->create(
            new Semestre(
                m_pTableWidget->itemAt(row,0)->text(),
                Semestre::str2saison(m_pTableWidget->itemAt(row,1)->text()),
                m_pTableWidget->itemAt(row,2)->text().toInt(),
                (m_pTableWidget->itemAt(row,3)->text() == "true" ? true : false),
                fac->getCursusDAO()->findByCode(m_pTableWidget->itemAt(row,4)->text())
            )
        );
    }
}
