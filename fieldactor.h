#ifndef ACTOR_H
#define ACTOR_H

#include "fieldentity.h"

/*! \brief This class declares an interactive BoardEntity, an Actor, it has one simple
 *      abstract method reaction() and it says something on death - die() method
 */
class FieldActor : public FieldEntity
{
public:
    FieldActor(const char& mapSign);
    FieldActor(const FieldActor& orig);

    //! All the actors must be interactive(able to react)
    virtual int reaction(FieldActor *to) = 0;
    virtual void die() = 0;
};

#endif // ACTOR_H
