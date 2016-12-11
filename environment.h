#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "entity.h"

struct Environment : public Entity
{
    enum fieldType {Empty, Rock, Tree, Corpse}; //new type declared
private:
    fieldType type;
public:
    Environment(std::string mapSign, fieldType type);
    fieldType getType();
};

#endif // ENVIRONMENT_H
