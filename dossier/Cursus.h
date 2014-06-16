#ifndef Cursus_h
#define Cursus_h

#include <QString>
#include <QMap>
#include "dossier/Dossier.h"

class Dossier;

class Cursus{

protected:
    unsigned int id;
    QString titre;
    QString code;
    unsigned int ects;
    unsigned int maxSemestres;
    unsigned int previsionsSemestres;
    bool current;
    Cursus* parent;
    QMap<QString,int> credits;

 public:
    Cursus(const unsigned int id, const QString& code, const QString& titre, const unsigned int ects,
           const unsigned int maxSemestre, bool current,QMap<QString,int> credits, Cursus* parent=0);

    Cursus(const QString& code, const QString& titre, const unsigned int ects,
           const unsigned int maxSemestre, bool current,QMap<QString,int> credits, Cursus* parent=0);

   ~Cursus();

    QString getCode() const;
    void setCode(const QString &value);

    unsigned int getMaxSemestres() const;
    void setMaxSemestres(unsigned int value);

    Cursus *getParent() const;
    void setParent(Cursus *value);

    unsigned int getEcts() const;
    void setEcts(unsigned int value);

    QString getTitre() const;
    void setTitre(const QString &value);

    unsigned int ID() const;
    void setID(unsigned int value);

    unsigned int getTotalCredits() const;
    void setTotalCredits(unsigned int value);

    QMap<QString, int> getCredits() const;
    void setCredits(const QMap<QString, int> &value);

    unsigned int getPrevisionsSemestres() const;
    void setPrevisionsSemestres(unsigned int value);
};



#endif // Cursus_h

