#ifndef HuTech_h
#define HuTech_h

#include "decorator/Cursus.h"
#include <QString>


class HuTech : public Cursus {

 public:
    HuTech(const QString& c, const QString& titre, const int& cat, const unsigned int& ects,const unsigned int m,const unsigned int cur, const unsigned int idparent )
        :Cursus("HuTech","Humanité et Technologie",cat,ects,m,cur,idparent){}

    virtual QString getTitre() const;
    virtual QString getCode() const;

    ~HuTech(){}

};

#endif // HuTech_h

