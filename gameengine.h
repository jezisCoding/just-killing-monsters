#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "gameboard.h"
#include "entityfactory.h"
#include <fstream>

class GameEngine
{
private:
    GameBoard *gameBoard;
    Hero* hero;
    void welcome() const;
    bool heroAction(char direction);
    char getKeyboardInput() const;
    bool saveGame() const;
    void loadGame();

    bool endGame(char input) const;

public:
    GameEngine();
    ~GameEngine();
    void play();
};

#endif // GAMEENGINE_H
