#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>

template <class T>
class Singleton
{
protected:
    // Constructeur/destructeur
    Singleton () { }
    ~Singleton () { std::cout << "destroying singleton." << std::endl; }

public:

    static T* getInstance ()
    {
        if (0 == instance)
        {
            std::cout << "creating singleton." << std::endl;
            instance = new T;
        }
        else
        {
            std::cout << "singleton already created!" << std::endl;
        }

        std::cout<<"Valeure de retour de la fonction : "<<instance<<"\n";
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
    static T *instance;
    Singleton(const Singleton&);
    Singleton& operator =(const Singleton&);
};

template <class T>
T* Singleton<T>::instance = 0;

#endif // SINGLETON_H
