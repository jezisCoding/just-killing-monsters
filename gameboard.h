#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include <iomanip>
#include <algorithm>

#include "gamefield.h"
#include "entity.h"
#include "potion.h"
#include "monster.h"
#include "environment.h"
#include "my2dvector.h"

class GameBoard
{
private:
    My2DVector<GameField *> board;
    Hero *hero;
        //for implementation of monstersDead with vector
    /*std::vector<Monster *> monsters;
    static Monster *left;*/
public:
    GameBoard();
    ~GameBoard();
    Hero *getHero();
    GameField *getFieldAt(Position *atPos);
    Environment::fieldType getEnvTypeAt(Position *atPos);
    void setFieldEntityAt(Position *atPos, Entity *toEntity);
    void moveHero(Position *toPos);

    void printBoard();
    void deleteEntityAt(Position *atPos);
    bool monstersDead() const;
    static bool monsterComparison(Monster *right);
    void initializeEnvironment();
    void initializeEntities();
};

#endif // GAMEBOARD_H
