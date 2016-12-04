//#include <cstdlib>

#include <iostream>

struct MathClass{
    int value;
    MathClass(int value){this->value = value;}
    /*MathClass* operator+ (MathClass* b){
        MathClass* box = new MathClass(value + b->value);
        return box;
    }*/
    void out() {std::cout << this->value << std::endl;}
};

int main(int argc, char *argv[])
{

    MathClass* meh = new MathClass(2);
    MathClass* ayy = new MathClass(2);
    int s = 0;
    meh = meh + s;
    meh->out();

    std::cout << "Hello World!" << std::endl;
    return EXIT_SUCCESS;
}

//overloadnut operator

