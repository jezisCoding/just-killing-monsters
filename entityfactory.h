#ifndef EntityFactory_H
#define EntityFactory_H

#include "monsterfearsome.h"
#include "hero.h"
#include "potion.h"
#include "environment.h"

/*!
 * \brief The EntityFactory class
 *      This class is used for returning standardized instances of Entities.
 */
class EntityFactory
{
public:
    EntityFactory();

    Monster* createNewMonster(const bool& fearsome) const;
    Hero* createNewHero(Position* heroPos) const;
    Potion* createNewPotion() const;
    Environment* createNewEnvironment(const Environment::fieldType& type) const;

    Monster* createNewMonster(char mapSign, std::string name, int health, int attack);
    MonsterFearsome* createNewMonsterF(char mapSign, std::string name, int health, int attack, float fearsomeness);
    Hero* createNewHero(char mapSign, std::string name, int health, int attack,
         int readiness, bool surpriseAttack, Position *pos);
    Potion* createNewPotion(const char mapSign, const int healthBonus);
    Environment* createNewEnvironment(const char mapSign, const Environment::fieldType type);
};

#endif // EntityFactory_H
