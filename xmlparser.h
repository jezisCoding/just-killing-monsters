#ifndef MYXMLPARSER_H
#define MYXMLPARSER_H

#include "entityfactory.h"
#include "gamefield.h"
#include "potion.h"
#include "monster.h"
#include "environment.h"
#include "my2dboardvector.h"
#include "entityfactory.h"
#include "myexceptions.h"
#include "myqmap.h"

#include "boost/algorithm/string.hpp"

class XMLParser
{
    EntityFactory* ef;
    My2DBoardVector<GameField*> *board;
    Hero* hero;

public:
    XMLParser(EntityFactory* ef, My2DBoardVector<GameField*> *board, Hero* hero);

    Hero* loadFrom(const QString &fileName) throw(file_error);
    bool saveTo(const QString &fileName) throw(file_error);

    void heroDied();

private:
    void writeFields(QXmlStreamWriter &writer);
    void readActor(QXmlStreamReader &reader, GameField* nf);
    void readField(QXmlStreamReader &reader);
};

#endif // MYXMLPARSER_H
