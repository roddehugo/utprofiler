#ifndef AbstractDAOFactory_h
#define AbstractDAOFactory_h

#include "UTProfilerException.h"
#include "dao/UVDAO.h"
#include "dao/DossierDAO.h"
#include "dao/EtudiantDAO.h"
#include "dao/CursusDAO.h"
#include "dao/DesiderataDAO.h"
#include "dao/InscriptionDAO.h"
#include "dao/SemestreDAO.h"

#define DAO_FACTORY_DEFINE 0

struct Factory{
    virtual UVDAO* getUVDAO() =0;
    virtual EtudiantDAO* getEtudiantDAO() = 0;
    virtual InscriptionDAO* getInscriptionDAO()=0;
    virtual DossierDAO* getDossierDAO() =0;
    virtual CursusDAO* getCursusDAO() =0;
    virtual DesiderataDAO* getDesiderataDAO() =0;
    virtual SemestreDAO* getSemestreDAO() = 0;
};

class DAOFactory : public Factory, public Singleton<DAOFactory>
{

public:
    UVDAO* getUVDAO();

    EtudiantDAO* getEtudiantDAO();

    InscriptionDAO* getInscriptionDAO();

    DossierDAO* getDossierDAO();

    CursusDAO* getCursusDAO() ;
    DesiderataDAO* getDesiderataDAO() ;
    SemestreDAO* getSemestreDAO() ;

};

class AbstractDAOFactory : public Factory
{
public:

    static Factory* getFactory(const int& type);

    static const unsigned int DAO_FACTORY = 0;
};

#endif // AbstractDAOFactory_h

