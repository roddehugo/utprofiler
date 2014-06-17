#ifndef SUPPRIMERUVWINDOW_H
#define SUPPRIMERUVWINDOW_H

#include <QDialog>
#include "dao/Factories.h"

namespace Ui {
class supprimerUVwindow;
}
/**
 * @brief classe QDialog pour supprimer une uv
 *
 * @details [long description]
 * 
 */
class supprimerUVwindow : public QDialog
{
    Q_OBJECT

public:

    explicit supprimerUVwindow(Factory* factory,QWidget *parent = 0);
    ~supprimerUVwindow();

private:
    Ui::supprimerUVwindow *ui;
    Factory* fac;
public slots:
    void delUV();
signals:
    void finsuppr();
};

#endif // SUPPRIMERUVWINDOW_H
