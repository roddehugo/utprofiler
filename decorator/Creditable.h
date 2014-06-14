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

 protected:

    QString titre;
    unsigned int ects;

    virtual ~Creditable() =0;
    Creditable(const QString& titre, const unsigned int ects);
};

class CategorieDecorator : virtual public Creditable {

 public:

    Creditable *getCreditable() const;
    void setCreditable(Creditable *value);

protected:
    Creditable* creditable;
    CategorieDecorator(const QString& titre,const unsigned int ects, Creditable* creditable);
    CategorieDecorator(const QString& titre, Creditable* creditable);
    virtual ~CategorieDecorator() =0;
};

#endif // Creditable_h

