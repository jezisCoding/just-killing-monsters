#ifndef HERO_H
#define HERO_H

#include "creature.h"
#include "position.h"

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
    int readiness;
    bool surpriseAttack;
    Position* pos;

public:
    Hero(Position *pos, char mapSign, std::string name, int health, int attack,
         int readiness, bool surpriseAttack);
    ~Hero();

private:
    /*!
     * \brief defendYourselfFrom
     *      This override exists so that it can call Hero's own dealDmg implementation.
     * \param who
     * \return bitwise return values
     */
    uint8_t defendYourselfFrom(FieldActor *who) override;
    void dealDmg(Creature *to, const int& dmgDealt);
    void die() override;
    void addToXml(QFile& where, QXmlStreamWriter& writer) const;

public:
    int getAttack() const;
    void resetSurpriseHit();
    Position* getPosition();
    void setPosition(Position* to);
};

#endif // HERO_H
