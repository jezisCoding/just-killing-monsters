#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <iostream>
#include <typeinfo>

#include "position.h"

class Creature;

class Entity
{
protected:
    std::string mapSign;
    Position *position;
public:
    Entity(Position *position, const std::string& mapSign);
    Entity(const Entity& orig);
    virtual ~Entity();

    virtual int reaction(Creature *to) = 0;

    std::string getMapSign() const;
    void setPosition(Position *position);
    Position *getPosition();
    std::string getTypeIdStringPointer();
    std::string getTypeIdStringValue();
};

#endif // ENTITY_H
