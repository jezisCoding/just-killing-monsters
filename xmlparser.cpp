#include "xmlparser.h"

XMLParser::XMLParser(EntityFactory *ef, My2DBoardVector<GameField*> *board, Hero *hero)
{
    this->ef = ef;
    this->board = board;
    this->hero = hero;
}

Hero *XMLParser::loadFrom(const QString &fileName) throw(file_error)
{
    QFile file(fileName);
    QXmlStreamReader reader;
    reader.setDevice(&file);

    if(file.open(QIODevice::ReadOnly)){
        StaticOutputStream::getStream() << "Loading Game..." << std::endl;

        while(reader.readNext() != reader.EndDocument)
            if(reader.isStartElement())
                if(reader.name() == "GameField")
                    readField(reader);

        file.close();
        return hero;
    } else {
        throw file_error("File was not opened(loadBoardXml()");
    }
    return nullptr; //this should never happen
}

bool XMLParser::saveTo(const QString &fileName) throw(file_error)
{
    QFile file(fileName);
    QXmlStreamWriter writer;
    writer.setDevice(&file);

    if(file.open(QIODevice::WriteOnly)){
        writer.writeStartDocument();
        writer.writeStartElement("GameBoard");

        writeFields(writer);

        writer.writeEndElement();
        writer.writeEndDocument();

        file.close();
        return true;
    } else {
        throw file_error("File was not opened(saveBoardXml())");
    }
    return false;
}

void XMLParser::writeFields(QXmlStreamWriter &writer)
{
    int i = 0;

    for(GameField* field : *board){
        writer.writeStartElement("GameField");
        writer.writeAttribute("index", std::to_string(i).c_str());

        writer.writeStartElement("fieldEnvironment");
        field->getFieldEnvironment()->addToXml(writer);
        writer.writeEndElement();

        if(field->getFieldActor() != nullptr){
            writer.writeStartElement("fieldActor");
            field->getFieldActor()->addToXml(writer);
            writer.writeEndElement();
        }

        writer.writeEndElement();
        i++;
    }
}

void XMLParser::readField(QXmlStreamReader &reader)
{
    GameField* newField;
    MyQMap envElement;

    reader.readNext(), reader.readNext();    //there is always an Environment at the start -> skip skip

    reader.readNext();
    envElement.insert(reader.name(), reader.readElementText());

    reader.readNext();
    envElement.insert(reader.name(), reader.readElementText());

    reader.readNext(), reader.readNext();

    newField = new GameField(new Environment(envElement.value("mapSign").at(0),
                                             (Environment::fieldType)std::stoi(envElement.value("type"))));

    reader.readNext();

    if (reader.name() == "fieldActor"){    //if it has an Actor
        readActor(reader, newField);
            //Actor ending
    } else newField->setFieldActor(nullptr);

    board->push_back(newField);
}

void XMLParser::readActor(QXmlStreamReader &reader, GameField *nf)
{
    MyQMap actorElement;

    reader.readNext();
    actorElement.insert("class", reader.name().toString());
    while (reader.readNext() != reader.EndElement) {
        actorElement.insert(reader.name(), reader.readElementText());
    }

    if(actorElement.value("class") == "Hero"){


        std::string before = actorElement.value("pos");
        std::vector<std::string> after;
        boost::split(after, before, boost::is_any_of("\t. "));

        Hero* newActor;
        newActor = ef->createNewHero(actorElement.value("mapSign").at(0),
                                     actorElement.value("name"),
                                     std::stoi(actorElement.value("health")),
                                     std::stoi(actorElement.value("attack")),
                                     std::stoi(actorElement.value("readiness")),
                                     (bool)actorElement.value("surpriseAttack").at(0),
                                     new Position(std::stoi(after.at(0)),
                                                  std::stoi(after.at(1)))
                                     );
        nf->setFieldActor(newActor);
        hero = newActor;

    } else if(actorElement.value("class") == "Monster"){
        Monster* newActor;
        newActor = ef->createNewMonster(actorElement.value("mapSign").at(0),
                                        actorElement.value("name"),
                                        std::stoi(actorElement.value("health")),
                                        std::stoi(actorElement.value("attack"))
                                        );
        nf->setFieldActor(newActor);

    } else if(actorElement.value("class") == "MonsterFearsome"){
        MonsterFearsome* newActor;
        newActor = ef->createNewMonsterF(actorElement.value("mapSign").at(0),
                                         actorElement.value("name"),
                                         std::stoi(actorElement.value("health")),
                                         std::stoi(actorElement.value("attack")),
                                         std::stof(actorElement.value("fearsomeness"))
                                         );
        nf->setFieldActor(newActor);

    } else if(actorElement.value("class") == "Potion"){
        Potion* newActor;
        newActor = ef->createNewPotion(actorElement.value("mapSign").at(0),
                                       std::stoi(actorElement.value("healthBonus"))
                                       );
        nf->setFieldActor(newActor);
    }

    reader.readNext();
    reader.readNext();
}

void XMLParser::heroDied()
{
    hero = nullptr;
}
