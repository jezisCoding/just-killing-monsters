#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "entity.h"
#include "creature.h"

/*!
 * \brief This structure describes the type of environment in a GameField
 */

struct Environment : public Entity
{
    //!
    //! \brief A type defining types of Environment, used for checking if it's accessible.
    //!
    enum fieldType {UNDEFINED, Empty, Rock, Tree, Corpse};
private:
    fieldType type;
public:
    Environment();
    Environment(Position* position, const std::__cxx11::string &mapSign, const fieldType &type);
    ~Environment();

    /*!
     * \brief Environment's reaction is not yet defined(or needed).
     * \param Creature reacted to.
     * \return Outcome of the reaction.
     */
    virtual int reaction(Creature *to);

    /*!
     * \brief Basic getter function.
     * \return fieldType of the object.
     */
    fieldType getType() const;
    bool passableEnvironment() const;
};

#endif // ENVIRONMENT_H
