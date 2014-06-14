#ifndef UV_h
#define UV_h

#include "decorator/Creditable.h"
#include <QString>
#include <QTextStream>

class UV : public Creditable
{

private:
   QString code;
   bool printemps;
   bool automne;
   bool demiuv;
   Creditable* creditable;

 public:
    UV(const QString& code, const QString& titre, const bool printemps, const bool automne, const bool demiuv, Creditable* creditable);
    UV(const QString& code, const QString& titre, const bool printemps, const bool automne, const bool demiuv);
    ~UV();

    QString getCode() const;
    void setCode(const QString &value);

    bool getPrintemps() const;
    void setPrintemps(bool value);

    bool getAutomne() const;
    void setAutomne(bool value);

    bool getDemiUV() const;
    void setDemiUV(bool value);

    Creditable *getCreditable() const;
    void setCreditable(Creditable *value);

    unsigned int getEcts() const;
    void setEcts(unsigned int value);

    unsigned int getCategorie() const;

};

QTextStream& operator<<(QTextStream& f, const UV& uv);



#endif // UV_h

