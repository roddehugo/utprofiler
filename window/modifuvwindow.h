#ifndef MODIFUVWINDOW_H
#define MODIFUVWINDOW_H

#include <QDialog>
#include "dao/Factories.h"
#include <QString>
#include <QMessageBox>

namespace Ui {
class modifUVwindow;
}

class modifUVwindow : public QDialog
{
    Q_OBJECT

public:
    explicit modifUVwindow(Factory* factory,QWidget *parent = 0);
    ~modifUVwindow();

private:
    Ui::modifUVwindow *ui;
    Factory* fac;

public slots:
    void saveUV();
    void on_modifuv_clicked();
};

#endif // MODIFUVWINDOW_H
