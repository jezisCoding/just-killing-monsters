#ifndef MY2DVECTOR_H
#define MY2DVECTOR_H

#include <vector>

template <class T>
class My2DVector
{
private:
    std::vector<T> myVector;
    unsigned int sizeX, sizeY;
public:
    const T& at(unsigned int x, unsigned int y) const {
        return myVector.at(x * sizeY + y);
    }

    T& at(unsigned int x, unsigned int y) {
        return myVector.at(x * sizeY + y);
    }
};

#endif // MY2DVECTOR_H
