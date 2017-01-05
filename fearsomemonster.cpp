#include "fearsomemonster.h"

FearsomeMonster::FearsomeMonster(std::string mapSign, std::string name, int health, int attack, float fearsomeness) : Monster(mapSign, name, health, attack)
{
    this->fearsomeness = fearsomeness;
}

FearsomeMonster::~FearsomeMonster()
{

}

int FearsomeMonster::getAttack(){
    return fearsomeness*attack;
}

int FearsomeMonster::getFearsomeness(){
    return fearsomeness;
}
