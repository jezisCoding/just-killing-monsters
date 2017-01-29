#ifndef MONSTER_H
#define MONSTER_H

#include "creature.h"

/*!
 * \brief The Monster class
 *      This class is a subtype of Creature.
 *
 * You need to kill all the monsters in order to win the game.
 * It's damage dealing mechanism is a bit different from Creature.
 */
class Monster : public Creature
{
    //!
    //! \brief monsterCount
    //!     A static member which counts the monsters on board, when it
    //!     descends to 0, the game is over.
    //!
    static int monsterCount;
public:
    Monster(Position* position, char mapSign, std::string name, int health, int attack);
    Monster(const Monster& orig);
    virtual ~Monster();

    static int getMonsterCount();

    bool operator==(const Monster &right);
};

#endif // MONSTER_H
