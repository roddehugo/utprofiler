#ifndef SINGLETON_H
#define SINGLETON_H

#include "writers/LogWriter.h"

template <class T>
/**
 * @brief classe template du design pattern singleton manipulant un objet de type T
 */
class Singleton
{
protected:
/**
 * @brief constructeur de la classe Singleton
 * @details 
 * @return 
 */ 
    Singleton () { }
    /**
     * @brief destructeur de la classe Singleton
     * @details 
     * @return 
     */
    ~Singleton () { }
    static T *instance;
public:

    static T* getInstance (){
        if (0 == instance){
            instance = new T;
        }

        return (static_cast<T*> (instance));
    }

    static void releaseInstance ()
    {
        if (0 != instance)
        {
            delete instance;
            instance = 0;
        }
    }

private:
    Singleton(const Singleton&);
    Singleton& operator =(const Singleton&);
};

template <class T>
T* Singleton<T>::instance = 0;

#endif // SINGLETON_H
