#ifndef CREATURE_H
#define CREATURE_H

#include "entity.h"
#include "potion.h"
//#include "gameboard.h"

class Creature : public Entity
{
protected:
    std::string name;
    int health;
    int attack;
public:
    Creature(std::string mapSign, std::__cxx11::string name, int health, int attack);
    virtual ~Creature();
    virtual int getAttack();
    int getHealth() const;
    std::string getName() const;
    void setHealth(int toValue);

    int interaction(Entity *with);
    int reaction(Creature &to);
    int defendYourselfFrom(Creature &who);
    bool operator== (const Creature& right);
};

#endif // CREATURE_H
