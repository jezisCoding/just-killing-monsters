#include "interactiveentity.h"

InteractiveEntity::InteractiveEntity(std::__cxx11::string mapSign) : Entity(mapSign)
{
}

int InteractiveEntity::interaction(InteractiveEntity *with)
{
    //std::cout << "You cannot interact with this entity" << std::cout;
    std::cout << "Undefined interaction of " << typeid(this).name()
              << " with: " << typeid(with).name() << std::endl;
    return 0;
}
