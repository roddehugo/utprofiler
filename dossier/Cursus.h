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
    bool current;
    Cursus* parent;
    Dossier* dossier;
    QMap<QString,int> credits;

 public:
    Cursus(const unsigned int id, const QString& code, const QString& titre, const unsigned int ects,
           const unsigned int maxSemestre, bool current,QMap<QString,int> credits, Dossier* dossier=0, Cursus* parent=0);

    Cursus(const QString& code, const QString& titre, const unsigned int ects,
           const unsigned int maxSemestre, bool current,QMap<QString,int> credits, Dossier* dossier=0, Cursus* parent=0);

   ~Cursus();

    QString getCode() const;
    void setCode(const QString &value);

    unsigned int getMaxSemestres() const;
    void setMaxSemestres(unsigned int value);

    bool isCurrent() const;
    void setCurrent(bool value);

    Cursus *getParent() const;
    void setParent(Cursus *value);

    Dossier *getDossier() const;
    void setDossier(Dossier *value);

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

};



#endif // Cursus_h

