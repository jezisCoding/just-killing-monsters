#ifndef POTION_H
#define POTION_H

#include "entity.h"

/*!
 * \brief The Potion class
 *  This class describes a special type of Entity on the board.
 *
 * A Creature can drink the potion(via interaction) and heal itself, destroying the potion.
 */
class Potion : public Entity
{
private:
    int healthBonus;
public:
    Potion(Position* position, char mapSign, int healthBonus);
    ~Potion();

    /*!
     * \brief reaction
     *      This overload of reaction heals the interacting creature and destroys the postion.
     * \param to Creature reacted to
     * \return Return values depending on the health of the interacting Creature
     *      0 if the hero is full health(nothing happens) 2 if the potion is drank(its destroyed)
     */
    int reaction(Creature *to);

    int getHealthBonus();
};

#endif // POTION_H
