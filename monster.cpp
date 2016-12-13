#include "monster.h"

int Monster::monsterCount = 0;  //this seems like im declaring it again

Monster::Monster(std::__cxx11::string mapSign, std::__cxx11::string name, int health, int attack, float fearsomeness)
    : Creature(name, mapSign, health, attack)
{
    this->fearsomeness = fearsomeness;
    monsterCount++;
}

Monster::~Monster(){
    std::cout << name + ": \"Bleeurhgdjksfgdak......h.\\\"  *pepsi*" << std::endl;
    monsterCount--;
}

int Monster::getFearsomeness(){
    return fearsomeness;
}
int Monster::getAttack(){
    return fearsomeness*attack;
}

/*bool Monster::isSame(const Monster& right){
    if (this->getName()==right.getName() && this->getHealth()==right.getHealth()) return true;
    return false;
}*/

int Monster::getMonsterCount(){
    return monsterCount;
}
