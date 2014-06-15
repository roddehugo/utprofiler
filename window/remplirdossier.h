#ifndef REMPLIRDOSSIER_H
#define REMPLIRDOSSIER_H

#include <QDialog>

namespace Ui {
class remplirDossier;
}

class remplirDossier : public QDialog
{
    Q_OBJECT

public:
    explicit remplirDossier(QWidget *parent = 0);
    ~remplirDossier();

private:
    Ui::remplirDossier *ui;
};

#endif // REMPLIRDOSSIER_H
