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
    ~GameEngine();
    void play();
    bool heroAction(char direction);
    void welcome();
    Position *createTargetPosition(char input);
    bool endGame(char input) const;
    char getKeyboardInput() const;
};

#endif // GAMEENGINE_H
