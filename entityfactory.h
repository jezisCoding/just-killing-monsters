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
    Monster* getNewMonster(const bool& fearsome) const;
    Hero* getNewHero(Position* heroPos) const;
    Potion* getNewPotion() const;
    Environment* getNewEnvironment(const Environment::fieldType& type) const;
};

#endif // EntityFactory_H
