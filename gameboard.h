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
#include "my2dvector.h"
#include "entityfactory.h"
#include "myexceptions.h"

class GameBoard
{
private:
    My2DVector<GameField *> board;
    Hero *hero;
    EntityFactory *ef;
        //for implementation of monstersDead with vector
    /*std::vector<Monster *> monsters;
    static Monster *left;*/
public:
    GameBoard(EntityFactory* ef);
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
    Environment::fieldType getEnvTypeAt(Position *atPos);
    void setFieldEntityTo(Entity *toEntity);
    void setFieldEntityAt(Position* at, Entity *toEntity);
};

#endif // GAMEBOARD_H
