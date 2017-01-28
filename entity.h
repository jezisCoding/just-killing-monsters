#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <iostream>
#include <typeinfo>

#include "position.h"

class Creature;

/*!
 * \brief The Entity class
 *      This abstract class describes an entity on the GameBoard
 */
class Entity
{
protected:
    std::string mapSign;
    Position *position;
public:
    Entity(Position *position, const std::string& mapSign);
    Entity(const Entity& orig);
    virtual ~Entity();

    //! All the entities must be interactive(able to react)
    virtual int reaction(Creature *to) = 0;

    void setMapSign(std::string to);
    std::string getMapSign() const;
    void setPosition(Position *position);
    Position *getPosition();
    std::string getTypeIdStringPointer();
    std::string getTypeIdStringValue();
};

#endif // ENTITY_H
