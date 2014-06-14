#ifndef TSH_h
#define TSH_h

#include "decorator/Creditable.h"
#include <QString>

enum ligne {Communiquer, Perception};
enum colonne {Pratique, Theorique};

class TSH : public CategorieDecorator {

private:

    colonne tagc;
    ligne tagl;

public:

     TSH(const QString& titre,const unsigned int ects, Creditable* creditable);
     ~TSH();

     QString getTitre() const;
     void setTitre(const QString &value);

     QHash<QString, int> &getEcts(QHash<QString, int> &ectsmap) const;
     void setEcts(unsigned int value);

     colonne getTagc() const;
     void setTagc(const colonne &value);

     ligne getTagl() const;
     void setTagl(const ligne &value);
};

#endif // TSH_h

