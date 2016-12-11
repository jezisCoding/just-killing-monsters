#ifndef POSITION_H
#define POSITION_H


struct Position
{
    unsigned int x;
    unsigned int y;
    Position(unsigned int xVal, unsigned int yVal) : x(xVal), y(yVal) {}
};

#endif // POSITION_H
