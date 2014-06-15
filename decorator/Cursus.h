#ifndef Cursus_h
#define Cursus_h

#include "decorator/Creditable.h"
#include <QString>
#include "dossier/Dossier.h"

class Dossier;

class Cursus : public Creditable {

protected:
   QString code;
   unsigned int maxSemestres;
   bool current;
   Cursus* parent;
   Dossier* dossier;

 public:
    Cursus(const unsigned int id, const QString& code, const QString& titre, const unsigned int ects,
           const unsigned int maxSemestre, bool current,
           Dossier* dossier, Cursus* parent );

    Cursus(const unsigned int id, const QString& code, const QString& titre, const unsigned int ects,
           const unsigned int maxSemestre, bool current,
           Dossier* dossier);
    Cursus(const QString& code, const QString& titre, const unsigned int ects,
           const unsigned int maxSemestre, bool current,
           Dossier* dossier, Cursus* parent );

    Cursus(const QString& code, const QString& titre, const unsigned int ects,
           const unsigned int maxSemestre, bool current,
           Dossier* dossier);

    virtual ~Cursus();

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

};



#endif // Cursus_h

