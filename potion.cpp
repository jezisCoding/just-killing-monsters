#include "potion.h"
#include "creature.h"

Potion::Potion(char mapSign, int healthBonus)
    : FieldActor(mapSign)
{
    this->healthBonus = healthBonus;
}

Potion::~Potion()
{

}

int Potion::reaction(FieldActor *to){
    return heal(to);
}

void Potion::die()
{
    StaticOutputStream::getStream() << "You drank the potion and its gone" << std::endl;
}

void Potion::addToXml(QFile& where, QXmlStreamWriter& writer) const
{
    writer.writeStartElement("Potion");
    writer.writeTextElement("healthBonus", QString(healthBonus));
    writer.writeEndElement();

    FieldActor::addToXml(where, writer);
}

int Potion::heal(FieldActor* who){
    Creature* user = dynamic_cast<Creature*>(who);

    int userHealth = user->getHealth();
    int userMaxHealth = user->getMAX_HEALTH();

    if (userHealth > userMaxHealth-1) {
        StaticOutputStream::getStream() << "You don't need this yet, you are on full health" << std::endl;
        return 0;
    }

    StaticOutputStream::getStream() << user->getName() << " drinks a potion ("
              << userHealth << "->";

    if (userHealth + healthBonus > userMaxHealth){
        int overHeal = (userHealth + healthBonus) % userMaxHealth;
        user->setHealth(userHealth + healthBonus - overHeal);
    } else user->setHealth(userHealth + healthBonus);

    StaticOutputStream::getStream() << user->getHealth() << ")" << std::endl;
    return 2;
}

int Potion::getHealthBonus(){
    return healthBonus;
}
