#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

#include "gamefield.h"
#include "entity.h"
#include "potion.h"
#include "monster.h"
#include "environment.h"
#include "my2dboardvector.h"
#include "entityfactory.h"
#include "myexceptions.h"

class GameBoard
{
private:
    const unsigned int SIZE_X = 10, SIZE_Y = 10;

    My2DBoardVector<GameField *> board;
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

public:
    bool monstersDead() const;
    void printBoard() const;
    bool saveBoard() throw(file_error);
    void loadBoard() const throw(file_error);
    void moveHero(Position *toPos);

    Position *getNewRandomFreeBoardPosition() const;
    bool freeFieldAt(Position *atPos) const;

private:
    bool entityEmptyPosition(Position* pos) const;
    bool passableEnvironmentAt(Position *pos) const;

public:
    Hero *getHero() const;
    GameField *getFieldAt(Position *atPos) const;
    Entity *getEntityAt(Position *atPos) const;
    Environment::fieldType getEnvTypeAt (Position *atPos) const;

    void setFieldEntityAtPosition(Entity *toEntity, Position *toPos);
    void setFieldEntityToItsPosition(Entity *entity);
    void deleteEntityFromBoardAt(Position *atPos);
    void deleteEntityFromBoard(Entity *entity);
};

#endif // GAMEBOARD_H
