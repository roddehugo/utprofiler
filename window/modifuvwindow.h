#ifndef MODIFUVWINDOW_H
#define MODIFUVWINDOW_H

#include <QDialog>

namespace Ui {
class modifUVwindow;
}

class modifUVwindow : public QDialog
{
    Q_OBJECT

public:
    explicit modifUVwindow(QWidget *parent = 0);
    ~modifUVwindow();

private:
    Ui::modifUVwindow *ui;
};

#endif // MODIFUVWINDOW_H
