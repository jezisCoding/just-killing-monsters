#include "gameengine.h"

GameEngine::GameEngine()
{
    gameBoard = new GameBoard();
    hero = gameBoard->getHero();
}

void GameEngine::play(){
    welcome();
    std::cout << "Ovladanie: WASD-pohyb" << std::endl;
    char input;
    std::cin >> input;
    input = toupper(input);

    while (input != 'X') {
        heroAction(input);
        gameBoard->printBoard();
        std::cin >> input;
        input = toupper(input);
    }

    std::cout << "Koniec hry" << std::endl;
}

void GameEngine::heroAction(char direction){
    Position *targetPosition = createTargetPosition(direction);
    InteractiveEntity *targetFieldEntity = gameBoard->getFieldAt(targetPosition)->getFieldEntity();

    if (targetFieldEntity != nullptr) {
            /*
             * 1. vypije lektvar - lektvar vymazat, healnut, vypisat nieco
             * 2. pohne sa tam - zmenit poziciu, obsah pola
             */
        gameBoard->interactHeroWith(targetFieldEntity);
        hero->interaction(targetFieldEntity);

    } else {
        if (gameBoard->getEnvTypeAt(targetPosition) == Environment::Empty){
            std::cout << "setujem hera" <<std::endl;
            gameBoard->moveHero(targetPosition);
        }
    }
}

void GameEngine::welcome(){
    std::cout << "welcome method" << std::endl;
    gameBoard->printBoard();
}

Position *GameEngine::createTargetPosition(char direction){
    Position *targetPos = hero->getPosition();
    switch (direction) {
    case 'W':
        targetPos = new Position(hero->getPosition()->x-1, hero->getPosition()->y);
        break;
    case 'S':
        targetPos = new Position(hero->getPosition()->x+1, hero->getPosition()->y);
        break;
    case 'A':
        targetPos = new Position(hero->getPosition()->x, hero->getPosition()->y-1);
        break;
    case 'D':
        targetPos = new Position(hero->getPosition()->x, hero->getPosition()->y+1);
        break;
    default:
        std::cout << "Invalid." << std::endl;
        break;
    }
    return targetPos;
}










