#ifndef DossierDAO_h
#define DossierDAO_h

#include "dossier/Dossier.h"
#include "dao/SqlDAOTemplate.h"

class DossierDAO : public SqlDAOTemplate<Dossier, DossierDAO> {

    friend class Singleton<DossierDAO>;
private:
    Dossier* current;
public:

    QMap<int, Dossier *> findAll();

    Dossier* find(const int& id);
    QStringList findByEtudiant(const int etu);

    bool update(Dossier* obj);

    bool remove(Dossier* obj);

    bool create(Dossier* obj);

    Dossier *findByStr(const QString &str);

    QMap<QString, int> getCursusMap(unsigned int id);

    Dossier *getCurrent() const;
    void setCurrent(Dossier *value);
    protected:

    ~DossierDAO(){}
    DossierDAO(){}

};

#endif // DossierDAO_h

