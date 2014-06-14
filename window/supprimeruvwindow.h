#ifndef SUPPRIMERUVWINDOW_H
#define SUPPRIMERUVWINDOW_H

#include <QDialog>

namespace Ui {
class supprimerUVwindow;
}

class supprimerUVwindow : public QDialog
{
    Q_OBJECT

public:
    explicit supprimerUVwindow(QWidget *parent = 0);
    ~supprimerUVwindow();

private:
    Ui::supprimerUVwindow *ui;
};

#endif // SUPPRIMERUVWINDOW_H
