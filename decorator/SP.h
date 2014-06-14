#ifndef SP_h
#define SP_h

#include "decorator/Creditable.h"
#include <QString>


class SP : public CategorieDecorator {

public:

     SP(const QString& titre,const unsigned int ects, Creditable* creditable);
     ~SP();

     QString getTitre() const;
     void setTitre(const QString &value);

     QHash<QString, int> &getEcts(QHash<QString, int> &ectsmap) const;
     void setEcts(unsigned int value);
};


#endif // SP_h

