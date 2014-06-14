#ifndef TC_h
#define TC_h

#include "decorator/Cursus.h"
#include <QString>


class TC : public Cursus {

 public:
    TC(const QString& c, const QString& titre, const int& cat, const unsigned int& ects,const unsigned int m,const unsigned int cur, const unsigned int idparent )
        :Cursus("TC","tronc commun",cat,ects,m,cur,idparent){}

    virtual QString getTitre() const;
    virtual QString getCode() const;

    ~TC(){}
};


//    virtual QString getTitre()  = 0;

//    virtual QString getCode()  = 0;

#endif // TC_h

