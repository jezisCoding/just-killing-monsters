#ifndef STATICOUTPUTSTREAM_H
#define STATICOUTPUTSTREAM_H

#include <streambuf>
#include <iostream>
#include <sstream>
#include <QString>

    ///StaticOutputStream
struct sos
{
    static std::ostringstream bout; //board out
    static std::ostringstream iout; //info out

    static std::ostringstream& getStream();
};

#endif // STATICOUTPUTSTREAM_H
