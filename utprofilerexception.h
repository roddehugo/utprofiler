#ifndef UTPROFILEREXCEPTION_H
#define UTPROFILEREXCEPTION_H

#include <QException>
#include <iostream>
#include <QString>

class UTProfilerException : public QException
{
public:
    UTProfilerException(const QString& m, const QString& f = 0)
        :message(m),file(f)
    {}

    UTProfilerException *clone() const { return new UTProfilerException(*this); }

    virtual ~UTProfilerException() throw() {}

    void raise() const { std::cout << "SAlut"; }

    QString getMessage(){return message;}

    QString getFile(){return file;}

private:
    QString message;
    QString file;
};

#endif // UTPROFILEREXCEPTION_H
