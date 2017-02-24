#include "monsterfearsome.h"

MonsterFearsome::MonsterFearsome(char mapSign, std::string name,
                                 int health, int attack, float fearsomeness)
    : Monster(mapSign, name, health, attack)
{
    this->fearsomeness = fearsomeness;
}

MonsterFearsome::MonsterFearsome(MonsterFearsome& orig) : Monster(orig)
{
    orig.setMapSign('V');

    this->mapSign = 'V';
    this->name = orig.getName() + "(split)";
    this->health = orig.getHealth();
    this->attack = orig.getAttack()/2;
    this->fearsomeness = orig.getFearsomeness();
}

MonsterFearsome::~MonsterFearsome()
{

}

uint8_t MonsterFearsome::defendYourselfFrom(FieldActor *who) {
    Creature* attacker = dynamic_cast<Creature*>(who);

    attacker->dealDmg(this, attacker->getAttack());
    dealDmg(attacker, getAttack());
    StaticOutputStream::getStream() << std::endl;

    uint8_t outcome = 0;    //bitwise
    if (attacker->getHealth() < 1) outcome |= 1;
    if (this->getHealth() < 1) outcome |= 2;
    if (monsterSplit()) outcome |= 4;

    return outcome;
}

void MonsterFearsome::addToXml(QFile& where, QXmlStreamWriter& writer) const
{
    writer.writeStartElement("MonsterFearsome");
    writer.writeTextElement("fearsomeness", QString(std::to_string(fearsomeness).c_str()));
    writer.writeEndElement();

    Monster::addToXml(where, writer);
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
