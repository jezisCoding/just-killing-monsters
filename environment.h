#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "entity.h"
#include "creature.h"

/*!
 * \brief The Environment struct
 *      This struct describes the type of environment in a GameField
 */

struct Environment : public Entity
{
    //!
    //! \brief The fieldType enum
    //!     A type defining types of Environment, used for checking if it's accessible.
    //!
    enum fieldType {Empty, Rock, Tree, Corpse};
private:
    fieldType type;
public:
    Environment(Position* position, const std::__cxx11::string &mapSign, const fieldType &type);
    ~Environment();

    /*!
     * \brief reaction
     *      Environment's reaction is not yet defined(or needed)
     * \param to
     * \return
     */
    virtual int reaction(Creature *to);

    /*!
     * \brief getType
     *      Returns the type of environment.
     * \return
     */
    fieldType getType() const;
    bool passableEnvironment() const;
};

#endif // ENVIRONMENT_H
