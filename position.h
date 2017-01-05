#ifndef POSITION_H
#define POSITION_H


struct Position
{
    unsigned int x;
    unsigned int y;
    Position(unsigned int xVal, unsigned int yVal) : x(xVal), y(yVal) {}

    static Position *getNewPosition(unsigned int x, unsigned int y){
        return new Position(x, y);
    }

    static Position *getNewPositionInDirection(Position* currPos, char direction){
        Position *targetPos = currPos;
        switch (direction) {
        case 'W':
            targetPos = new Position(currPos->x-1, currPos->y);
            break;
        case 'S':
            targetPos = new Position(currPos->x+1, currPos->y);
            break;
        case 'A':
            targetPos = new Position(currPos->x, currPos->y-1);
            break;
        case 'D':
            targetPos = new Position(currPos->x, currPos->y+1);
            break;
        default:
            std::cout << "Invalid input." << std::endl;
            break;
        }
        return targetPos;
    }
};

#endif // POSITION_H
