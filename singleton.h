#ifndef SINGLETON_H
#define SINGLETON_H

#include "writers/LogWriter.h"

template <class T>
class Singleton
{
protected:

    Singleton () { }
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
