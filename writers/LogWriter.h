#ifndef LogWriter_h
#define LogWriter_h

#include <QString>
#include <QDateTime>
#include <iostream>

#define q2s(string) string.toStdString()
/**
 * @brief classe definissant xriter dans log
 * @details 
 * 
 * @param source fichier depuis lequel il est appele    
 * @param message message à envoyer
 */ 
class LogWriter {

public:
  /**
   * @brief affiche dans la console le message puis saute une ligne
   * @details 
   * 
   * @param source fichier source
   * @param message message a afficher
   */
    static void writeln(const QString source, const QString& message)
    {
        std::cout << q2s(QDateTime::currentDateTime().toString())
                  << " : From <" << q2s(source) << "> : "
                  << q2s(message)
                  << std::endl;
                }

/**
   * @brief affiche dans la console le message puis saute une ligne
   * @details 
   * 
   * @param source fichier source
   * @param message message a afficher
   */
    static void write(const QString source, const QString& message)
    {
        std::cout << q2s(QDateTime::currentDateTime().toString())
                  << " : From <" << q2s(source) << "> : "
                  << q2s(message)
                  << "...";

    }
/**
 * @brief ajoute unmessage a la suite
 * @details 
 * 
 * @param message message a ajouter
 */
    static void append(const QString& message){
        std::cout << q2s(message);
    }
/**
 * @brief finit la ligne dans la sortie du log
 * @details 
 */
    static void endl(){
        std::cout << std::endl;
    }


};

#endif // LogWriter_h

