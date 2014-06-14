#ifndef SUPPRIMERCURSUS_H
#define SUPPRIMERCURSUS_H

#include <QDialog>

namespace Ui {
class supprimerCursus;
}

class supprimerCursus : public QDialog
{
    Q_OBJECT

public:
    explicit supprimerCursus(QWidget *parent = 0);
    ~supprimerCursus();

private:
    Ui::supprimerCursus *ui;
};

#endif // SUPPRIMERCURSUS_H
