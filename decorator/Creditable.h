#ifndef Creditable_h
#define Creditable_h

#include <QString>

class Creditable {

 public:

    virtual QString getTitre() const;
    virtual unsigned int getEcts() const  = 0;


 protected:

    QString titre;
    unsigned int ects;

    virtual ~Creditable();
    Creditable(const QString& titre, const unsigned int ects=0);
};

class CategorieDecorator : virtual public Creditable {

 public:

    virtual QString getTitre() const ;
    virtual unsigned int getEcts() const  = 0;

    Creditable *getCreditable() const;
    void setCreditable(Creditable *value);

protected:
    Creditable* creditable;
    CategorieDecorator(const QString& titre,const unsigned int ects, Creditable* creditable);
    CategorieDecorator(const QString& titre, Creditable* creditable);
    virtual ~CategorieDecorator();
};

#endif // Creditable_h

