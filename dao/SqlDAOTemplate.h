#ifndef DAO_h
#define DAO_h

#include <QMap>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QMessageBox>
#include "writers/LogWriter.h"
#include "UTProfilerException.h"
#include "dao/Connexion.h"

template <class T, class DAO>
/**
 * @brief Classe template pour les Database acces object
 * @details model de classe pour acceder a la DB, herite de singleton
 * @return 
 */
class SqlDAOTemplate : public Singleton<DAO> {

    friend class Singleton<DAO>;

public:
/**
 * @brief renvoi tous les objets du type T recherche 
 * @details 
 * @return QMap associant entier et pointeur vers objet type T
 */
    virtual QMap<int, T*> findAll() =0;
/**
 * @brief find : trouve un objet par son id
 * @details 
 * 
 * @param id int id de l'entree dans la table
 * @return pointeur objet de type T
 */
    virtual T* find(const int& id) =0;
/**
 * @brief modifie une entree de la base
 * @details 
 * 
 * @param obj pointeur sur objet de type T
 * @return true si modification reussie
 */
    virtual bool update(T* obj) =0;
/**
 * @brief retire une entree dans la base
 * @details 
 * 
 * @param obj pointeur sur objet de type T
 * @return true sis uppression effectue
 */
    virtual bool remove(T* obj) =0;
/**
 * @brief cree une entree dans la table associe
 * @details 
 * 
 * @param obj pointeur sur objet de type T
 * @return true si reussit
 */
    virtual bool create(T* obj) =0;

protected:
    /**
     * @brief constructeur
     * @details virtuelle donc pas de creation
     */
    SqlDAOTemplate(){}
    /**
     * @brief destructeur
     * @details 
     * @return 
     */~SqlDAOTemplate(){

//        for(QMap<int, T*>::const_iterator it = Map.begin(); it != Map.end(); ++it){
//            delete it.value();
//        }
    }

    QMap<int, T*> Map;
    /**
     * @brief accesseur deQMap entre objet T et int
     * @details 
     * @return QMap
     */
    QMap<int, T*> getMap() const{
        return Map;
    }
    /**
     * @brief mutateur deQMap entre objet T et int
     * @details 
     * @return QMap
     */
    void setMap(const QMap<int, T*> &value){
        Map = value;
    }
};


#endif // DAO_h
