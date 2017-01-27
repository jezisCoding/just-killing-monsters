#ifndef CREATURE_H
#define CREATURE_H

#include "entity.h"
#include "potion.h"

#include <cstdint>

/*!
 * \brief This class describes Creatures on the GameBoard and their interactions.
 */
class Creature : public Entity
{
protected:
    std::string name;
    int health;
    int attack;
    static const int MAX_HEALTH = 100;

public:
    Creature(Position* position, std::string mapSign, std::__cxx11::string name, int health, int attack);
    Creature(const Creature& orig);
    virtual ~Creature();

    int interaction(Entity *with);

protected:
    int reaction(Creature *to);

    /*! \brief This method manages the fight between Creatures
     *
     * \return bitwise return values: death of:
     * 0-nobody * 1-the other creature(who/attacker/hero) * 2-this creature(this/defender/monster) * 3-both creatures
     */
    virtual uint8_t fight(Creature *who);

public:
    //! Method used in fight() that takes care of dealing damage itself
    virtual void dealDmg(Creature *to, const int& dmgDealt);

    std::string getName() const;
    virtual int getAttack() const;
    int getHealth() const;
    static int getMAX_HEALTH();
    void setHealth(const int& toValue);

    //! Operator for comparing Creatures based on name and current health
    bool operator== (const Creature& right);
};

#endif // CREATURE_H
