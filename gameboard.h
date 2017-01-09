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

    void initializeEnvironment();
    void initializeEntities();
    void deleteEntityAt(Position *atPos);
    bool monstersDead() const;
    void printBoard() const;
    bool saveBoard() throw(file_error);
    void loadBoard() const throw(file_error);

    Hero *getHero() const;
    void moveHero(Position *toPos);
    GameField *getFieldAt(Position *atPos) const;
    Entity *getEntityAt(Position *atPos);
    bool emptyFieldAt(Position *atPos);
    Environment::fieldType getEnvTypeAt(Position *atPos);
    void setFieldEntityToPosition(Entity *toEntity, Position *toPos);
    void setFieldEntityToItsPosition(Entity *entity);
    bool entityEmptyPosition(Position* pos);
};

#endif // GAMEBOARD_H
