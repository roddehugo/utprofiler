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
/**
 * @brief classe definissant les desiderata etudiant
 * @details i.e. les uv preferes ou rejetees
 * 
 * @param int id
 * @param type type desiderata
 * @param dossier pointeur sur dossier
 * @param uv pointeur sur uv
 * @return 
 */     
class Desiderata {

public:
    /**
     * @brief constructeur desiderata
     * @details 
     * 
     * @param int id
     * @param type enum preference exigence ou rejet
     * @param dossier pointeur sur dossier
     * @param uv pointeur sur uv
     */
    Desiderata(const unsigned int id,TypeDesiderata type,Dossier* dossier,UV* uv);
    /**
     * @brief constructeur desiderata sans id
     * @details [long description]
     * 
     * @param type enum preference exigence ou rejet
     * @param dossier pointeur sur dossier
     * @param uv pointeur sur uv
     */
    Desiderata(TypeDesiderata type,Dossier* dossier,UV* uv);
   /**
    * @brief destructeur desderata
    * @details 
    * @return 
    */ ~Desiderata();
/**
 * @brief accesseur id
 * @details 
 * @return unsigned int
 */
    unsigned int getId() const;
    void setId(unsigned int value);
/**
 * @brief accesseur dossier
 * @details 
 * @return pointeur sur dossier
 */
    Dossier *getMyDossier() const;
    void setMyDossier(Dossier *value);
/**
 * @brief accesseur uv
 * @details 
 * @return pointeur sur uv
 */
    UV *getUv() const;
    void setUv(UV *value);
/**
 * @brief acceseur type desiderata
 * @details 
 * @return enum preference exigence ou rejet
 */
    TypeDesiderata getType() const;
    void setType(const TypeDesiderata &value);
/**
 * @brief convertisseur string en enum
 * @details 
 * 
 * @param str Qstring
 * @return enum preference exigence ou rejet
 */
    static TypeDesiderata str2typeD(const QString& str);
  /**
   * @brief convertisseur enum en string
   * @details 
   * 
   * @param desiderata enum preference exigence ou rejet
   * @return QString
   */
    static QString typeD2str(TypeDesiderata desiderata);


private:
    unsigned int id;
    TypeDesiderata type;

public:

    Dossier *dossier;
    UV *uv;




};

#endif // Desiderata_h

