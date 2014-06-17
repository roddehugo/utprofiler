#ifndef MODIFUVWINDOW_H
#define MODIFUVWINDOW_H

#include <QDialog>
#include "dao/Factories.h"
#include <QString>
#include <QMessageBox>

namespace Ui {
class modifUVwindow;
}
/**
 * @brief classe modifier une uv
 * @details [long description]
 * @return [description]
 */
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
    void saveuv();
    void on_modifuv_clicked();
    void addcursus();
    void addcredit();
    void removecredit();
    void removecursus();
};

#endif // MODIFUVWINDOW_H
