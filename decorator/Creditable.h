#ifndef Creditable_h
#define Creditable_h

#include <QString>

class Creditable {

 public:

    virtual QString getTitre() const;
    virtual unsigned int getECTS() const  = 0;


 protected:
    //les données de la classe de base
    QString titre;
    unsigned int ects;

    virtual ~Creditable();
    Creditable(const QString& titre, const unsigned int &ects=0);
    //Creditable(){}
};

class CategorieDecorator :virtual public Creditable {

 public:

    virtual QString getTitre() const ;
    virtual unsigned int getECTS() const  = 0;

    Creditable* getCreditable() const {return &m_creditable;}


protected:
    Creditable& m_creditable;
    CategorieDecorator(Creditable&  creditable,const QString& titre,const unsigned int ects=0);
    virtual ~CategorieDecorator();
};

#endif // Creditable_h

