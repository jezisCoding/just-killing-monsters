#include "gameboard.h"

GameBoard::GameBoard()
{
    Environment *empty = new Environment(Environment::Empty, ".");
    Environment *tree = new Environment(Environment::Tree, "T");
    Position *pos;

    for (int i=0; i<10; i++){
        std::vector<GameField *> row;
        for (int j=0; j<10; j++){
            pos = new Position(i,j);
            row.push_back(new GameField(nullptr, empty, pos));
        }
        board.push_back(row);
    }

    for (int i=0; i<10; i++){
        int j=0;
        pos = new Position(i,j);
        board.at(i).at(j)= new GameField(nullptr, tree, pos);

        j=9;
        pos = new Position(i,j);
        board.at(i).at(j)= new GameField(nullptr, tree, pos);
    }

    for (int j=1; j<9; j++){
        int i=0;
        pos = new Position(i,j);
        board.at(i).at(j)= new GameField(nullptr, tree, pos);

        i=9;
        pos = new Position(i,j);
        board.at(i).at(j)= new GameField(nullptr, tree, pos);
    }

    Position *heroPos = new Position(1,1);
    hero = new Hero(10, true, heroPos, 100, 15, "H");
    InteractiveEntity *potion = new Potion(50, "L");
    setFieldEntityAt(heroPos, hero);
    setFieldEntityAt(new Position(5,5), potion);
}

Hero *GameBoard::getHero(){
    return hero;
}

GameField *GameBoard::getFieldAt(Position *atPos){
    return board.at(atPos->x).at(atPos->y);
}

Environment::fieldType GameBoard::getEnvTypeAt(Position *atPos){
    return board.at(atPos->x).at(atPos->y)->getFieldEnvironment()->getType();
}

void GameBoard::setFieldEntityAt(Position *atPos, InteractiveEntity *toEntity){
    board.at(atPos->x).at(atPos->y)->setFieldEntity(toEntity);
}

void GameBoard::moveHero(Position *toPos){
    board.at(hero->getPosition()->x).at(hero->getPosition()->y)->setFieldEntity(nullptr);
    board.at(toPos->x).at(toPos->y)->setFieldEntity(hero);
    hero->setPosition(toPos);
}

void GameBoard::printBoard(){
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            std::cout << std::left << std::setw(2) <<
                board.at(i).at(j)->getPrintSign();
        }
        std::cout << std::endl;
    }
}

void GameBoard::deleteEntity(InteractiveEntity *entity){ //delete entity at?

}

void GameBoard::deleteEntityAt(Position *atPos){
    delete board.at(atPos->x).at(atPos->y);
}

void GameBoard::interactHeroWith(InteractiveEntity *with){

}
