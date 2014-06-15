#ifndef Creditable_h
#define Creditable_h

#include <QString>
#include <QHash>
#include <QDebug>

class Creditable {

 public:

    virtual QString getTitre() const;
    virtual QHash<QString, int> &getEcts(QHash<QString, int> &ectsmap) const;
    virtual void setEcts(const unsigned int e);

    unsigned int ID() const;
    void setID(unsigned int value);
    unsigned int getEctsValue() const;

 protected:
    unsigned int id;
    QString titre;
    unsigned int ects;

    virtual ~Creditable() =0;
    Creditable(const unsigned int id, const QString& titre, const unsigned int ects);
    Creditable(const QString& titre, const unsigned int ects);
};

class CategorieDecorator : virtual public Creditable {

 public:

    Creditable *getCreditable() const;
    void setCreditable(Creditable *value);

protected:
    Creditable* creditable;
    CategorieDecorator(const unsigned int id, const QString& titre,const unsigned int ects, Creditable* creditable);
    CategorieDecorator(const unsigned int id, const QString& titre, Creditable* creditable);
    CategorieDecorator(const QString& titre,const unsigned int ects, Creditable* creditable);
    CategorieDecorator(const QString& titre, Creditable* creditable);
    virtual ~CategorieDecorator() =0;
};

#endif // Creditable_h

