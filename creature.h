#ifndef CREATURE_H
#define CREATURE_H

#include "entity.h"
#include "potion.h"

#include <cstdint>

class Creature : public Entity
{
protected:
    std::string name;
    int health;
    int attack;
    static const int MAX_HEALTH = 100;

public:
    Creature(Position* position, std::string mapSign, std::__cxx11::string name, int health, int attack);
    Creature(const Creature& orig);
    virtual ~Creature();

    int interaction(Entity *with);

protected:
    int reaction(Creature *to);
    virtual uint8_t defendYourselfFrom(Creature *who);

public:
    virtual void dealDmg(Creature *to, const int& dmgDealt);

    std::string getName() const;
    virtual int getAttack() const;
    int getHealth() const;
    static int getMAX_HEALTH();
    void setHealth(const int& toValue);

    bool operator== (const Creature& right);
};

#endif // CREATURE_H
