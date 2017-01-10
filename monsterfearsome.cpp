#include "monsterfearsome.h"

MonsterFearsome::MonsterFearsome(Position* position, std::string mapSign, std::string name,
                                 int health, int attack, float fearsomeness)
    : Monster(position, mapSign, name, health, attack)
{
    this->fearsomeness = fearsomeness;
}

MonsterFearsome::MonsterFearsome(MonsterFearsome& orig) : Monster(orig)
{
    orig.setMapSign("V");

    this->mapSign = "V";
    this->name = orig.getName() + "(split)";
    this->health = orig.getHealth();
    this->attack = orig.getAttack()/2;
    this->fearsomeness = orig.getFearsomeness();
}

MonsterFearsome::~MonsterFearsome()
{

}

uint8_t MonsterFearsome::defendYourselfFrom(Creature *who) {
    who->dealDmg(this, who->getAttack());
    dealDmg(who, getAttack());
    std::cout << std::endl;

    uint8_t outcome = 0;    //bitwise
    if (who->getHealth() < 1) outcome |= 1;
    if (this->getHealth() < 1) outcome |= 2;
    if (monsterSplit()) outcome |= 4;

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
