#ifndef POSITION_H
#define POSITION_H


struct Position
{
    unsigned int x;
    unsigned int y;
    enum direction{Up, Down, Left, Right};

    Position() : x(0), y(0){}
    Position(unsigned int xVal, unsigned int yVal) : x(xVal), y(yVal) {}

    static Position *getNewPosition(unsigned int x, unsigned int y){
        return new Position(x, y);
    }

    static Position getNewPositionInDirection(Position* currPos, char direct){
        Position targetPos;
        switch (direct) {
        case 'W':
            targetPos = Position(currPos->x-1, currPos->y);
            break;
        case 'S':
            targetPos = Position(currPos->x+1, currPos->y);
            break;
        case 'A':
            targetPos = Position(currPos->x, currPos->y-1);
            break;
        case 'D':
            targetPos = Position(currPos->x, currPos->y+1);
            break;
        default:
            std::cout << "Invalid direction." << std::endl;
            break;
        }
        return targetPos;
    }

    static Position getNewPositionInDirection(Position* currPos, direction direct){
        Position targetPos;
        switch (direct) {
        case Up:
            targetPos = Position(currPos->x-1, currPos->y);
            break;
        case Down:
            targetPos = Position(currPos->x+1, currPos->y);
            break;
        case Left:
            targetPos = Position(currPos->x, currPos->y-1);
            break;
        case Right:
            targetPos = Position(currPos->x, currPos->y+1);
            break;
        default:
            std::cout << "Invalid direction." << std::endl;
            break;
        }
        return targetPos;
    }

};

#endif // POSITION_H
