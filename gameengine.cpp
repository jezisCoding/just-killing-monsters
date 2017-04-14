#include "gameengine.h"

GameEngine::GameEngine()
{
    gameBoard = new GameBoard(false);
    hero = gameBoard->getHero();
}

GameEngine::~GameEngine()
{
    deleteBoard();
}

    //Not used anymore
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
                    saveGame("gameSave.xml");
                    break;
                case 'R':
                    loadGame("gameSave.xml");
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
        } catch (file_error& ex){
            sos::iout << "Exception in GameEngine::play() : "
                      << ex.what() << std::endl;
        } catch (invalid_input& ex){
            sos::iout << "Exception in GameEngine::play() : "
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
    sos::iout << "Welcome to the game of Just Killing Monsters\n"
              << "Kill all the monsters by running into them.\n"
              << "When you move between your hits, you get Surprise strike bonus damage on hit\n\n"

              << "Controls: WSAD to move\n\n"

              << "Legend: [H]-Hero, [P]-Health Potion, [M,W,V]-Monsters, [T]-Tree\n\n";
    gameBoard->printBoard();
}

void GameEngine::heroTurn(const char& direction){
    Position *targetPosition = new Position();
    *targetPosition = Position::getNewPositionInDirection(hero->getPosition(), direction);
    FieldActor *targetFieldActor = gameBoard->getFieldAt(targetPosition)->getFieldActor();

    if (targetFieldActor != nullptr) heroAction(targetFieldActor, targetPosition);
    else gameBoard->moveHero(targetPosition);
}

void GameEngine::heroAction(FieldActor* targetFieldActor, Position* targetPosition){
    uint8_t outcome = hero->interaction(targetFieldActor);

        //bitwise
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
        hero = nullptr, gameBoard->heroDied();
    }
}

/**
 * This method returns input from keyboard converted to Upcase
 *
 * Not used anymore
 */
char GameEngine::getKeyboardInput() const throw(invalid_input){
    sos::iout << "Hero's action: ";
    char input;
    std::cin >> input;
    sos::iout << std::endl;
    if (!isalpha((int)input)) throw (invalid_input("Use only letters for controlling"));
    return toupper(input);
}

void GameEngine::saveGame(const QString& fileName) const throw(file_error){
    try{
        if(gameBoard->saveBoardXml(fileName)){
            gameBoard->printBoard();
            sos::iout << "XML Saved." << std::endl << std::endl;
        }
    } catch (file_error& ex){
        throw ex;
    }
}

void GameEngine::loadGame(const QString& fileName) throw(file_error){
    try{
        QFile test(fileName);
        if(test.open(QIODevice::ReadOnly)){
            test.close();
            deleteBoard();   //deletes hero too

            gameBoard = new GameBoard(true);    //load? true
            hero = gameBoard->loadBoardXml(fileName);   //returns pointer to Hero
            gameBoard->printBoard();            
            sos::iout << "Game Loaded." << std::endl;
        } else {
            throw file_error("Error in GameEngine::loadGame : "
                             "File not open(may not exist, save game first?)");
        }
    } catch (file_error& ex){
        sos::iout << "File not open" << std::endl;
        throw ex;
    }
}

bool GameEngine::endGame()
{
    if (gameBoard == nullptr){
        sos::iout << "Game over." << std::endl;
        return true;
    }
    else if (hero == nullptr && gameBoard->monstersDead()){
        sos::iout << "After an epic battle with the last of the monsters... You died.\n"
                     "But you did kill them all and the goal of the game was not to survive so "
                     "technically you still won."
                  << std::endl << std::endl
                  << "Game over" << std::endl;
        deleteBoard();
        return true;
    }
    else if (hero == nullptr) {
        sos::iout << "You ded"
                  << std::endl << std::endl
                  << "Game over" << std::endl;
        deleteBoard();
        return true;
    }
    else if (gameBoard->monstersDead()){
        sos::iout << "You've killed all the monsters and saved the village from certain doom! GG"
                  << std::endl << std::endl
                  << "Game over" << std::endl;
        deleteBoard();
        return true;
    }
    return false;
}
    //for CLI version
bool GameEngine::endGame(const char &input){
    if (input == 'X'){
        sos::iout << "Game over" << std::endl;
        return true;
    }
    return endGame();
}

void GameEngine::splitMonsterAround(FieldActor* monster, Position* centerPos){
    if (monster != nullptr){
        MonsterFearsome* mf = dynamic_cast<MonsterFearsome*>(monster);

        if (mf == nullptr) sos::iout << "monstersplit cast error" << std::endl;
        else {
            int direction = Position::Up;
            Position* splitPos = new Position;

            do {
                *splitPos = Position::getNewPositionInDirection(centerPos, (Position::direction)direction);
                direction++;
            } while (!gameBoard->freeFieldAt(splitPos) && direction <= Position::direction::None);

            if (*splitPos == *centerPos) sos::iout << "The monster has nowhere to split, good for you" << std::endl;
            else {
                MonsterFearsome* mfsplit = new MonsterFearsome(*mf);
                gameBoard->setFieldActorAt(mfsplit, splitPos);
            }
        }
    }
}

void GameEngine::deleteBoard()
{
    delete gameBoard;
    gameBoard = nullptr;
}
