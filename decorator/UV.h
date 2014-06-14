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
   int categorie;

 public:
    UV(const QString& c, const QString& titre, const bool& p, const bool& a, const bool& d, const int& cat, const unsigned int& ects)
        :code(c), printemps(p), automne(a), demiuv(d), categorie(cat),Creditable(titre,ects)
    {}

    ~UV();



    QString getCode() const { return code; }

    QString getTitre() const { return titre; }

    bool getAutomne() const { return automne; }

    bool getPrintemps() const { return printemps; }

    bool getDemiUV() const { return demiuv; }

    int getCategorie() const { return categorie; }

    void setCode(const QString& c) { code=c; }

    void setTitre(const QString& t) { titre=titre; }

    void setAutomne(bool a) { automne=a; }

    void setPrintemps(bool p) { printemps=p; }

    void setDemiUV(bool d) { demiuv=d; }

    void setCategorie(int cat){ categorie = cat; }

    unsigned int getECTS() const {return ects;}

};

QTextStream& operator<<(QTextStream& f, const UV& uv);



#endif // UV_h

