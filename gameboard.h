#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <memory>

#include "gamefield.h"
#include "fieldentity.h"
#include "potion.h"
#include "monster.h"
#include "environment.h"
#include "my2dboardvector.h"
#include "entityfactory.h"
#include "myexceptions.h"

/*!
 * \brief The GameBoard class
 *      GameBoard is the playground on which the whole game takes place.
 *
 * It takes care of all the functionality concerning maintenance of the board,
 * it provides some services for GameEngine, such as deleting and moving Entities,
 * saving and loading game state and so on.
 */

class GameBoard
{
    const unsigned int SIZE_X = 10, SIZE_Y = 10;

    My2DBoardVector<GameField*> board;
    EntityFactory *ef;
    Hero *hero;
public:
    GameBoard();
    ~GameBoard();

private:
    void initializeBoard();
    void initializeBoardRnd();
    void initializeEnvironment();
    void initializeEnvironmentRnd();
    void initializeEntities();
    void initializeEntitiesRnd();
    void initializeBoardBase();

public:
    bool monstersDead() const;
    void printBoard() const;
    /*!
     * \brief saveBoard
     *     The current implementation of saveBoard().
     * \return whether the save was successful
     */
    bool saveBoard() throw(file_error);
    void loadBoard() const throw(file_error);
    void moveHero(Position *toPos);

    /*!
     * \brief getNewRandomFreeBoardPosition
     *      Returns a pointer to an instance of Position, which is randomized
     *      and checked if the GameField at given position is "free".
     *
     * "Free" meaning that the environment is accessible and there is no Actor there yet.
     * \return the instance of Position
     */
    Position *getNewRandomFreeBoardPosition() const;
    bool freeFieldAt(Position *atPos) const;

private:
    bool actorEmptyPosition(Position* pos) const;
    bool passableEnvironmentAt(Position *pos) const;

public:
    Hero *getHero() const;
    GameField *getFieldAt(Position *atPos) const;
    FieldActor *getActorAt(Position *atPos) const;
    Environment::fieldType getEnvTypeAt (Position *atPos) const;

    void setFieldActorAt(FieldActor *toActor, Position *toPos);
    void deleteActorAt(Position *atPos);
    void killActorAt(Position* at);
};

#endif // GAMEBOARD_H
