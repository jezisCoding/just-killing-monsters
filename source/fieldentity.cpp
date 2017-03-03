#include "fieldentity.h"
//#include "creature.h"

FieldEntity::FieldEntity(const char mapSign)
{
    this->mapSign = mapSign;
}

FieldEntity::FieldEntity(const FieldEntity& orig)
{
    this->mapSign = orig.mapSign;
}

FieldEntity::~FieldEntity()
{
    //StaticOutputStream::getStream() << "An entity was just destroyed." << std::endl;
}

void FieldEntity::addToXml(QXmlStreamWriter& writer) const
{
    writer.writeStartElement("FieldEntity");
    writer.writeTextElement("mapSign", QString(mapSign));
    writer.writeEndElement();
}

void FieldEntity::addAncestryToXml(QXmlStreamWriter &writer) const
{
    writer.writeTextElement("mapSign", QString(mapSign));
}

void FieldEntity::setMapSign(const char &to)
{
    mapSign = to;
}

char FieldEntity::getMapSign() const
{
    return mapSign;
}

std::string FieldEntity::getTypeIdStringPointer() const {
    return typeid(this).name();
}

std::string FieldEntity::getTypeIdStringValue() const {
    return typeid(*this).name();
}
