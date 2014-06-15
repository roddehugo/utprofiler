#ifndef Desiderata_h
#define Desiderata_h

#include <QMap>
#include <QString>
#include "UTProfilerException.h"



class Dossier;
class UV;

enum TypeDesiderata {
    Preference,
    Exigence,
    Rejet
};

class Desiderata {

public:
    Desiderata(const unsigned int id,TypeDesiderata type,Dossier* dossier,UV* uv);
    Desiderata(TypeDesiderata type,Dossier* dossier,UV* uv);
    ~Desiderata();

    unsigned int getId() const;
    void setId(unsigned int value);

    Dossier *getMyDossier() const;
    void setMyDossier(Dossier *value);

    UV *getUv() const;
    void setUv(UV *value);

    TypeDesiderata getType() const;
    void setType(const TypeDesiderata &value);

    static TypeDesiderata str2typeD(const QString& str);
    static QString typeD2str(TypeDesiderata desiderata);


private:
    unsigned int id;
    TypeDesiderata type;

public:

    Dossier *dossier;
    UV *uv;




};

#endif // Desiderata_h

