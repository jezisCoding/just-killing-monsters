#include "staticoutputstream.h"

std::ostringstream StaticOutputStream::wout = std::ostringstream();

std::ostringstream &StaticOutputStream::getStream(){
    return wout;
}

std::ostringstream StaticOutputStream::operator<<(const QString& str)
{
    //return wout << str.toStdString();
}
