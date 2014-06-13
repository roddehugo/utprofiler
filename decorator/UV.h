#ifndef UV_h
#define UV_h

//#include "decorator/Creditable.h"
#include <QString>
#include <QTextStream>

class UV //: public Creditable
{

 public:
    UV(const QString& c, const QString& t, const bool& p, const bool& a, const bool& d, const int& cat)
        :code(c), titre(t), printemps(p), automne(a), demiUV(d), categorie(cat)
    {}

    UV();

    QString getCode() const { return code; }

    QString getTitre() const { return titre; }

    bool ouvertureAutomne() const { return automne; }

    bool ouverturePrintemps() const { return printemps; }

    void setCode(const QString& c) { code=c; }

    void setTitre(const QString& t) { titre=t; }

    void setOuvertureAutomne(bool a) { automne=a; }

    void setOuverturePrintemps(bool p) { printemps=p; }

    void setDemiUV(bool d) { demiUV=d; }

 private:
    QString code;
    QString titre;
    bool printemps;
    bool automne;
    bool demiUV;
    int categorie;


 public:

};

QTextStream& operator<<(QTextStream& f, const UV& uv);

#endif // UV_h

