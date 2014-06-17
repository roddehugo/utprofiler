#ifndef UTPROFILEREXCEPTION_H
#define UTPROFILEREXCEPTION_H

#include <QException>
#include <iostream>
#include <QString>
/**
 * @brief classe de gestion des erreurs 
 * @details 
 * 
 * @param e 
 * @return 
 */
class UTProfilerException : public QException
{
public:
    /**
     * @brief constructeur d'une instance de la classe UTProfilerException
     * @details 
     * 
     * @param  
     * @return 
     */
    UTProfilerException(const QString& m, const QString& f = 0)
        :message(m),file(f)
    {}
    /**
     * @brief copie de la classe UTProfiler
     * @details [long description]
     * @return pointeur vers UTProfilerException 
           */
    UTProfilerException *clone() const { return new UTProfilerException(*this); }
    /**
     * @brief destructeur de la classe UTProfilerEsception
     * @details 
     * 
     * @param w 
     */
    virtual ~UTProfilerException() throw() {}
    
    void raise() const { std::cout << "Salut"; }

    QString getMessage(){return message;}
    
    QString getFile(){return file;}

private:
    QString message;
    QString file;
};

#endif // UTPROFILEREXCEPTION_H
