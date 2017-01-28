#ifndef HERO_H
#define HERO_H

#include "creature.h"

/*!
 * \brief The Hero class
 *      The Hero is a subclass of Creature.
 *
 * The hero is the playable character in the game.
 * He differs very little from other Creatures in the game.
 * His damage dealing mechanism is different from Creature.
 */
class Hero : public Creature
{
private:
    int readiness;
    bool surpriseAttack;
public:
    Hero(Position *position, std::string mapSign, std::string name, int health, int attack,
         int readiness, bool surpriseAttack);
    ~Hero();

private:
    /*!
     * \brief defendYourselfFrom
     *      This override exists so that it can call Hero's own dealDmg implementation.
     * \param who
     * \return bitwise return values
     */
    uint8_t defendYourselfFrom(Creature *who) override;
    void dealDmg(Creature *to, const int& dmgDealt);

public:
    int getAttack() const;
    void resetSurpriseHit();
};

#endif // HERO_H
