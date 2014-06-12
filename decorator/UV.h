#ifndef UV_h
#define UV_h

#include "decorator/Creditable.h"
#include <QString>


class UV : public Creditable {

 public:

    UV();

    QString getCode();

    QString getTitre();

    void setCode(QString c);

    void setTitre(QString t);

    void setSaison(int s);

    int getSaison();

 public:
    static const int SAISON_PRINTEMPS = 0;
    static const int SAISON_AUTOMNE = 1;
    static const int SAISON_NULL = 2;
    static const int SAISON_BOTH = 3;

 private:
    QString code;
    QString titre;

 public:

};

#endif // UV_h

