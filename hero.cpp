#include "hero.h"

Hero::Hero(char mapSign, std::string name, int health, int attack, int readiness, bool surpriseHit,
           Position* pos) : Creature(mapSign, name, health, attack)
{
    this->pos = pos;
    this->readiness = readiness;
    this->surpriseAttack = surpriseHit;
}

Hero::~Hero(){

}

uint8_t Hero::defendYourselfFrom(FieldActor *who){
    Creature* attacker = dynamic_cast<Creature*>(who);

    attacker->dealDmg(this, attacker->getAttack());
    dealDmg(attacker, getAttack());
    StaticOutputStream::getStream() << std::endl;

    uint8_t outcome = 0;    //bitwise
    if (attacker->getHealth() < 1) outcome |= 1;
    if (this->getHealth() < 1) outcome |= 2;
    return outcome;
}

void Hero::dealDmg(Creature *to, const int& dmgDealt){
    surpriseAttack = false;

    StaticOutputStream::getStream() << this->getName() << " attacks " + to->getName() + "(" << to->getHealth() << "->";
    to->setHealth(to->getHealth() - dmgDealt);
    StaticOutputStream::getStream() << to->getHealth() << ")" << std::endl;
}

void Hero::die()
{
    StaticOutputStream::getStream() << name + " is dead, git gud" << std::endl;
}

void Hero::addToXml(QXmlStreamWriter& writer) const
{
    writer.writeStartElement("Hero");

    Creature::addAncestryToXml(writer);

    writer.writeTextElement("readiness", QString(std::to_string(readiness).c_str()));
    writer.writeTextElement("surpriseAttack", QString(std::to_string(surpriseAttack).c_str()));
    writer.writeTextElement("pos", QString(std::to_string(pos->x).c_str()) + "." + QString(std::to_string(pos->y).c_str()));
    writer.writeEndElement();
}

int Hero::getAttack() const{
    if (surpriseAttack) return attack+readiness;
    return attack;
}

void Hero::resetSurpriseHit(){
    surpriseAttack = true;
}

Position *Hero::getPosition()
{
    return pos;
}

void Hero::setPosition(Position *to)
{
    pos = to;
}


