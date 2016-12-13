#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <iostream>
#include <typeinfo>

class Creature;

class Entity
{
protected:
    std::string mapSign;
public:
    Entity(std::string mapSign);
    virtual ~Entity();
    std::string getMapSign() const;
    virtual int reaction(Creature &to); //=0?
    virtual std::string getPointerTypeIdString(); //skusit odvirtualizovat
    virtual std::string getValueTypeIdString();
};

#endif // ENTITY_H
