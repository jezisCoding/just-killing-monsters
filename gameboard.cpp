#include "gameboard.h"

GameBoard::GameBoard()
{
    ef = new EntityFactory();
    board.setSizes(SIZE_X, SIZE_Y);

    initializeEnvironment();
    initializeEntitiesRnd();
}

GameBoard::~GameBoard()
{
    board.clear();
}

void GameBoard::initializeEnvironment(){
    Environment *empty;
    Environment *tree;
    Position *pos = new Position;

    for (unsigned int i=0; i<SIZE_X; i++){
        for (unsigned int j=0; j<SIZE_Y; j++){
            *pos = Position::getNewPosition(i, j);
            empty = ef->getNewEnvironment(pos, Environment::Empty);
            board.push_back(new GameField(nullptr, empty));    //its all the same empty instance
        }
    }

    for (unsigned int i=0; i<SIZE_X; i++){
        unsigned int j=0;
        *pos = Position::getNewPosition(i, j);
        tree = ef->getNewEnvironment(pos, Environment::Tree);
        board.at(i, j) = new GameField(nullptr, tree);

        j = SIZE_Y-1;
        *pos = Position::getNewPosition(i, j);
        tree = ef->getNewEnvironment(pos, Environment::Tree);
        board.at(i, j) = new GameField(nullptr, tree);
    }

    for (unsigned int j=1; j<SIZE_Y-1; j++){
        unsigned int i=0;
        *pos = Position::getNewPosition(i, j);
        tree = ef->getNewEnvironment(pos, Environment::Tree);
        board.at(i, j) = new GameField(nullptr, tree);

        i = SIZE_X-1;
        *pos = Position::getNewPosition(i, j);
        tree = ef->getNewEnvironment(pos, Environment::Tree);
        board.at(i, j) = new GameField(nullptr, tree);
    }
}

void GameBoard::initializeEntities(){
    Position *startingPos = new Position(1,1);
    hero = ef->getNewHero(startingPos);
    Monster *monster1 = ef->getNewMonster(new Position(4,4), 0);
    Monster *monster2 = ef->getNewMonster(new Position(3,6), 1);
    Monster *monster3 = ef->getNewMonster(new Position(5,7), 0);
    Potion *potion1 = ef->getNewPotion(new Position(5,5));
    Potion *potion2 = ef->getNewPotion(new Position(6,8));

    setFieldEntityToItsPosition(hero);
    setFieldEntityToItsPosition(monster1);
    setFieldEntityToItsPosition(monster2);
    setFieldEntityToItsPosition(monster3);
    setFieldEntityToItsPosition(potion1);
    setFieldEntityToItsPosition(potion2);
}

void GameBoard::initializeEntitiesRnd()
{
    std::cout << "Randomizing positions... \n\n";

    hero = ef->getNewHero(getNewRandomFreeBoardPosition());
    setFieldEntityToItsPosition(hero);
    Monster *monster1 = ef->getNewMonster(getNewRandomFreeBoardPosition(), 0);
    setFieldEntityToItsPosition(monster1);
    Monster *monster2 = ef->getNewMonster(getNewRandomFreeBoardPosition(), 1);
    setFieldEntityToItsPosition(monster2);
    Monster *monster3 = ef->getNewMonster(getNewRandomFreeBoardPosition(), 0);
    setFieldEntityToItsPosition(monster3);
    Potion *potion1 = ef->getNewPotion(getNewRandomFreeBoardPosition());
    setFieldEntityToItsPosition(potion1);
    Potion *potion2 = ef->getNewPotion(getNewRandomFreeBoardPosition());
    setFieldEntityToItsPosition(potion2);
}

bool GameBoard::monstersDead() const{
    if (Monster::getMonsterCount() == 0) return true;
    return false;
}

