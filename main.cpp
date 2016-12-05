//#include <cstdlib>

#include <iostream>
#include <gameengine.h>

int main(/*int argc, char *argv[]*/)
{
    std::cout << "Hello World!" << std::endl;

    GameEngine *engine = new GameEngine;
    engine->play();

    return EXIT_SUCCESS;
}

//destruktory
//overloadnut operator
//nahradit moje metody z STL, for_each
//2D pole
//initialize vector by ={a,b,c}
//struct constructor = variable(value),
//sortnut daco
//stringy
