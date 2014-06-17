#ifndef Semestre_h
#define Semestre_h

#include <QMap>
#include <QString>
#include "UTProfilerException.h"

class Cursus;
class Inscription;

enum Saison{
    Printemps,
    Automne
};
/**
 * @brief Semestre classe definissant un semestre
 * @details 
 * 
 * @param int id
 * @param titre nom ou code
 * @param saison automne ou printemps
 * @param int annee
 * @param etranger si le semestre est effectué a l'etranger
 * @param cursus cursus effectue pendant ce semestre
 * @return 
 */
class Semestre {

 public:
    /**
     * @brief constructeur semestre
     * @details 
     * 
     * @param int id
     * @param titre nom 
     * @param saison printemps ou automne
     * @param int annee
     * @param etranger effectue a l'etranger
     * @param cursus cursus associe
     */
    Semestre(const unsigned int id, const QString& titre, const Saison& saison, unsigned int annee, bool etranger, Cursus* cursus);
   /**
    * @brief constructeur Semestre sans id
    * @details          
    *
    * @param titre nom du semestre
    * @param saison printemps ou automne       
    * @param int annee
    * @param etranger semestre a l'etranger
    * @param cursus pendant lequel le semestre a ete fait
    */
    Semestre(const QString& titre, const Saison& saison, unsigned int annee, bool etranger, Cursus* cursus);
/**
 * @brief destructeur de semestre
 * @details 
 */
    ~Semestre();
/**
 * @brief accesseur saison
 * @details 
 * @return saison
 */
    Saison getSaison() const;
    void setSaison(const Saison &value);
/**
 * @brief accesseur annee
 * @details 
 * @return int annee
 */
    unsigned int getAnnee() const;
    void setAnnee(unsigned int value);
/**
 * @brief accesseur incription
 * @details 
 * @return QMap associant id et inscription
 */
    QMap<int, Inscription *> getInscriptions() const;
    void setInscriptions(const QMap<int, Inscription *> &value);
/**
 * @brief accesseur cursus associe
 * @details 
 * @return cursus pointeur
 */
    Cursus *getCursus() const;
    void setCursus(Cursus *value);
/**
 * @brief accesseur etranger
 * @details 
 * @return bool
 */
    bool isEtranger() const;
    void setEtranger(bool value);
/**
 * @brief modifie string en enum saison 
 * @details 
 * @return saison
 */
    static Saison str2saison(const QString& str);
   /**
    * @brief enum saison en string
    * @details 
    * 
    * @param saison Saison
    * @return QString
    */
    static QString saison2str(Saison saison);
/**
 * @brief id du semestre
 * @details 
 * @return int id
 */
    unsigned int ID() const;
/**
 * @brief mutateur id
 * @details 
 * 
 * @param int  int id
 */ 
    void setID(unsigned int value);
/**
 * @brief accesseur titre
 * @details 
 * @return Qstring de titre
 */
    QString getTitre() const;
    void setTitre(const QString &value);
/**
 * @brief accesseur total ects
 * @details 
 * @return int contenant nombre de ects
 */
    unsigned int getComputedEcts() const;
   
    void setComputedEcts(unsigned int value);

    QString getComputedCode() const;

private:
    unsigned int id;
    QString titre;
    Saison saison;
    unsigned int annee;
    bool etranger;
    QMap<int, Inscription *> inscriptions;
    Cursus* cursus;
    unsigned int computedEcts;
    QString computedCode;

};

#endif // Semestre_h

