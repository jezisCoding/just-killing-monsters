#ifndef STATICOUTPUTSTREAM_H
#define STATICOUTPUTSTREAM_H

#include <streambuf>
#include <iostream>
#include <sstream>

struct StaticOutputStream
{
    static std::ostringstream wout;

    static std::ostringstream& getStream();

    staticOutputStream();
};

#endif // STATICOUTPUTSTREAM_H
