#include "entityfactory.h"

EntityFactory::EntityFactory()
{

}

Monster* EntityFactory::createNewMonster(const bool& fearsome) const{
    if (fearsome) return new MonsterFearsome('W', "A scary ass splitting monster",
                                             MonsterFearsome::getMAX_HEALTH(), 15, 1.5);
    else return new Monster('M', "A not too scary monster",
                            Creature::getMAX_HEALTH(), 15);
}

Hero* EntityFactory::createNewHero(Position* heroPos) const{
    return new Hero('H', "The hero", Hero::getMAX_HEALTH(), 20, 15, true, heroPos);
}

Potion* EntityFactory::createNewPotion() const{
    return new Potion('P', 50);
}

Environment* EntityFactory::createNewEnvironment(const Environment::fieldType &type) const{
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

Monster *EntityFactory::createNewMonster(char mapSign, std::__cxx11::string name, int health, int attack){
    return new Monster(mapSign, name, health, attack);
}

MonsterFearsome *EntityFactory::createNewMonsterF(char mapSign, std::__cxx11::string name, int health,
                                                  int attack, float fearsomeness){
    return new MonsterFearsome(mapSign, name, health, attack, fearsomeness);
}

Hero *EntityFactory::createNewHero(char mapSign, std::__cxx11::string name, int health, int attack,
                                   int readiness, bool surpriseAttack, Position *pos){
    return new Hero(mapSign, name, health, attack, readiness, surpriseAttack, pos);
}

Potion *EntityFactory::createNewPotion(const char mapSign, const int healthBonus){
    return new Potion(mapSign, healthBonus);
}

Environment *EntityFactory::createNewEnvironment(const char mapSign, const Environment::fieldType type){
    return new Environment(mapSign, type);
}
