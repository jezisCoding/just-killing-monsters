#include "creature.h"

Creature::Creature(char mapSign, std::string name, int health, int attack)
    : FieldActor(mapSign)
{
    this->name = name;
    this->health = health;
    this->attack = attack;
}

Creature::Creature(const Creature& orig) : FieldActor(orig)
{
    this->name = orig.name;
    this->health = orig.health;
    this->attack = orig.attack;
}

Creature::~Creature()
{

}

int Creature::interaction(FieldActor *with){    //reworking actor and entity abstract
    return with->reaction(this);
}

int Creature::reaction(FieldActor *to){
    return defendYourselfFrom(to);
}

uint8_t Creature::defendYourselfFrom(FieldActor *who){
    Creature* attacker = static_cast<Creature*>(who);

    attacker->dealDmg(this, attacker->getAttack());
    dealDmg(attacker, getAttack());
    StaticOutputStream::getStream() << std::endl;

    uint8_t outcome = 0;    //bitwise
    if (attacker->getHealth() < 1) outcome |= 1;
    if (this->getHealth() < 1) outcome |= 2;
    return outcome;
}

void Creature::dealDmg(Creature *to, const int& dmgDealt){
    StaticOutputStream::getStream() << this->getName() << " attacks " + to->getName() + "(" << to->getHealth() << "->";
    to->setHealth(to->getHealth() - dmgDealt);
    StaticOutputStream::getStream() << to->getHealth() << ")" << std::endl;
}

void Creature::die()
{
    StaticOutputStream::getStream() << "A creature just died." << std::endl;
}

void Creature::addToXml(QXmlStreamWriter& writer) const
{
    writer.writeStartElement("Creature");

    FieldActor::addAncestryToXml(writer);

    writer.writeTextElement("name", QString(name.c_str()));
    writer.writeTextElement("health", QString(std::to_string(health).c_str()));
    writer.writeTextElement("attack", QString(std::to_string(attack).c_str()));
    writer.writeEndElement();
}

void Creature::addAncestryToXml(QXmlStreamWriter &writer) const
{
    FieldActor::addAncestryToXml(writer);

    writer.writeTextElement("name", QString(name.c_str()));
    writer.writeTextElement("health", QString(std::to_string(health).c_str()));
    writer.writeTextElement("attack", QString(std::to_string(attack).c_str()));
}

std::string Creature::getName() const{
    return name;
}

int Creature::getAttack() const{
    return attack;
}

int Creature::getHealth() const{
    return health;
}

int Creature::getMAX_HEALTH(){
    return MAX_HEALTH;
}

void Creature::setHealth(const int &toValue){
    this->health = toValue;
}

bool Creature::operator== (const Creature& right){
    if (this->getName()==right.getName() && this->getHealth()==right.getHealth()) return true;
    return false;
}
