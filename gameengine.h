#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "gameboard.h"
#include "myexceptions.h"
#include <fstream>
#include <cstdint>

class GameEngine
{
private:
    GameBoard *gameBoard;
    Hero* hero;

public:
    GameEngine();
    ~GameEngine();
    void play();

private:
    void welcome() const;
    void heroTurn(char direction);
    void heroAction(Entity *targetFieldEntity);
    char getKeyboardInput() const throw(invalid_input);
    void saveGame() const throw(file_error);
    void loadGame() throw(file_error);
    bool endGame(char input) const;
    void splitMonsterAround(Entity *monster, Position* centerPos);
};

#endif // GAMEENGINE_H
