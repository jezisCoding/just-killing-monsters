#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include "entity.h"
#include "environment.h"
#include "position.h"
#include "hero.h"

/*!
 * \brief The GameField class
 *      This class describes a single field in the GameBoard class.
 *
 * It is basically a container which describes contents of the single field on the board.
 */
class GameField
{
private:
    Entity *fieldEntity;
    Environment *fieldEnvironment;
public:
    GameField(Entity *fieldEntity, Environment *fieldEnvironment);
    ~GameField();

    /*!
     * \brief getPrintSign
     *      This method returns the character to be printed to output depending
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
