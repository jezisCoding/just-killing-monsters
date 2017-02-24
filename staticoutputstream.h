#ifndef STATICOUTPUTSTREAM_H
#define STATICOUTPUTSTREAM_H

#include <streambuf>
#include <iostream>
#include <sstream>
#include <QString>

struct StaticOutputStream
{
    static std::ostringstream wout;

    static std::ostringstream& getStream();

    std::ostringstream operator<<(const QString& str);

    staticOutputStream();
};

#endif // STATICOUTPUTSTREAM_H
