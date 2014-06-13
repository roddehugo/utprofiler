#ifndef SINGLETON_H
#define SINGLETON_H

#include "writers/LogWriter.h"

template <class T>
class Singleton
{
protected:
    // Constructeur/destructeur
    Singleton () { }
    ~Singleton () { LogWriter::writeln("Singleton.h","Destruction du singleton"); }
    static T *instance;
public:

    static T* getInstance (){
        if (0 == instance){
            LogWriter::writeln("Singleton.h","Création du singleton");
            instance = new T;
        }else{
            LogWriter::writeln("Singleton.h","Singleton déjà existant");
        }

        return (static_cast<T*> (instance));
    }

    static void releaseInstance ()
    {
        if (0 != instance)
        {
            LogWriter::writeln("Singleton.h","Destruction du singleton");
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
