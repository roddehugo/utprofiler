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
#include "dao/CategorieDAO.h"

/**
 * @brief classe modele de Factory
 * @details 
 * @return 
 */
struct Factory{
    virtual UVDAO* getUVDAO() =0;
    virtual EtudiantDAO* getEtudiantDAO() = 0;
    virtual InscriptionDAO* getInscriptionDAO()=0;
    virtual DossierDAO* getDossierDAO() =0;
    virtual CursusDAO* getCursusDAO() =0;
    virtual DesiderataDAO* getDesiderataDAO() =0;
    virtual SemestreDAO* getSemestreDAO() = 0;
    virtual CategorieDAO* getCategorieDAO() = 0;

};
/**
 * @brief classe donnant acces a toutes les classes de gestin de la BDD@
 * @details 
 * @return 
 */
class DAOFactory : public Factory, public Singleton<DAOFactory>
{

public:
    UVDAO* getUVDAO();
    EtudiantDAO* getEtudiantDAO();
    InscriptionDAO* getInscriptionDAO();
    DossierDAO* getDossierDAO();
    CategorieDAO* getCategorieDAO();
    CursusDAO* getCursusDAO() ;
    DesiderataDAO* getDesiderataDAO() ;
    SemestreDAO* getSemestreDAO() ;

};
/**
 * @brief classe modele de la classe gerant les DAOfactory
 * @details 
 * 
 * @param type type de la DAO voulat etre accede
 * @return 
 */
class AbstractDAOFactory : public Factory
{
public:

    static Factory* getFactory(const int& type);

    static const unsigned int DAO_FACTORY = 0;
    static const unsigned int XML_FACTORY = 1;

};

#endif // AbstractDAOFactory_h