void GameBoard::printBoard() const{
    std::cout << std::endl;
    for (unsigned int i=0; i<SIZE_X; i++){
        for (unsigned int j=0; j<SIZE_Y; j++){
            std::cout << std::left << std::setw(2)
                      << board.at(i, j)->getPrintSign();
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool GameBoard::saveBoard() throw(file_error){
    std::ofstream out("map.txt");
    if(out.is_open()){

        //std::for_each(board.begin(), board.end(), [out](GameField const& item){ out << item.getPrintSign(); });
        auto it = board.begin();
        int i = 0;
        while(it!=board.end()){
            out << (*it)->getPrintSign();    //double dereference
            ++it;
            if (i%10 == 9) out << std::endl;
            i++;
        }
        out.close();
        return true;
    } else {
        throw file_error("File is not open");
        return false;
    }
}

void GameBoard::loadBoard() const throw(file_error){
    std::ifstream in("map.txt");
    if(in.is_open()){
        std::cout << std::endl;
        std::string line = "";

        while (std::getline(in, line)) {
            std::cout << std::endl << line;
        }
        std::cout << std::endl;
    } else {
        throw file_error("File is not open");
    }
    in.close();
}

void GameBoard::moveHero(Position *toPos){
    if (freeFieldAt(toPos)){
        setFieldEntityAtPosition(nullptr, hero->getPosition());
        hero->setPosition(toPos);
        setFieldEntityToItsPosition(hero);
        hero->resetSurpriseHit();
    }
}

Hero *GameBoard::getHero() const{
    return hero;
}

GameField *GameBoard::getFieldAt(Position *atPos) const{
    return board.at(atPos);
}

Entity *GameBoard::getEntityAt(Position *atPos) const
{
    return board.at(atPos)->getFieldEntity();
}

Environment::fieldType GameBoard::getEnvTypeAt(Position *atPos) const{
    return board.at(atPos)->getFieldEnvironment()->getType();
}

void GameBoard::setFieldEntityAtPosition(Entity *entity, Position* toPos){
    board.at(toPos)->setFieldEntity(entity);
    if (entity != nullptr) entity->setPosition(toPos);
}

void GameBoard::setFieldEntityToItsPosition(Entity *entity){
    if (entity != nullptr) board.at(entity->getPosition())->setFieldEntity(entity);
    else std::cout << "attempting to set nullptr position"
                      "(GameBoard::setFieldEntityToItsPosition(Entity *entity))" << std::endl;
}

bool GameBoard::entityEmptyPosition(Position *pos) const{
    bool a = getEntityAt(pos) == nullptr;
    return a;
}

bool GameBoard::passableEnvironmentAt(Position *pos) const
{
    bool a = board.at(pos)->getFieldEnvironment()->passableEnvironment();
    return a;
}

bool GameBoard::freeFieldAt(Position *atPos) const
{
    bool a = entityEmptyPosition(atPos) && passableEnvironmentAt(atPos);
    return a;
}

void GameBoard::deleteEntityFromBoard(Entity *entity)
{
    setFieldEntityAtPosition(nullptr, entity->getPosition());

    Creature *creature = dynamic_cast<Creature *>(entity);
    if (creature != nullptr)
        getFieldAt(entity->getPosition())->
                setFieldEnvironment(ef->getNewEnvironment(entity->getPosition(), Environment::Corpse));

    delete entity;
}

void GameBoard::deleteEntityFromBoardAt(Position *atPos){
    Entity *entityAtPos = getFieldAt(atPos)->getFieldEntity();
    setFieldEntityAtPosition(nullptr, atPos);

    Creature *creatureAtPos = dynamic_cast<Creature *>(entityAtPos);
    if (creatureAtPos != nullptr)
        getFieldAt(atPos)->setFieldEnvironment(ef->getNewEnvironment(atPos, Environment::Corpse));

    delete entityAtPos;
}

Position *GameBoard::getNewRandomFreeBoardPosition() const
{
    Position *pos = new Position;
    do {
        *pos = Position::getNewRandomPosition(1, SIZE_X-1, 1, SIZE_Y-1);
    } while (!freeFieldAt(pos));
    return pos;
}


