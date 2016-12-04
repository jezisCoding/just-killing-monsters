#ifndef POSITION_H
#define POSITION_H


struct Position
{
    unsigned int x;
    unsigned int y;
    Position(unsigned int x, unsigned int y){
        this->x = x;
        this->y = y;
    }
};

#endif // POSITION_H
