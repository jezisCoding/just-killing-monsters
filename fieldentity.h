#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <iostream>
#include <typeinfo>
#include <memory>

#include <QString>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QFile>
#include <QMap>
#include <QDebug>

#include <QTextStream>

class Creature;

/*!
 * \brief The Entity class
 *      This abstract class describes an entity on the GameBoard(in the GameField)
 */
class FieldEntity
{
protected:
    char mapSign;

    FieldEntity(const char& mapSign);
    FieldEntity(const FieldEntity& orig);
    virtual ~FieldEntity();

public:
    virtual void addToXml(QFile& where, QXmlStreamWriter& writer) const;

    void setMapSign(const char& to);
    char getMapSign() const;
    std::string getTypeIdStringPointer() const;
    std::string getTypeIdStringValue() const;
};

#endif // ENTITY_H
