#ifndef CREATURE_H
#define CREATURE_H

#include "potion.h"
#include "fieldactor.h"

#include <cstdint>

/*!
 * \brief The Creature class
 *      This class describes Creatures on the GameBoard and their interactions.
 */
class Creature : public FieldActor
{
protected:
    std::string name;
    int health;
    int attack;
    static const int MAX_HEALTH = 100;

public:
    Creature(char mapSign, std::string name, int health, int attack);
    Creature(const Creature& orig);
    virtual ~Creature();

    int interaction(FieldActor *with);

protected:
    int reaction(FieldActor *to);

    //! Self defense when attacked
    /*!
     * bitwise return values: death of:
     * 0-nobody * 1-the other creature(who/attacker/hero) * 2-this creature(this/defender/monster) * 3-both creatures
     */
    virtual uint8_t defendYourselfFrom(FieldActor *who);

public:
    //! Method used in defendYourselfFrom that takes care of dealing damage itself
    virtual void dealDmg(Creature *to, const int& dmgDealt);
    virtual void die();

    std::string getName() const;
    virtual int getAttack() const;
    int getHealth() const;
    static int getMAX_HEALTH();
    void setHealth(const int& toValue);

    bool operator== (const Creature& right);
};

#endif // CREATURE_H
