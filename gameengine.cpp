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
              << "ENTER to confirm\n\n1"

              << "When you move between your hits, you get Surprise strike bonus damage on hit\n"
              << "Legend: [H]-Hero, [P]-Health Potion, [M,N,...]-Monsters, [T]-Tree\n";
    gameBoard->printBoard();
}

void GameEngine::heroTurn(char direction){
    Position *targetPosition = new Position();
    *targetPosition = Position::getNewPositionInDirection(hero->getPosition(), direction);
    Entity *targetFieldEntity = gameBoard->getFieldAt(targetPosition)->getFieldEntity();

    if (targetFieldEntity != nullptr) heroAction(targetFieldEntity);
    else gameBoard->moveHero(targetPosition);
}

void GameEngine::heroAction(Entity* targetFieldEntity){
    uint8_t outcome = hero->interaction(targetFieldEntity);

        //hero(attacker) died
    if((outcome & 1) == 1){gameBoard->deleteEntityAt(hero->getPosition()); hero = nullptr;}
        //opponent(defender) died
    if((outcome & 2) == 2)gameBoard->deleteEntityAt(targetFieldEntity->getPosition());
        //monster split
    if((outcome & 4) == 4)splitMonsterAround(targetFieldEntity, hero->getPosition());
}

/**
 * This method returns input from keyboard converted to Upcase
 */
char GameEngine::getKeyboardInput() const throw (invalid_input){
    std::cout << "Hero's action: ";
    char input;
    std::cin >> input;
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

void GameEngine::splitMonsterAround(Entity* monster, Position* centerPos){
    MonsterFearsome* mf = dynamic_cast<MonsterFearsome*>(monster);

    if (mf == nullptr) std::cout << "monstersplit cast error" << std::endl;
    else {
        int direction = Position::Up;
        Position* splitPos = new Position;

        do {
            *splitPos = Position::getNewPositionInDirection(centerPos, (Position::direction)direction);
            ++direction; // ++doesnt matter here
        } while (direction != (int)Position::Left || !gameBoard->emptyFieldAt(splitPos));

        MonsterFearsome* mfsplit = new MonsterFearsome(*mf);
        gameBoard->setFieldEntityToPosition(mfsplit, splitPos);
    }
}
