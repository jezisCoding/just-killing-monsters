#ifndef CREATURE_H
#define CREATURE_H

#include "entity.h"
#include "potion.h"

class Creature : public Entity
{
protected:
    std::string name;
    int health;
    int attack;
    static const int MAX_HEALTH = 100;
public:
    Creature(Position* position, std::string mapSign, std::__cxx11::string name, int health, int attack);
    virtual ~Creature();

    virtual int getAttack();
    virtual int reaction(Creature &to);
    int interaction(Entity *with);
    int defendYourselfFrom(Creature &who);

    int getHealth() const;
    void setHealth(const int& toValue);
    std::string getName() const;
    static int getMAX_HEALTH();

    bool operator== (const Creature& right);
};

#endif // CREATURE_H
