#ifndef DAO_h
#define DAO_h

#include <dao/Connection.h>

template <class T>
class DAO {

 public:

    DAO();

    virtual T& find(const unsigned int& id) const;

    virtual void update(const T& obj);

    virtual void remove(const T& obj);

    virtual void create(const T& obj);

    virtual ~DAO();

 protected:
    Connection* conn;

};

template <class T>
DAO<T>::DAO() {
    conn = Connection::getInstance();
}

template <class T>
DAO<T>::~DAO() {
    Connection::releaseInstance();
    conn = 0;
}

#endif // DAO_h

