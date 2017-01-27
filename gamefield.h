#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include "entity.h"
#include "environment.h"
#include "position.h"
#include "hero.h"
#include <memory>

/*!
 * \brief This class describes a single field in the GameBoard class.
 *
 * It is basically a container which describes contents of the single field on the board.
 */
class GameField
{
private:
    typedef std::unique_ptr<Entity> MyEntityPointer;
    typedef std::unique_ptr<Environment> MyEnvironmentPointer;
    MyEntityPointer fieldEntity;
    MyEnvironmentPointer fieldEnvironment;
public:
    GameField(MyEntityPointer fieldEntity, MyEnvironmentPointer fieldEnvironment);
    ~GameField();

    /*!
     * \brief This method returns the character to be printed to output depending
     *      on the state of the GameField.
     * \return string value of the character to be printed
     */
    std::string getPrintSign() const;

    Entity *getFieldEntity() const;
    Environment *getFieldEnvironment() const;
    void setFieldEntity(Entity *toValue);
    void setFieldEnvironment(Environment *toValue);
};

#endif // GAMEFIELD_H
