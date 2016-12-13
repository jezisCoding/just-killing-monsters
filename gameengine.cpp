#include "gameengine.h"

GameEngine::GameEngine()
{
    gameBoard = new GameBoard();
    hero = gameBoard->getHero();
}

GameEngine::~GameEngine(){
    delete gameBoard;
}

void GameEngine::play(){
    char input = 'Q';
    welcome();

    while (!endGame(input)) {
        input = getKeyboardInput();
        if (input == 'Q') welcome();
        else {
            heroAction(input);
            gameBoard->printBoard();
        }
    }
}

bool GameEngine::heroAction(char direction){
    Position *targetPosition = createTargetPosition(direction);
    Entity *targetFieldEntity = gameBoard->getFieldAt(targetPosition)->getFieldEntity();

    if (targetFieldEntity != nullptr) {
        int outcome = hero->interaction(targetFieldEntity);

        switch (outcome) {
        case 0:  //both survived
            break;
        case 1:  //hero died
            gameBoard->deleteEntityAt(hero->getPosition());
            hero = nullptr;
            return false;
            break;
        case 2:  //opponent died
            gameBoard->deleteEntityAt(targetPosition);
            break;
        case 3:  //both died
            gameBoard->deleteEntityAt(hero->getPosition());
            gameBoard->deleteEntityAt(targetPosition);
            hero = nullptr;
            return false;
            break;
        default:
            break;
        }
        return true;

    } else {
        if (gameBoard->getEnvTypeAt(targetPosition) == Environment::Empty){
            gameBoard->moveHero(targetPosition);
        } else std::cout << "You can't move into a tree" <<std::endl;
    }
    return true;
}

void GameEngine::welcome(){
    std::cout << "Welcome to the game of Just Killing Monsters \n"
              << "Kill the monsters by running into them: WSAD to move, Q for this Intro, X to exit\n"
              << "When you move between your hits, you get Surprise strike bonus damage on hit\n"
              << "Legend: [H]-Hero, [P]-Health Potion, [M,N,...]-Monsters, [T]-Tree\n";
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
        std::cout << "Invalid input." << std::endl;
        std::cout << "Stop hitting yourself!" << std::endl;
        break;
    }
    return targetPos;
}

bool GameEngine::endGame(char input) const{

    if (input == 'X') return true;
    else if (hero == nullptr && gameBoard->monstersDead()){
        std::cout << "After an epic battle with the last of the monsters... You died.\n"
                     "But you did kill them all and the goal of the game wasnt to survive so "
                     "technically you win"
                  << std::endl << std::endl
                  << "Game over" << std::endl;
        return true;
    }
    else if (hero == nullptr) {
        std::cout << "Did you actually manage to loose this game? uninstall pls"
                  << std::endl << std::endl
                  << "Game over" << std::endl;
        return true;
    }
    else if (gameBoard->monstersDead()){
        std::cout << "You've killed all the monsters and saved the village from certain doom! GG"
                  << std::endl << std::endl
                  << "Game over" << std::endl;
        return true;
    }
    return false;
}

/* This method returns input from keyboard converted to Upcase
 */
char GameEngine::getKeyboardInput() const{
    std::cout << "Hero's action: ";
    char input;
    std::cin >> input;
    return toupper(input);
}
