#ifndef Cursus_h
#define Cursus_h

#include "decorator/Creditable.h"
#include <QString>

class Cursus : public Creditable {

protected:
   QString code;
   unsigned int maxSemestres;
   bool current;
   Creditable* parent;
   Dossier* dossier;

 public:
    Cursus(const unsigned int id, const QString& code, const QString& titre, const unsigned int ects,
           const unsigned int maxSemestre, bool current,
           Dossier* dossier, Creditable* parent );

    Cursus(const unsigned int id, const QString& code, const QString& titre, const unsigned int ects,
           const unsigned int maxSemestre, bool current,
           Dossier* dossier);
    Cursus(const QString& code, const QString& titre, const unsigned int ects,
           const unsigned int maxSemestre, bool current,
           Dossier* dossier, Creditable* parent );

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

    Creditable *getParent() const;
    void setParent(Creditable *value);

    Dossier *getDossier() const;
    void setDossier(Dossier *value);

};



#endif // Cursus_h

