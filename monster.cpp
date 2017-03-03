#include "monster.h"

int Monster::s_monsterCount = 0;

Monster::Monster(char mapSign, std::__cxx11::string name, int health, int attack)
    : Creature(mapSign, name, health, attack)
{
    s_monsterCount++;
}

Monster::Monster(const Monster &orig) : Creature(orig)
{
    s_monsterCount++;

    this->name = orig.getName() + "(split)";
    this->mapSign = 'V';
    this->health = orig.getHealth();
    this->attack = orig.getAttack();
}

Monster::~Monster()
{
    s_monsterCount--;
}

int Monster::getMonsterCount(){
    return s_monsterCount;
}

void Monster::die()
{
    StaticOutputStream::getStream() << name + ": \*dying sounds\*  *pepsi*" << std::endl;
}

void Monster::addToXml(QXmlStreamWriter& writer) const
{
    writer.writeStartElement("Monster");

    Creature::addAncestryToXml(writer);

    writer.writeTextElement("monsterCount", QString(std::to_string(s_monsterCount).c_str()));
    writer.writeEndElement();
}

void Monster::addAncestryToXml(QXmlStreamWriter &writer) const
{
    Creature::addAncestryToXml(writer);

    writer.writeTextElement("monsterCount", QString(std::to_string(s_monsterCount).c_str()));
}

bool Monster::operator==(const Monster& right){
    if (this->getName()==right.getName() && this->getHealth()==right.getHealth()) return true;
    return false;
}
