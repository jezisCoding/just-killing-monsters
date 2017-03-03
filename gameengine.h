#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "gameboard.h"
#include "myexceptions.h"

#include <fstream>
#include <cstdint>
#include <QCoreApplication>

#include <streambuf>
#include <iostream>
#include <sstream>

/*!
 * \brief The GameEngine class
 *      This class is the core of the whole program.
 *
 * It contains the main loop, takes care of user input and communicates it further
 * among other functionality.
 */
class GameEngine
{
private:
    GameBoard *gameBoard;
    Hero* hero;

    //std::streambuf* oldCoutStreamBuf;
    //std::ostringstream* myCout;

public:
    GameEngine();
    ~GameEngine();
    void play();

    void GUIKeyinput(int key);
    void welcome() const;
    void saveGame(const QString& fileName) const throw(file_error);
    void loadGame(const QString& fileName) throw(file_error);
    bool endGame();

private:
    void heroTurn(const char &direction);
    void heroAction(FieldActor *targetFieldActor, Position *targetPosition);
    char getKeyboardInput() const throw(invalid_input);    
    bool endGame(const char &input);
    void splitMonsterAround(FieldActor *monster, Position* centerPos);

    void deleteBoard();
};

#endif // GAMEENGINE_H
