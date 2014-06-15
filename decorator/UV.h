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

 public:
    UV(const unsigned int id, const QString& code, const QString& titre, const bool printemps, const bool automne, const bool demiuv);
    UV(const QString& code, const QString& titre, const bool printemps, const bool automne, const bool demiuv);
    virtual ~UV();

    QString getCode() const;
    void setCode(const QString &value);

    bool isPrintemps() const;
    void setPrintemps(bool value);

    bool isAutomne() const;
    void setAutomne(bool value);

    bool isDemiUV() const;
    void setDemiUV(bool value);

};

QTextStream& operator<<(QTextStream& f, const UV& uv);



#endif // UV_h

