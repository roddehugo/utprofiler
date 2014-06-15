#ifndef AJOUTDOSSIER_H
#define AJOUTDOSSIER_H

#include <QDialog>

namespace Ui {
class ajoutDossier;
}

class ajoutDossier : public QDialog
{
    Q_OBJECT

public:
    explicit ajoutDossier(QWidget *parent = 0);
    ~ajoutDossier();

private:
    Ui::ajoutDossier *ui;
};

#endif // AJOUTDOSSIER_H
