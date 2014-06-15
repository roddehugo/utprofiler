#ifndef AJOUTERUVWINDOW_H
#define AJOUTERUVWINDOW_H

#include <QDialog>

namespace Ui {
class ajouterUVwindow;
}

class ajouterUVwindow : public QDialog
{
    Q_OBJECT

public:
    explicit ajouterUVwindow(QWidget *parent = 0);
    ~ajouterUVwindow();

private:
    Ui::ajouterUVwindow *ui;


};

#endif // AJOUTERUVWINDOW_H
