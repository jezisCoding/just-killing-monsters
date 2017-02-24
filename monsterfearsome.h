#ifndef FEARSOMEMONSTER_H
#define FEARSOMEMONSTER_H

#include "monster.h"

/*!
 * \brief The MonsterFearsome class
 *      FearsomeMonster is a special type of Monster.
 *
 * FearsomeMonster is a type of Monster, who splits in 2
 * (and keeps splitting on each hit) when his health gets below half of his health pool.
 */
class MonsterFearsome : public Monster
{
protected:
    float fearsomeness;
public:
    MonsterFearsome(char mapSign, std::string name, int health, int attack, float fearsomeness);
    MonsterFearsome(MonsterFearsome& from);
    ~MonsterFearsome();

private:
    /*!
     * \brief defendYourselfFrom
     *      A specialized version of defense, which includes return value for monsterSplit for GameEngine
     * \param who The attacking Creature
     * \return The bitwise return values of Creature::defendYourselfFrom with monsterSplit added
     */
    uint8_t defendYourselfFrom(FieldActor *who) override;
    void addToXml(QFile& where, QXmlStreamWriter& writer) const;

public:
    int getAttack() const;
    int getFearsomeness() const;
    bool monsterSplit() const;
};

#endif // FEARSOMEMONSTER_H
