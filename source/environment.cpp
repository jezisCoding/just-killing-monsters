#include "environment.h"

Environment::Environment(const char mapSign, const fieldType type)
    : FieldEntity(mapSign)
{
    this->type = type;
}

Environment::~Environment()
{

}

void Environment::addToXml(QXmlStreamWriter& writer) const
{
    writer.writeStartElement("Environment");

    FieldEntity::addAncestryToXml(writer);

    writer.writeTextElement("type", std::to_string(type).c_str());
    writer.writeEndElement();
}

Environment::fieldType Environment::getType() const{
    return type;
}

bool Environment::passableEnvironment() const
{
    return type == Empty;
}
