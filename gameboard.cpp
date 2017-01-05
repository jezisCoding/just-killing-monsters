#include "gameboard.h"

//for implementation of monstersDead with vector
//Monster* GameBoard::left = nullptr;

GameBoard::GameBoard(EntityFactory *ef)
{
    this->ef = ef;
    initializeEnvironment();
    initializeEntities();
}

GameBoard::~GameBoard()
{
    board.clear();
}

void GameBoard::initializeEnvironment(){
    EntityFactory ef;
    Environment *empty;
    Environment *tree;
    Position *pos;

    for (unsigned int i=0; i<board.getSizeX(); i++){
        for (unsigned int j=0; j<board.getSizeY(); j++){
            pos = new Position(i,j);
            empty = ef.getNewEnvironment(pos, Environment::Empty);
            board.push_back(new GameField(nullptr, empty, pos));    //its all the same empty instance
        }
    }

    for (unsigned int i=0; i<board.getSizeX(); i++){
        unsigned int j=0;
        pos = new Position(i,j);
        tree = ef.getNewEnvironment(pos, Environment::Tree);
        board.at(i, j) = new GameField(nullptr, tree, pos);

        j=board.getSizeY()-1;
        pos = new Position(i,j);
        tree = ef.getNewEnvironment(pos, Environment::Tree);
        board.at(i, j) = new GameField(nullptr, tree, pos);
    }

    for (unsigned int j=1; j<board.getSizeY()-1; j++){
        unsigned int i=0;
        pos = new Position(i,j);
        tree = ef.getNewEnvironment(pos, Environment::Tree);
        board.at(i, j) = new GameField(nullptr, tree, pos);

        i=board.getSizeX()-1;
        pos = new Position(i,j);
        tree = ef.getNewEnvironment(pos, Environment::Tree);
        board.at(i, j) = new GameField(nullptr, tree, pos);
    }
}

//old initialize environment
/*
void GameBoard::initializeEnvironment(){
    EntityFactory ef;
    Environment *empty = ef.getNewEnvironment(Environment::Empty);
    Environment *tree = ef.getNewEnvironment(Environment::Tree);
    Position *pos;

    for (unsigned int i=0; i<board.getSizeX(); i++){
        for (unsigned int j=0; j<board.getSizeY(); j++){
            pos = new Position(i,j);
            board.push_back(new GameField(nullptr, empty, pos));    //its all the same empty instance
        }
    }

    for (unsigned int i=0; i<board.getSizeX(); i++){
        unsigned int j=0;
        pos = new Position(i,j);
        board.at(i, j) = new GameField(nullptr, tree, pos);

        j=board.getSizeY()-1;
        pos = new Position(i,j);
        board.at(i, j) = new GameField(nullptr, tree, pos);
    }

    for (unsigned int j=1; j<board.getSizeY()-1; j++){
        unsigned int i=0;
        pos = new Position(i,j);
        board.at(i, j) = new GameField(nullptr, tree, pos);

        i=board.getSizeX()-1;
        pos = new Position(i,j);
        board.at(i, j) = new GameField(nullptr, tree, pos);
    }
}
*/

void GameBoard::initializeEntities(){
    hero = ef->getNewHero(new Position(1,1));
    Monster *monster1 = ef->getNewMonster(new Position(4,4), 0);
    Monster *monster2 = ef->getNewMonster(new Position(3,6), 1);
    Monster *monster3 = ef->getNewMonster(new Position(5,7), 0);
    Potion *potion1 = ef->getNewPotion(new Position(5,5));
    Potion *potion2 = ef->getNewPotion(new Position(6,8));

    setFieldEntityTo(hero);
    setFieldEntityTo(monster1);
    setFieldEntityTo(monster2);
    setFieldEntityTo(monster3);
    setFieldEntityTo(potion1);
    setFieldEntityTo(potion2);
}

void GameBoard::deleteEntityAt(Position *atPos){

    Entity *entityAtPos = getFieldAt(atPos)->getFieldEntity();
    setFieldEntityAt(atPos, nullptr);

    Creature *creatureAtPos = dynamic_cast<Creature *>(entityAtPos);
    if (creatureAtPos != nullptr)
        getFieldAt(atPos)->setFieldEnvironment(ef->getNewEnvironment(atPos, Environment::Corpse));

    delete entityAtPos;
}

bool GameBoard::monstersDead() const{
    if (Monster::getMonsterCount() == 0) return true;
    return false;
}

            //for (string &s : stringVec) cout << s << " ";
            //vector<>::size_type; !=.size()
void GameBoard::printBoard() const{
    std::cout << std::endl;
    for (auto i=0; i<10; i++){
        for (unsigned int j=0; j<10; j++){
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

Hero *GameBoard::getHero() const{
    return hero;
}

void GameBoard::moveHero(Position *toPos){
    setFieldEntityAt(hero->getPosition(), nullptr);
    hero->setPosition(toPos);
    setFieldEntityTo(hero);
    hero->resetSurpriseHit();
}

GameField *GameBoard::getFieldAt(Position *atPos) const{
    return board.at(atPos->x, atPos->y);
}

Environment::fieldType GameBoard::getEnvTypeAt(Position *atPos){
    return board.at(atPos->x, atPos->y)->getFieldEnvironment()->getType();
}

void GameBoard::setFieldEntityTo(Entity *toEntity){
    board.at(toEntity->getPosition()->x, toEntity->getPosition()->y)->setFieldEntity(toEntity);
}

void GameBoard::setFieldEntityAt(Position* at, Entity *toEntity){
    board.at(at->x, at->y)->setFieldEntity(toEntity);
}

