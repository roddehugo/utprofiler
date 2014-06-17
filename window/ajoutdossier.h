#ifndef AJOUTDOSSIER_H
#define AJOUTDOSSIER_H

#include <QDialog>
#include "dao/Factories.h"

namespace Ui {
	
class ajoutdossier;
}
/**
	 * @brief classe QDialog ajout dossier
	 * @details [long description]
	 * @return [description]
	 */
class ajoutdossier : public QDialog
{
    Q_OBJECT

public:
    explicit ajoutdossier(Factory* fac,QWidget *parent = 0);
    ~ajoutdossier();

private:
    Ui::ajoutdossier *ui;
    Factory* factory;
};

#endif // AJOUTDOSSIER_H
