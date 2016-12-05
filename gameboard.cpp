#include "gameboard.h"

GameBoard::GameBoard()
{
    Environment *empty = new Environment(".", Environment::Empty);
    Environment *tree = new Environment("T", Environment::Tree);
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
    hero = new Hero("H", 100, 20, 15, true, heroPos);
    Potion *potion = new Potion("P", 50);
    Monster*monster1 = new Monster("M", 100, 20, 5);
    //what if Monster *monster1

    setFieldEntityAt(heroPos, hero);
    setFieldEntityAt(new Position(5,5), potion);
    setFieldEntityAt(new Position(4,4), monster1);
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
                              //for (string &s : stringVec) cout << s << " ";
void GameBoard::printBoard(){ //vector<>::size_type; !=.size()
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            std::cout << std::left << std::setw(2) <<
                board.at(i).at(j)->getPrintSign();
        }
        std::cout << std::endl;
    }
}

void GameBoard::deleteEntityAt(Position *atPos){
    delete board.at(atPos->x).at(atPos->y);
}

void GameBoard::interactHeroWith(InteractiveEntity *with){
    /*
    int sCim;
    int vysledok = koho->interakcia(sCim);
    if (vysledok == 0) {
        std::cout << "returned 0" << std::endl;
    } else if (vysledok == 1) {
        plocha.at(koho->getPozicia()->x).at(koho->getPozicia()->y) = nullptr;
        delete koho;
    } else if (vysledok == 2) {
        plocha.at(sCim->getPozicia()->x).at(sCim->getPozicia()->y) = nullptr;
        delete sCim;
    } else if (vysledok == 3) {
        plocha.at(sCim->getPozicia()->x).at(sCim->getPozicia()->y) = nullptr;
        delete sCim;
        plocha.at(koho->getPozicia()->x).at(koho->getPozicia()->y) = nullptr;
        delete koho;
    } else {
        std::cout << "??? returned -1" << std::endl;
    }*/
}
