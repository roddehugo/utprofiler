#ifndef Creditable_h
#define Creditable_h

#include <QString>
#include <QHash>
#include <QDebug>
#include "UTProfilerException.h"

class Dossier;

class Creditable {

 public:

    virtual QString getTitre() const;
    virtual QHash<QString, int> &getEcts(QHash<QString, int> &ectsmap) const;
    virtual void setEcts(const unsigned int e);

    virtual QString getCode() const;
    virtual void setCode(const QString &value);

    virtual bool isPrintemps() const;
    virtual void setPrintemps(bool value);

    virtual bool isAutomne() const;
    virtual void setAutomne(bool value);

    virtual bool isDemiUV() const;
    virtual void setDemiUV(bool value);

    virtual unsigned int getMaxSemestres() const =0;
    virtual void setMaxSemestres(unsigned int value);

    virtual bool isCurrent() const;
    virtual void setCurrent(bool value);

    virtual Creditable *getParent() const;
    virtual void setParent(Creditable *value);

    virtual Dossier *getDossier() const;
    virtual void setDossier(Dossier *value);

    unsigned int ID() const;
    void setID(unsigned int value);
    unsigned int getEctsValue() const;

    virtual Creditable *getCreditable() const =0;

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

    unsigned int getMaxSemestres() const;

protected:
    Creditable* creditable;
    CategorieDecorator(const unsigned int id, const QString& titre,const unsigned int ects, Creditable* creditable);
    CategorieDecorator(const unsigned int id, const QString& titre, Creditable* creditable);
    CategorieDecorator(const QString& titre,const unsigned int ects, Creditable* creditable);
    CategorieDecorator(const QString& titre, Creditable* creditable);
    virtual ~CategorieDecorator() =0;
};

#endif // Creditable_h

