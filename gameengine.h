#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "gameboard.h"

class GameEngine
{
private:
    GameBoard *gameBoard;
    Hero* hero;
public:
    GameEngine();
    void play();
    void heroAction(char direction);
    void welcome();
    Position *createTargetPosition(char input);
};

#endif // GAMEENGINE_H
