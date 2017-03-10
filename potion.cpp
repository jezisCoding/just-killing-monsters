#include "potion.h"
#include "creature.h"

Potion::Potion(const char mapSign, const int healthBonus)
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
    sos::iout << "You drank the potion and its gone"
                                    << std::endl << std::endl;
}

void Potion::addToXml(QXmlStreamWriter& writer) const
{
    writer.writeStartElement("Potion");

    FieldActor::addAncestryToXml(writer);

    writer.writeTextElement("healthBonus", QString(std::to_string(healthBonus).c_str()));
    writer.writeEndElement();
}

int Potion::heal(FieldActor* who){
    Creature* user = dynamic_cast<Creature*>(who);

    int userHealth = user->getHealth();
    int userMaxHealth = user->getMAX_HEALTH();

    if (userHealth > userMaxHealth-1) {
        sos::iout << "You don't need this yet, you are on full health" << std::endl;
        return 0;
    }

    sos::iout << user->getName() << " drinks a potion ("
              << userHealth << "->";

    if (userHealth + healthBonus > userMaxHealth){
        int overHeal = (userHealth + healthBonus) % userMaxHealth;
        user->setHealth(userHealth + healthBonus - overHeal);
    } else user->setHealth(userHealth + healthBonus);

    sos::iout << user->getHealth() << ")" << std::endl;
    return 2;
}

int Potion::getHealthBonus(){
    return healthBonus;
}
