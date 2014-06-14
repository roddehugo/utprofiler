#ifndef AJOUTFILIEREWINDOW_H
#define AJOUTFILIEREWINDOW_H

#include <QDialog>

namespace Ui {
class ajoutfilierewindow;
}

class ajoutfilierewindow : public QDialog
{
    Q_OBJECT

public:
    explicit ajoutfilierewindow(QWidget *parent = 0);
    ~ajoutfilierewindow();

private:
    Ui::ajoutfilierewindow *ui;
};

#endif // AJOUTFILIEREWINDOW_H
