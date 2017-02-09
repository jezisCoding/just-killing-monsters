#include "monster.h"

int Monster::monsterCount = 0;

Monster::Monster(char mapSign, std::__cxx11::string name, int health, int attack)
    : Creature(mapSign, name, health, attack)
{
    monsterCount++;
}

Monster::Monster(const Monster &orig) : Creature(orig)
{
    monsterCount++;

    this->name = orig.getName() + "(split)";
    this->mapSign = 'V';
    this->health = orig.getHealth();
    this->attack = orig.getAttack();
}

Monster::~Monster()
{
    monsterCount--;
}

int Monster::getMonsterCount(){
    return monsterCount;
}

void Monster::die()
{
    StaticOutputStream::getStream() << name + ": \"Bleeurhgdjksfgdak......h.\"  *pepsi*" << std::endl;
}

bool Monster::operator==(const Monster& right){
    if (this->getName()==right.getName() && this->getHealth()==right.getHealth()) return true;
    return false;
}
