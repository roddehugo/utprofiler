#ifndef AJOUTCURSUSWINDOW_H
#define AJOUTCURSUSWINDOW_H

#include <QDialog>

namespace Ui {
class ajoutcursuswindow;
}

class ajoutcursuswindow : public QDialog
{
    Q_OBJECT

public:
    explicit ajoutcursuswindow(QWidget *parent = 0);
    ~ajoutcursuswindow();

private:
    Ui::ajoutcursuswindow *ui;
};

#endif // AJOUTCURSUSWINDOW_H
