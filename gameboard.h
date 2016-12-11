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

class GameBoard
{
private:
    std::vector<std::vector<GameField *>> board;
    std::vector<Monster *> monsters;
    static Monster *left;
    Hero *hero;
    const int sizeX = 10;
    const int sizeY = 10;
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
};

#endif // GAMEBOARD_H
