#ifndef Connexion_h
#define Connexion_h

#include <QSqlDatabase>
#include <QFileDialog>
#include "Singleton.h"
#include "writers/LogWriter.h"
#include "UTProfilerException.h"

class Connexion : public Singleton<Connexion> {

    friend class Singleton<Connexion>;

public:
    QSqlDatabase getDataBase() const;
    void setConnexion(const QString &dbfile);
    void close();

private:
    QSqlDatabase db;
    Connexion () {}
    ~Connexion (){db.close();}
};

#endif // Connexion_h

