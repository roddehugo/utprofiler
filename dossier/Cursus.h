#ifndef Cursus_h
#define Cursus_h

#include <QString>
#include <QMap>
/**
 * @brief classe  definissant le cursus
 * @details 
 * 
 */
class Cursus{

protected:
    unsigned int id;
    QString code;
    QString titre;
    unsigned int ects;
    unsigned int maxSemestres;
    unsigned int previsionSemestres;
    Cursus* parent;
    QMap<QString,int> credits;

 public:
    /**
     * @brief constructeur instance cursus
     * @details 
     * 
     * @param int id
     * @param code code du cursus
     * @param titre titre cursus
     * @param int nombre d'ects
     * @param int nombre maximum de semsetre pour realiser ce cursus
     * @param int nombre prevu pu realiser ce semestre
     * @param parent  pointeur vers le cursus parent
     * @param credits QMap de credits associes au cursus
     */
    Cursus(const unsigned int id, const QString &code, const QString &titre, const unsigned int ects,
            const unsigned int maxSemestre,const unsigned int previsionSemestres,
            Cursus *parent, QMap<QString, int> credits);
/**
     * @brief constructeur instance cursus
     * @details 
     * 
     * @param code code du cursus
     * @param titre titre cursus
     * @param int nombre d'ects
     * @param int nombre maximum de semsetre pour realiser ce cursus
     * @param int nombre prevu pu realiser ce semestre
     * @param parent  pointeur vers le cursus parent
     * @param credits QMap de credits associes au cursus
     */
    Cursus(const QString &code, const QString &titre, const unsigned int ects,
                   const unsigned int maxSemestre,const unsigned int previsionSemestres,
                   Cursus *parent, QMap<QString, int> credits);
/**
     * @brief constructeur instance cursus
     * @details 
     * 
     * @param int id
     * @param code code du cursus
     * @param titre titre cursus
     * @param int nombre d'ects
     * @param int nombre maximum de semsetre pour realiser ce cursus
     * @param int nombre prevu pu realiser ce semestre
     * @param parent  pointeur vers le cursus parent
     */
    Cursus(const unsigned int id, const QString &code, const QString &titre, const unsigned int ects,
            const unsigned int maxSemestre,const unsigned int previsionSemestres,
            Cursus *parent);

/**
     * @brief constructeur instance cursus
     * @details 
     * 
     * @param code code du cursus
     * @param titre titre cursus
     * @param int nombre d'ects
     * @param int nombre maximum de semsetre pour realiser ce cursus
     * @param int nombre prevu pu realiser ce semestre
     * @param parent  pointeur vers le cursus parent
     */
    Cursus(const QString &code, const QString &titre, const unsigned int ects,
                   const unsigned int maxSemestre,const unsigned int previsionSemestres,
                   Cursus *parent);
/**
 * @brief destructeur de cursus
 * @details 
 */
   ~Cursus();
/**
 * @brief accesseur de code
 * @details 
 * @return QString
 */
    QString getCode() const;
    void setCode(const QString &value);
/**
 * @brief accessuer de MAximum semestre
 * @details 
 * @return unsigned int
 */ 
    unsigned int getMaxSemestres() const;
    void setMaxSemestres(unsigned int value);
/**
 * @brief accesseur nombre credits
 * @details 
 * @return unsigned int
 */ 
    unsigned int getEcts() const;
    void setEcts(unsigned int value);
/**
 * @brief accesseur titre
 * @details 
 * @return QSTring du titre
 */
    QString getTitre() const;
    void setTitre(const QString &value);
/**
 * @brief accesseur id
 * @details 
 * @return unsigned int de l'id
 */
    unsigned int ID() const;
    void setID(unsigned int value);
/**
 * @brief accesseur de la QMap contenant les credits
 * @details 
 * @return QMap associant credit et int
 */
    QMap<QString, int> getCredits() const;
    void setCredits(const QMap<QString, int> &value);
/**
 * @brief accessuer de prevision semestre
 * @details 
 * @return unsigned int
 */ 
    unsigned int getPrevisionSemestres() const;
    void setPrevisionSemestres(unsigned int value);
/**
 * @brief accesseur cursus paren
 * @details 
 * @return pointeur sur cursus
 */
    Cursus *getParent() const;
    void setParent(Cursus *value);
/**
 * @brief renvoie code plus titre
 * @details 
 * @return full name QString code+titre
 */
    QString getFull() const;
};



#endif // Cursus_h

