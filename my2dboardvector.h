#ifndef MY2DVECTOR_H
#define MY2DVECTOR_H

#include <vector>
#include <algorithm>
#include <iostream>

#include "position.h"



/*!
 * \brief This class is a std::vector wrapper customized for my needs for the GameBoard.
 *
 * It is also more processor time efficient than a classic vector of vectors.
 */
template <class T>
class My2DBoardVector
{
private:
    std::vector<T> myVector;
    unsigned int sizeX = 10, sizeY = 10;
    typedef typename std::vector<T>::const_iterator const_iterator;
public:
    //My2DBoardVector(unsigned int x, unsigned int y) : sizeX(x), sizeY(y){}

    inline const T& at(unsigned int x, unsigned int y) const {return myVector.at(x * sizeY + y);}
    inline T& at(unsigned int x, unsigned int y) {return myVector.at(x * sizeY + y);}

    inline const T& at(unsigned int x) const {return myVector.at(x);}
    inline T& at(unsigned int x) {return myVector.at(x);}

    inline const T& at(Position* pos) const {return at(pos->x, pos->y);}
    inline T& at(Position *pos) {return at(pos->x, pos->y);}

    void push_back(const T& value){myVector.push_back(value);}

    unsigned int getSizeX() const{return sizeX;}

    unsigned int getSizeY() const{return sizeY;}

    const_iterator begin() const{return myVector.begin();}

    const_iterator end() const{return myVector.end();}

    /*!
     * \brief This method can be used in a for_each for deleting the whole vector.
     */
    struct MyDeleter : std::unary_function<T, void>{
        void operator()(T fieldPtr){delete fieldPtr;}
    };

    void clear(){myVector.clear();}

    void deleteFieldFromVector(T *value){delete value;}

    void setSizes(const unsigned int& x, const unsigned int& y){sizeX = x; sizeY = y;}
};

#endif // MY2DVECTOR_H
