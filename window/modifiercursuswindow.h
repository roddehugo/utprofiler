#ifndef MODIFIERCURSUSWINDOW_H
#define MODIFIERCURSUSWINDOW_H

#include <QDialog>

namespace Ui {
class modifiercursuswindow;
}

class modifiercursuswindow : public QDialog
{
    Q_OBJECT

public:
    explicit modifiercursuswindow(QWidget *parent = 0);
    ~modifiercursuswindow();

private:
    Ui::modifiercursuswindow *ui;
};

#endif // MODIFIERCURSUSWINDOW_H
