#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "gameboard.h"
#include "entityfactory.h"
#include "myexceptions.h"
#include <fstream>

class GameEngine
{
private:
    GameBoard *gameBoard;
    Hero* hero;
    void welcome() const;
    bool heroAction(char direction);
    char getKeyboardInput() const throw(invalid_input);
    bool saveGame() const throw(file_error);
    void loadGame() throw(file_error);
    bool endGame(char input) const;

public:
    GameEngine();
    ~GameEngine();
    void play();
};

#endif // GAMEENGINE_H
