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
    ui->semestreCombo->addItems(fac->getSemestreDAO()->getStringList());
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
    QTableWidgetItem *h2 = new QTableWidgetItem("Semestre");
    h2->setTextAlignment(Qt::AlignLeft);
    QTableWidgetItem *h3 = new QTableWidgetItem("Résultat");
    h3->setTextAlignment(Qt::AlignLeft);
    m_pTableWidget->setHorizontalHeaderItem(0,h1);
    m_pTableWidget->setHorizontalHeaderItem(1,h2);
    m_pTableWidget->setHorizontalHeaderItem(2,h3);
    m_pTableWidget->setFixedSize(349,352);

    connect(ui->ajouterBouton,SIGNAL(clicked()),this, SLOT(on_ajouterItem()));
    connect(ui->retirerBouton,SIGNAL(clicked()),this, SLOT(on_retirerItem()));
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(saveInscription()));

}

void saisirinscription::on_ajouterItem()
{
    if(ui->listAll->currentItem()!=NULL){
        int row = m_pTableWidget->rowCount();
        m_pTableWidget->setRowCount(row+1);
        m_pTableWidget->setItem(row, 0, new QTableWidgetItem(ui->listAll->currentItem()->text()) );
        m_pTableWidget->setItem(row, 1, new QTableWidgetItem(ui->semestreCombo->currentText()) );
        m_pTableWidget->setItem(row, 2, new QTableWidgetItem(ui->resultatCombo->currentText()) );

        delete ui->listAll->currentItem();
    }
}

void saisirinscription::on_retirerItem()
{
    QList<QTableWidgetItem *> l = m_pTableWidget->selectedItems();
    if(!l.empty()){
        ui->listAll->addItem(l.first()->text());
        m_pTableWidget->removeRow(l.first()->row());
        ui->listAll->sortItems();
    }

}

void saisirinscription::saveInscription()
{
    Dossier* dossier = fac->getDossierDAO()->getCurrent();
    int row = m_pTableWidget->rowCount();
    for (int i = 0; i < row ; ++i)
    {
        const QString codeuv = m_pTableWidget->item(i,0)->text();
        const QString codesemestre = m_pTableWidget->item(i,1)->text();
        const Resultat resultat = Inscription::str2resultat(m_pTableWidget->item(i,2)->text());

        UV* uv = fac->getUVDAO()->findByCode(codeuv);
        Semestre* sem = fac->getSemestreDAO()->findByStr(codesemestre);
        fac->getInscriptionDAO()->create(new Inscription(uv,sem,resultat,dossier));
    }
}


saisirinscription::~saisirinscription()
{
    delete ui;
}
