#ifndef Creditable_h
#define Creditable_h

#include <QString>
#include "decorator/CategorieDecorator.h"


class Creditable {

 public:

    virtual QString getTitre();

    virtual unsigned int getECTS()  = 0;


 protected:
    //les données de la classe de base
        QString titre;
        unsigned int ects;

        virtual ~Creditable();
        Creditable(QString& titre,unsigned int ects=0);
};

class CategorieDecorator : public Creditable {

 public:

    virtual QString getTitre()  = 0;
    Creditable* GetCreditable() const {return &m_creditable;}


     protected:
        Creditable& m_creditable;
        CategorieDecorator(Creditable&  creditable, QString& titre, unsigned int ects=0);
        virtual ~CategorieDecorator();

};

#endif // Creditable_h

