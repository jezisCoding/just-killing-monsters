#include "staticoutputstream.h"

std::ostringstream StaticOutputStream::wout = std::ostringstream();

std::ostringstream &StaticOutputStream::getStream(){
    return wout;
}
