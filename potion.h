#ifndef POTION_H
#define POTION_H

#include "fieldactor.h"

/*!
 * \brief The Potion class
 *  This class describes a special type of Actor on the board.
 *
 * A Creature can drink the potion(via interaction) and heal itself, destroying the potion.
 */
class Potion : public FieldActor
{
private:
    int healthBonus;
public:
    Potion(char mapSign, int healthBonus);
    ~Potion();

    /*!
     * \brief reaction
     *      This overload of reaction heals the interacting creature and destroys the postion.
     * \param to Creature reacted to
     * \return Return values depending on the health of the interacting Creature
     *      0 if the hero is full health(nothing happens) 2 if the potion is drank(its destroyed)
     */
    int reaction(FieldActor *to) override;
    void die() override;
    int heal(FieldActor* who);

    int getHealthBonus();
};

#endif // POTION_H
