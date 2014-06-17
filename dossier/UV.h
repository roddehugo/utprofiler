#ifndef UV_h
#define UV_h

#include "dossier/Cursus.h"
#include <QString>
#include <QTextStream>
#include <QMap>

class Cursus;
/**
 * @brief classe UV
 * @details contient les information sur une UV
 * 
 */
class UV
{

private:
    unsigned int id;
    QString code;
    QString titre;
    bool printemps;
    bool automne;
    bool demiuv;
    QMap<QString,int> credits;
    QList<Cursus*> cursus;

 public:
    /**
     * @brief constructeur complet de UV
     * @details 
     * 
     * @param int id
     * @param code code de l'UV
     * @param titre titre
     * @param printemps uv enseigné au printemps
     * @param automne uv enseigné au printemps
     * @param demiuv 
     * @param cursus Qlist de cursus auquell elle est associé
     */     
    UV(const unsigned int id, const QString& code, const QString& titre, const bool printemps, const bool automne, const bool demiuv, QMap<QString,int> credits, QList<Cursus *> cursus);
    /**
     * @brief constructeur complet de UV
     * @details 
     * 
     * @param int id
     * @param code code de l'UV
     * @param titre titre
     * @param printemps uv enseigné au printemps
     * @param automne uv enseigné au printemps
     * @param demiuv 
     */
    UV(const unsigned int id, const QString &code, const QString &titre, const bool printemps, const bool automne, const bool demiuv);
   /**
     * @brief constructeur complet de UV
     * @details 
     * 
     * @param code code de l'UV
     * @param titre titre
     * @param printemps uv enseigné au printemps
     * @param automne uv enseigné au printemps
     * @param demiuv 
     * @param cursus Qlist de cursus auquell elle est associé
     */
    UV(const QString& code, const QString& titre, const bool printemps, const bool automne, const bool demiuv, QMap<QString,int> credits, QList<Cursus *> cursus);
    /**
     * @brief constructeur complet de UV
     * @details 
     * 
     * @param code code de l'UV
     * @param titre titre
     * @param printemps uv enseigné au printemps
     * @param automne uv enseigné au printemps
     * @param demiuv 
     */
    UV(const QString& code, const QString& titre, const bool printemps, const bool automne, const bool demiuv);
/**
 * @brief destructeur d'une uv
 * @details 
 */
    ~UV();
/**
 * @brief accesseur attribut printemps
 * @details 
 * @return yes or no
 */
    bool isPrintemps() const;
    void setPrintemps(bool value);
/**
 * @brief accesseur attribut automne
 * @details 
 * @return yes or no
 */
    bool isAutomne() const;
    void setAutomne(bool value);
/**
 * @brief accesseur attribut qui verifie si l'uv est une demi uv
 * @details 
 * @return yes or no
 */
    bool isDemiUV() const;
    void setDemiUV(bool value);
/**
 * @brief accesseur attribut code de l'uv
 * @details 
 * @return QString contenant le code
 */
    QString getCode() const;
    void setCode(const QString &value);
/**
 * @brief accesseur attribut id de l'uv
 * @details 
 * @return unsigned int contenant le id
 */
    unsigned int ID() const;
    void setID(unsigned int value);
/**
 * @brief accesseur attribut code de l'uv
 * @details 
 * @return QString contenant le titre
 */
    QString getTitre() const;
    void setTitre(const QString &value);
/**
 * @brief accesseur attribut credit associé
 * @details 
 * @return Qmap contenant les credits
 */
    QMap<QString, int> getCredits() const;
    void setCredits(const QMap<QString, int> &value);
/**
 * @brief accesseur attribut cursus de l'uv
 * @details 
 * @return QList contenant le cursus
 */
    QList<Cursus *> getCursus() const;
    void setCursus(const QList<Cursus *> &value);
/**
 * @brief accesseur chaine des credits associés
 * @details 
 * @return QString contenant la concatenation des credits
 */
    QString getCreditsString() const;
    QString getCursusString() const;

};


#endif // UV_h

