#include "gameengine.h"

GameEngine::GameEngine()
{
    gameBoard = new GameBoard();
    hero = gameBoard->getHero();
}

GameEngine::~GameEngine()
{
    delete gameBoard;
}

void GameEngine::play(){
    bool gameOver = false;
    char input = '\0';
    welcome();
    do {
        try{
            do {
                input = getKeyboardInput();

                switch (input) {
                case 'Q':
                    welcome();
                    break;
                case 'E':
                    saveGame();
                    break;
                case 'R':
                    loadGame();
                    break;
                case 'X':
                    //just let it fall
                    break;
                default:
                    heroTurn(input);
                    gameBoard->printBoard();
                }

            } while (!(gameOver = endGame(input)));
        } catch (std::exception& ex){
            std::cerr << "Exception in GameEngine::play() : "
                      << ex.what() << std::endl;
        }
    } while (!gameOver);
}

void GameEngine::welcome() const{
    std::cout << "Welcome to the game of Just Killing Monsters\n"
              << "Kill the monsters by running into them.\n\n"

              << "Controls:"
              << "WSAD to move, Q for this Intro, X to exit, E to save game, R to load game,\n"
              << "ENTER to confirm\n\n"

              << "When you move between your hits, you get Surprise strike bonus damage on hit\n"
              << "Legend: [H]-Hero, [P]-Health Potion, [M,W,V]-Monsters, [T]-Tree\n";
    gameBoard->printBoard();
}

void GameEngine::heroTurn(const char& direction){
    Position *targetPosition = new Position();
    *targetPosition = Position::getNewPositionInDirection(hero->getPosition(), direction);
    FieldActor *targetFieldActor = gameBoard->getFieldAt(targetPosition)->getFieldActor();

    if (targetFieldActor  != nullptr) heroAction(targetFieldActor , targetPosition);
    else gameBoard->moveHero(targetPosition);
}

void GameEngine::heroAction(FieldActor* targetFieldActor, Position* targetPosition){
    uint8_t outcome = hero->interaction(targetFieldActor);


        //opponent(defender) died
    if((outcome & 2) == 2) {
        gameBoard->killActorAt(targetPosition);
        targetFieldActor = nullptr;
    }
        //monster split
    if((outcome & 4) == 4)splitMonsterAround(targetFieldActor, hero->getPosition());

        //hero(attacker) died
    if((outcome & 1) == 1) {
        gameBoard->killActorAt(hero->getPosition());
        hero = nullptr;
    }
}

/**
 * This method returns input from keyboard converted to Upcase
 */
char GameEngine::getKeyboardInput() const throw(invalid_input){
    std::cout << "Hero's action: ";
    char input;
    std::cin >> input;
    std::cout << std::endl;
    if (!isalpha((int)input)) throw (invalid_input("Use only letters for controlling"));
    return toupper(input);
}

void GameEngine::saveGame() const throw(file_error){
    try{
        if(gameBoard->saveBoard()) std::cout << "Game saved." << std::endl;
    } catch (file_error& ex){
        throw ex;
    }
}

void GameEngine::loadGame() throw(file_error){
    try{
        gameBoard->loadBoard();
    } catch (file_error& ex){
        throw ex;
    }
}

bool GameEngine::endGame(const char &input) const{

    if (input == 'X'){
        std::cout << "Game over" << std::endl;
        return true;
    }
    else if (hero == nullptr && gameBoard->monstersDead()){
        std::cout << "After an epic battle with the last of the monsters... You died.\n"
                     "But you did kill them all and the goal of the game was not to survive so "
                     "technically you still won."
                  << std::endl << std::endl
                  << "Game over" << std::endl;
        return true;
    }
    else if (hero == nullptr) {
        std::cout << "You ded"
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

void GameEngine::splitMonsterAround(FieldActor* monster, Position* centerPos){
    if (monster != nullptr){
        MonsterFearsome* mf = dynamic_cast<MonsterFearsome*>(monster);

        if (mf == nullptr) std::cout << "monstersplit cast error" << std::endl;
        else {
            int direction = Position::Up;
            Position* splitPos = new Position;

            do {
                *splitPos = Position::getNewPositionInDirection(centerPos, (Position::direction)direction);
                direction++;
            } while (!gameBoard->freeFieldAt(splitPos) && direction <= Position::direction::None);

            if (*splitPos == *centerPos) std::cout << "The monster has nowhere to split, good for you" << std::endl;
            else {
                MonsterFearsome* mfsplit = new MonsterFearsome(*mf);
                gameBoard->setFieldActorAt(mfsplit, splitPos);
            }
        }
    }
}
