#include "entityfactory.h"

EntityFactory::EntityFactory()
{

}

Monster* EntityFactory::getNewMonster(const bool& fearsome) const{
    if (fearsome) return new MonsterFearsome('W', "A scary ass splitting monster",
                                             MonsterFearsome::getMAX_HEALTH(), 15, 1.5);
    else return new Monster('M', "A not too scary monster",
                            Creature::getMAX_HEALTH(), 15);
}

Hero* EntityFactory::getNewHero(Position* heroPos) const{
    return new Hero(heroPos, 'H', "The hero", Hero::getMAX_HEALTH(), 20, 15, true);
}

Potion* EntityFactory::getNewPotion() const{
    return new Potion('P', 50);
}

Environment* EntityFactory::getNewEnvironment(const Environment::fieldType &type) const{
    switch (type) {
    case Environment::Empty:
        return new Environment('.', Environment::Empty);
        break;
    case Environment::Corpse:
        return new Environment('X', Environment::Corpse);
        break;
    case Environment::Tree:
        return new Environment('T', Environment::Tree);
        break;
    case Environment::Rock:
        return new Environment('O', Environment::Rock);
        break;
    default:
        return 0; //nullptr
        break;
    }
}
