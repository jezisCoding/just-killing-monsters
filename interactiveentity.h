#ifndef INTERACTIVEENTITY_H
#define INTERACTIVEENTITY_H

#include "entity.h"

class InteractiveEntity : public Entity
{
public:
    InteractiveEntity(std::__cxx11::string mapSign);
    virtual int interaction(InteractiveEntity *with);
    //virtual int interaction(Creature *with);
};

#endif // INTERACTIVEENTITY_H
