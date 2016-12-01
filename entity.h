#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <iostream>
#include <typeinfo>

class Entity
{
protected:
    std::string mapSign;
public:
    Entity(std::string mapSign);
    ~Entity();
    std::string getMapSign() const;
    /*virtual void printTypeId();
    virtual std::string getTypeId();    vraca mi typ Entita aj ked volam z potomka, pozri do ZOOcka?*/
};

#endif // ENTITY_H
