#include "gameengine.h"

GameEngine::GameEngine()
{
    gameBoard = new GameBoard();
    hero = gameBoard->getHero();

    //oldCoutStreamBuf = StaticOutputStream::getStream().rdbuf();
    //std::ostringstream strCout;
    //StaticOutputStream::getStream().rdbuf(myCout->rdbuf());   //&rdbuf()
}

GameEngine::~GameEngine()
{
    delete gameBoard;
}

void GameEngine::play(){
    bool gameOver = false;
    char input = '\0';
    this->welcome();
    do {
        try{
            do {
                input = getKeyboardInput();
                switch (input) {
                case 'Q':
                    this->welcome();
                    break;
                case 'E':
                    saveGame();
                    break;
                case 'R':
                    loadGame();
                    break;
                case 'X':
                    //just let it go
                    break;
                case 'W':
                case 'S':
                case 'A':
                case 'D':
                    heroTurn(input);
                default:
                    gameBoard->printBoard();
                }
            } while (!(gameOver = endGame(input)));   
        } catch (std::exception& ex){
            std::cerr << "Exception in GameEngine::play() : "
                      << ex.what() << std::endl;
        }
    } while (!gameOver);
}

void GameEngine::GUIKeyinput(int key)
{
    switch (key) {
    case Qt::Key_W:
        heroTurn('W');
        break;
    case Qt::Key_S:
        heroTurn('S');
        break;
    case Qt::Key_A:
        heroTurn('A');
        break;
    case Qt::Key_D:
        heroTurn('D');
        break;
    default:
        break;
    }
    gameBoard->printBoard();
}

void GameEngine::welcome() const{
    StaticOutputStream::getStream()
              << "Welcome to the game of Just Killing Monsters\n"
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

    if (targetFieldActor  != nullptr) heroAction(targetFieldActor ,targetPosition);
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
    StaticOutputStream::getStream() << "Hero's action: ";
    char input;
    std::cin >> input;
    StaticOutputStream::getStream() << std::endl;
    if (!isalpha((int)input)) throw (invalid_input("Use only letters for controlling"));
    return toupper(input);
}

void GameEngine::saveGame() const throw(file_error){
    try{
        if(gameBoard->saveBoard()) StaticOutputStream::getStream() << "Game saved." << std::endl;
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
        StaticOutputStream::getStream() << "Game over" << std::endl;
        return true;
    }
    else if (hero == nullptr && gameBoard->monstersDead()){
        StaticOutputStream::getStream() << "After an epic battle with the last of the monsters... You died.\n"
                     "But you did kill them all and the goal of the game was not to survive so "
                     "technically you still won."
                  << std::endl << std::endl
                  << "Game over" << std::endl;
        return true;
    }
    else if (hero == nullptr) {
        StaticOutputStream::getStream() << "You ded"
                  << std::endl << std::endl
                  << "Game over" << std::endl;
        return true;
    }
    else if (gameBoard->monstersDead()){
        StaticOutputStream::getStream() << "You've killed all the monsters and saved the village from certain doom! GG"
                  << std::endl << std::endl
                  << "Game over" << std::endl;
        return true;
    }
    return false;
}

void GameEngine::splitMonsterAround(FieldActor* monster, Position* centerPos){
    if (monster != nullptr){
        MonsterFearsome* mf = dynamic_cast<MonsterFearsome*>(monster);

        if (mf == nullptr) StaticOutputStream::getStream() << "monstersplit cast error" << std::endl;
        else {
            int direction = Position::Up;
            Position* splitPos = new Position;

            do {
                *splitPos = Position::getNewPositionInDirection(centerPos, (Position::direction)direction);
                direction++;
            } while (!gameBoard->freeFieldAt(splitPos) && direction <= Position::direction::None);

            if (*splitPos == *centerPos) StaticOutputStream::getStream() << "The monster has nowhere to split, good for you" << std::endl;
            else {
                MonsterFearsome* mfsplit = new MonsterFearsome(*mf);
                gameBoard->setFieldActorAt(mfsplit, splitPos);
            }
        }
    }
}
