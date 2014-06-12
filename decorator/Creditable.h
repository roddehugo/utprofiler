#ifndef Creditable_h
#define Creditable_h

#include <QString>


class Creditable {

 public:

    virtual QString getTitre();

    virtual unsigned int getECTS()  = 0;


 private:
    QString titre;
    unsigned int ects;
};

#endif // Creditable_h

