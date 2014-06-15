#ifndef Desiderata_h
#define Desiderata_h

#include <QMap>
#include <QString>
#include "UTProfilerException.h"



class Dossier;
class Creditable;

enum TypeDesiderata {
    Preference,
    Exigence,
    Rejet
};

class Desiderata {

public:
    Desiderata(const unsigned int id,TypeDesiderata type,Dossier* dossier,Creditable* uv);
    Desiderata(TypeDesiderata type,Dossier* dossier,Creditable* uv);
    ~Desiderata();

    unsigned int getId() const;
    void setId(unsigned int value);
    Dossier *getMyDossier() const;
    void setMyDossier(Dossier *value);
    Creditable *getUv() const;
    void setUv(Creditable *value);
    TypeDesiderata getType() const;
    void setType(const TypeDesiderata &value);
    static TypeDesiderata str2typeD(const QString& str);
    static QString typeD2str(TypeDesiderata desiderata);


private:
    unsigned int id;
    TypeDesiderata type;

public:

    /**
     * @element-type Dossier
     */
    Dossier *myDossier;
    Creditable *uv;




};

#endif // Desiderata_h

