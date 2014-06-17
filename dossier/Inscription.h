#ifndef Inscription_h
#define Inscription_h

#include "dossier/Semestre.h"
#include "dossier/UV.h"

enum Resultat{
    A,B,C,D,E,F,FX,
    ABS, /*Absent*/
    RES, /*Reserve*/
    EC, /*En cours*/
    EQU  /*Equivalence*/
};

class UV;
class Semestre;
class Dossier;
/**
 * @brief classe inscription
 * @details connecte semestre resultat et dossier
 * 
 */
class Inscription {

private:
    unsigned int id;
    UV* uv;
    Semestre* semestre;
    Resultat resultat;
    Dossier* dossier;

 public:
    /**
     * @brief constructeur inscription
     * @details 
     * 
     * @param int id
     * @param uv pointeur sur uv
     * @param semestre pointeur sur semestre
     * @param resultat reference vers un enum resultat
     * @param dossier pointeur sur dossier
     */
    Inscription(const unsigned int id, UV* uv, Semestre* semestre, const Resultat& resultat, Dossier* dossier);
    /**
     * @brief constructeur inscription sans id
     * @details 
     * 
     * @param uv pointeur sur uv
     * @param semestre pointeur sur semestre
     * @param resultat reference vers un enum resultat
     * @param dossier pointeur sur dossier
     */
    Inscription(UV *uv, Semestre *semestre, const Resultat &resultat, Dossier* dossier);
    /**
     * @brief destructeur inscription
     * @details
     */
    ~Inscription();
/**
 * @brief accesseur resultat
 * @details
 * @return resultat Resultat
 */
    Resultat getResultat() const;
    void setResultat(const Resultat &value);
/**
 * @brief accesseur semestre
 * @details
 * @return pointeur semestre
 */
    Semestre *getSemestre() const;
    void setSemestre(Semestre *value);
/**
 * @brief accesseur uv
 * @details
 * @return pointeur uv
 */
    UV *getUv() const;
    void setUv(UV *value);
/**
 * @brief modifie QString en resultat
 * @details
 * @return resultat dans enum Resultat
 */
    static Resultat str2resultat(const QString& str);
    static QString resultat2str(Resultat res);
/**
 * @brief accesseur id
 * @details
 * @return unsigned int
 */
    unsigned int ID() const;
    void setID(unsigned int value);
/**
 * @brief accesseur dossier
 * @details
 * @return pointeur sur dossier
 */
    Dossier *getDossier() const;
    void setDossier(Dossier *value);
};

#endif // Inscription_h

