#ifndef CS_h
#define CS_h

#include "decorator/Creditable.h"
#include <QString>


class CS : public CategorieDecorator {

public:

     CS(const unsigned int id, const QString& titre,const unsigned int ects, Creditable* creditable);
     CS(const QString& titre,const unsigned int ects, Creditable* creditable);
     ~CS();

     QString getTitre() const;
     void setTitre(const QString &value);

     QHash<QString, int> &getEcts(QHash<QString, int>& ectsmap) const;
     void setEcts(unsigned int value);
};

#endif // CS_h

