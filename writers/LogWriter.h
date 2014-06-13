#ifndef LogWriter_h
#define LogWriter_h

#include <QString>
#include <QDateTime>
#include <iostream>
#define q2s(string) string.toStdString()

class LogWriter {

public:
    static void write(const QString source, const QString& message)
    {
        std::cout << q2s(QDateTime::currentDateTime().toString())
                  << " : From <" << q2s(source) << "> : "
                  << q2s(message)
                  << std::endl;
    }


};

#endif // LogWriter_h

