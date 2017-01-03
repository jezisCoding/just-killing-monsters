#include "monster.h"

int Monster::monsterCount = 0;

Monster::Monster(std::__cxx11::string mapSign, std::__cxx11::string name, int health, int attack)
    : Creature(name, mapSign, health, attack)
{
    monsterCount++;
}

Monster::~Monster(){
    std::cout << name + ": \"Bleeurhgdjksfgdak......h.\\\"  *pepsi*" << std::endl;
    monsterCount--;
}

/*bool Monster::isSame(const Monster& right){
    if (this->getName()==right.getName() && this->getHealth()==right.getHealth()) return true;
    return false;
}*/

int Monster::getMonsterCount(){
    return monsterCount;
}
