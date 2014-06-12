#ifndef XML_h
#define XML_h

template <class T>
class XML {

 public:

    XML();

    virtual T& find(const unsigned int& id) const;

    virtual void update(const T& obj);

    virtual void remove(const T& obj);

    virtual void create(const T& obj);

    virtual ~XML();

 protected:

};

template <class T>
XML<T>::XML() {

}

template <class T>
XML<T>::~XML() {

}

#endif // XML_h

