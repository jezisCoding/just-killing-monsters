#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <iostream>
#include <typeinfo>
#include <memory>

class Creature;

/*!
 * \brief The Entity class
 *      This abstract class describes an entity on the GameBoard(in the GameField)
 */
class FieldEntity
{
protected:
    char mapSign;

    //cant be instantiated
    FieldEntity(const char& mapSign);
    FieldEntity(const FieldEntity& orig);
    virtual ~FieldEntity();

public:
    void setMapSign(const char& to);
    char getMapSign() const;
    std::string getTypeIdStringPointer();
    std::string getTypeIdStringValue();
};

#endif // ENTITY_H
