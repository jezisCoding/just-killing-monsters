#ifndef MY2DVECTOR_H
#define MY2DVECTOR_H

#include <vector>
#include <algorithm>
#include <iostream>

#include "position.h"



/*!
 * \brief The My2DBoardVector class
 *      This class is a std::vector wrapper customized for my needs for the GameBoard.
 *
 * It is also more processor time efficient than a classic vector of vectors.
 */
template <class T>
class My2DBoardVector
{
    std::vector<T> myVector;
    unsigned int sizeX = 10, sizeY = 10;
    typedef typename std::vector<T>::const_iterator const_iterator;

public:
    My2DBoardVector(unsigned int x, unsigned int y) : sizeX(x), sizeY(y){}

    const T& at(unsigned int x, unsigned int y) const {return myVector.at(x * sizeY + y);}
    T& at(unsigned int x, unsigned int y) {return myVector.at(x * sizeY + y);}

    const T& at(unsigned int x) const {return myVector.at(x);}
    T& at(unsigned int x) {return myVector.at(x);}

    const T& at(Position* pos) const {return at(pos->x, pos->y);}
    T& at(Position *pos) {return at(pos->x, pos->y);}

    void push_back(const T& value){myVector.push_back(value);}

    unsigned int getSizeX() const{return sizeX;}

    unsigned int getSizeY() const{return sizeY;}

    const_iterator begin() const{return myVector.begin();}

    const_iterator end() const{return myVector.end();}

    /*!
     * \brief The MyDeleter struct
     *      This method can be used in a for_each for deleting the whole vector.
     */
    struct MyDeleter : std::unary_function<T, void>{
        void operator()(T fieldPtr){delete fieldPtr;}
    };

    void clear(){myVector.clear();}

    void deleteFieldFromVector(T *value){delete value;}

    void setSizes(const unsigned int& x, const unsigned int& y){sizeX = x; sizeY = y;}

    bool empty(){return myVector.empty();}

    void pop_back(){myVector.pop_back();}
};

#endif // MY2DVECTOR_H
