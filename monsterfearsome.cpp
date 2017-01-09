#include "monsterfearsome.h"

MonsterFearsome::MonsterFearsome(Position* position, std::string mapSign, std::string name,
                                 int health, int attack, float fearsomeness)
    : Monster(position, mapSign, name, health, attack)
{
    this->fearsomeness = fearsomeness;
}

MonsterFearsome::MonsterFearsome(const MonsterFearsome& from) : Monster(position, mapSign, name, health, attack)
{
    this->mapSign = "V";
    this->name = from.getName() + "(split)";
    this->health = from.getHealth();
    this->attack = from.getAttack()/2;
    this->fearsomeness = from.getFearsomeness();
}

MonsterFearsome::~MonsterFearsome()
{

}

uint8_t MonsterFearsome::defendYourselfFrom(Creature *who) {
    who->dealDmg(this, who->getAttack());
    dealDmg(who, getAttack());

    uint8_t outcome = 0;    //bitwise
    if (who->getHealth() < 1) outcome |= 1;
    if (this->getHealth() < 1) outcome |= 2;
    if (monsterSplit()) outcome |= 4;
        //zobere poziciu hera, checkne ci je volno naokolo, hodi mu klona,
    return outcome;
}

int MonsterFearsome::getAttack() const{
    return fearsomeness*attack;
}

int MonsterFearsome::getFearsomeness() const{
    return fearsomeness;
}

bool MonsterFearsome::monsterSplit() const{
    return this->getHealth() <= this->getMAX_HEALTH()/2;
}
