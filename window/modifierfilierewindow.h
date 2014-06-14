#ifndef MODIFIERFILIEREWINDOW_H
#define MODIFIERFILIEREWINDOW_H

#include <QDialog>

namespace Ui {
class modifierfilierewindow;
}

class modifierfilierewindow : public QDialog
{
    Q_OBJECT

public:
    explicit modifierfilierewindow(QWidget *parent = 0);
    ~modifierfilierewindow();

private:
    Ui::modifierfilierewindow *ui;
};

#endif // MODIFIERFILIEREWINDOW_H
