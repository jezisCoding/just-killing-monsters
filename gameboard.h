#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>//<algorithm>
#include <iomanip>

#include "gamefield.h"
#include "interactiveentity.h"
#include "potion.h"

class GameBoard
{
private:
    std::vector<std::vector<GameField *>> board;
    Hero* hero;
public:
    GameBoard();
    Hero* getHero();
    GameField *getFieldAt(Position *atPos);
    Environment::fieldType getEnvTypeAt(Position *atPos);
    void setFieldEntityAt(Position *atPos, InteractiveEntity *toEntity);
    void moveHero(Position *toPos);

    void printBoard();
    void deleteEntity(InteractiveEntity *entity);
    void deleteEntityAt(Position *atPos);
    void interactHero(InteractiveEntity *with);

    //gettery settery so specialnymi podmienkami a akciami vsade.?
    void interactHeroWith(InteractiveEntity *with);
};

#endif // GAMEBOARD_H
