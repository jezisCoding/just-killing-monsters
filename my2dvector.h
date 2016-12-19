#ifndef MY2DVECTOR_H
#define MY2DVECTOR_H

#include <vector>
#include <algorithm>
#include <iostream>

template <class T>
class My2DVector
{
private:
    std::vector<T> myVector;
    const unsigned int sizeX = 10, sizeY = 10;
    typedef typename std::vector<T>::const_iterator const_iterator;
public:
    const T& at(unsigned int x, unsigned int y) const {return myVector.at(x * sizeY + y);}

    T& at(unsigned int x, unsigned int y) {return myVector.at(x * sizeY + y);}

    void push_back(const T& value){myVector.push_back(value);}

    unsigned int getSizeX() const{return sizeX;}

    unsigned int getSizeY() const{return sizeY;}

    const_iterator begin(){return myVector.begin();}

    const_iterator end(){return myVector.end();}

    struct MyDeleter : std::unary_function<T, void>{
        void operator()(T fieldPtr){delete fieldPtr;}
    };

    void clear(){
        myVector.clear();
    }

    void deleteFieldFromVector(T *value){
        delete value;
    }
};

#endif // MY2DVECTOR_H
