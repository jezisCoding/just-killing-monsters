#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "entity.h"
#include "creature.h"

struct Environment : public Entity
{
    enum fieldType {Empty, Rock, Tree, Corpse}; //new type declared
private:
    fieldType type;
public:
    Environment(Position* position, const std::__cxx11::string &mapSign, const fieldType &type);
    ~Environment();

    virtual int reaction(Creature *to);

    fieldType getType() const;
};

#endif // ENVIRONMENT_H
