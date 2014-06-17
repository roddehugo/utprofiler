#ifndef Dossier_h
#define Dossier_h

#include <vector>
#include <QString>

#include "dossier/Cursus.h"
#include "dossier/Inscription.h"
#include "dossier/Semestre.h"

//class AlgoManager;
class Etudiant;
/**
 * @brief classe dossier
 * @details connecte etudiant a dossier
 * 
 * @param int id
 * @param titre nom du dossier
 * @param current dossier actuel ou non
 * @param etudiant pointeur sur etudiant
 * @return 
 */
class Dossier {

 public:
/**
 * @brief constructeur dossier
 * @details 
 * 
 * @param int id
 * @param titre QString titre
 * @param current dossier actuel ou non
 * @param etudiant pointeur sur etudiant
 */
    Dossier(const unsigned int id, const QString& titre, bool current, Etudiant* etudiant);
    /**
 * @brief constructeur dossier
 * @details 
 * 
 * @param titre QString titre
 * @param current dossier actuel ou non
 * @param etudiant pointeur sur etudiant
 */
    Dossier(const QString &titre, bool current, Etudiant *etudiant);
    /**
     * @brief destructeur dossier
     * @details 
     */
    ~Dossier();
/**
 * @brief accesseur etudiant
 * @details 
 * @return pointeur sur etudiant 
 */
    Etudiant *getEtudiant() const;
    /**
     * @brief mutateur etudiant
     * @details 
     * 
     * @param value pointeur sur etudiant
     */
    void setEtudiant(Etudiant *value);
/**
 * @brief accesseur dossier actuel
 * @details 
 * @return bool
 */ 
    bool isCurrent() const;
    void setCurrent(bool value);
/**
 * @brief accesseur titre
 * @details 
 * @return Qstring contenant titre
 */
    QString getTitre() const;
    void setTitre(const QString &value);
/**
 * @brief accesseur id
 * @details 
 * @return unsigned int ID
 */ 
    unsigned int ID() const;
    void setID(unsigned int id);

private:
    unsigned int id;
    QString titre;
    bool current;
    Etudiant* etudiant;

};

#endif // Dossier_h

