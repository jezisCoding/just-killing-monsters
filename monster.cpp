#include "monster.h"

int Monster::monsterCount = 0;

Monster::Monster(Position* position, std::__cxx11::string mapSign, std::__cxx11::string name, int health, int attack)
    : Creature(position, name, mapSign, health, attack)
{
    monsterCount++;
}

Monster::~Monster()
{
    std::cout << name + ": \"Bleeurhgdjksfgdak......h.\\\"  *pepsi*" << std::endl;
    monsterCount--;
}

int Monster::getMonsterCount(){
    return monsterCount;
}

bool Monster::operator==(const Monster& right){
    if (this->getName()==right.getName() && this->getHealth()==right.getHealth()) return true;
    return false;
}
