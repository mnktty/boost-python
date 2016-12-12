#include "World.hpp"

void World::set(std::string msg) { 
    this->msg = msg; 
}
    
std::string World::greet() { 
    return msg; 
}

// eof
