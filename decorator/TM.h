#ifndef TM_h
#define TM_h

#include "decorator/Creditable.h"
#include <QString>


class TM : public CategorieDecorator {

public:

     TM(const QString& titre,const unsigned int ects, Creditable* creditable);
     ~TM();

     QString getTitre() const;
     void setTitre(const QString &value);

     unsigned int getEcts() const;
     void setEcts(unsigned int value);
};

#endif // TM_h

