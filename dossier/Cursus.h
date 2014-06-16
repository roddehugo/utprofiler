#ifndef Cursus_h
#define Cursus_h

#include <QString>
#include <QMap>

class Cursus{

protected:
    unsigned int id;
    QString code;
    QString titre;
    unsigned int ects;
    unsigned int maxSemestres;
    unsigned int previsionSemestres;
    Cursus* parent;
    QMap<QString,int> credits;

 public:
    Cursus(const unsigned int id, const QString &code, const QString &titre, const unsigned int ects,
            const unsigned int maxSemestre,const unsigned int previsionSemestres,
            Cursus *parent, QMap<QString, int> credits);

    Cursus(const QString &code, const QString &titre, const unsigned int ects,
                   const unsigned int maxSemestre,const unsigned int previsionSemestres,
                   Cursus *parent, QMap<QString, int> credits);

    Cursus(const unsigned int id, const QString &code, const QString &titre, const unsigned int ects,
            const unsigned int maxSemestre,const unsigned int previsionSemestres,
            Cursus *parent);

    Cursus(const QString &code, const QString &titre, const unsigned int ects,
                   const unsigned int maxSemestre,const unsigned int previsionSemestres,
                   Cursus *parent);

   ~Cursus();

    QString getCode() const;
    void setCode(const QString &value);

    unsigned int getMaxSemestres() const;
    void setMaxSemestres(unsigned int value);

    unsigned int getEcts() const;
    void setEcts(unsigned int value);

    QString getTitre() const;
    void setTitre(const QString &value);

    unsigned int ID() const;
    void setID(unsigned int value);

    QMap<QString, int> getCredits() const;
    void setCredits(const QMap<QString, int> &value);

    unsigned int getPrevisionSemestres() const;
    void setPrevisionSemestres(unsigned int value);

    Cursus *getParent() const;
    void setParent(Cursus *value);
};



#endif // Cursus_h

