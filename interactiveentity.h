#ifndef INTERACTIVEENTITY_H
#define INTERACTIVEENTITY_H

#include "entity.h"

class InteractiveEntity : public Entity
{
public:
    InteractiveEntity(std::__cxx11::string mapSign);
    int interaction(InteractiveEntity *with);
};

#endif // INTERACTIVEENTITY_H
