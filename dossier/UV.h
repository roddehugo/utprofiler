#ifndef UV_h
#define UV_h

#include "dossier/Cursus.h"
#include <QString>
#include <QTextStream>
#include <QMap>

class Cursus;

class UV
{

private:
    unsigned int id;
    QString code;
    QString titre;
    bool printemps;
    bool automne;
    bool demiuv;
    QMap<QString,int> credits;
    QList<Cursus*> cursus;

 public:
    UV(const unsigned int id, const QString& code, const QString& titre, const bool printemps, const bool automne, const bool demiuv, QMap<QString,int> credits, QList<Cursus *> cursus);
    UV(const unsigned int id, const QString &code, const QString &titre, const bool printemps, const bool automne, const bool demiuv);
    UV(const QString& code, const QString& titre, const bool printemps, const bool automne, const bool demiuv, QMap<QString,int> credits, QList<Cursus *> cursus);
    UV(const QString& code, const QString& titre, const bool printemps, const bool automne, const bool demiuv);

    ~UV();

    bool isPrintemps() const;
    void setPrintemps(bool value);

    bool isAutomne() const;
    void setAutomne(bool value);

    bool isDemiUV() const;
    void setDemiUV(bool value);

    QString getCode() const;
    void setCode(const QString &value);

    unsigned int ID() const;
    void setID(unsigned int value);

    QString getTitre() const;
    void setTitre(const QString &value);

    QMap<QString, int> getCredits() const;
    void setCredits(const QMap<QString, int> &value);

    QList<Cursus *> getCursus() const;
    void setCursus(const QList<Cursus *> &value);

    QString getCreditsString() const;
    QString getCursusString() const;

};


#endif // UV_h

