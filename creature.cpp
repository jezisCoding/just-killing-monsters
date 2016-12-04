#include "creature.h"

Creature::Creature(int health, int attack, std::__cxx11::string mapSign) : InteractiveEntity(mapSign)
{
    this->health = health;
    this->attack = attack;
}

int Creature::getAttack() const{
    return attack;
}

int Creature::getHealth() const{
    return health;
}

void Creature::setHealth(int toValue){
    this->health = toValue;
}

int Creature::interaction(InteractiveEntity *with){
    return with->interaction(this);
}

    /* attack and self defense when attacked
     *
     * return values: death of:
     * 0-nobody
     * 1-this creature
     * 2-the other creature
     * 3-both creatures
     */
int Creature::interaction(Creature *with){
    health -= with->getAttack();
    with->setHealth(with->getHealth() - this->attack);

    if (this->health < 1) return 1;
    else if (with->getHealth() < 1) return 2;
    else if (with->getHealth() < 1 || this->health < 1) return 3;
    else return 0;
}
