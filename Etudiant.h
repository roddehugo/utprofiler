#ifndef Etudiant_h
#define Etudiant_h

#include <QString>
/**
 * @brief definit la classe etudiant
 * @details 
 * 
 */
class Etudiant
{

private:
   unsigned int id;
   QString login;
   QString prenom;
   QString nom;


public:
/**
 * @brief constructeur etudiant
 * @details 
 * 
 * @param int id
 * @param login login
 * @param prenom prenom
 * @param nom nom
 */
    Etudiant(const unsigned int id, const QString& login, const QString& prenom, const QString& nom);
   /**
 * @brief constructeur etudiant
 * @details 
 * 
 * @param login login
 * @param prenom prenom
 * @param nom nom
 */
    Etudiant(const QString& login, const QString& prenom, const QString& nom);
/**
 * @brief destructeur etudiant
 * @details 
 */
    ~Etudiant();
/**
 * @brief accesseur id etu
 * @details 
 * @return unsigned int
 */
    unsigned int ID() const;
    void setID(unsigned int value);
/**
 * @brief accesseur login
 * @details 
 * @return QString du login
 */
    QString getLogin() const;
   /**
    * @brief mutateur login
    * @details 
    * 
    * @param value QString du login
    */
    void setLogin(const QString &value);
/**
 * @brief accesseur prenom
 * @details 
 * @return QString du prenom
 */
    QString getPrenom() const;
      /**
    * @brief mutateur prenom
    * @details 
    * 
    * @param value QString du prenom
    */
    void setPrenom(const QString &value);
/**
 * @brief accesseur nom
 * @details 
 * @return QString du nom
 */
    QString getNom() const;
      /**
    * @brief mutateur nom
    * @details 
    * 
    * @param value QString du nom
    */
    void setNom(const QString &value);
};

#endif // Etudiant_h

