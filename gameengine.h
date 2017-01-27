#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "gameboard.h"
#include "myexceptions.h"
#include <fstream>
#include <cstdint>

/*!
 * \brief This class is the core of the whole program.
 *
 * It contains the main loop, takes care of user input and communicates it further
 * among other functionality.
 */
class GameEngine
{
private:
    GameBoard *gameBoard;
    Hero* hero;

public:
    GameEngine();
    ~GameEngine();
    //! This is the main game loop
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
