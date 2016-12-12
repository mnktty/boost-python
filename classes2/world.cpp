#include "World.hpp"

World::World() :msg("Empty World"){}

World::World(const std::string& msg):msg(msg) {}

void World::set(const std::string& msg) { 
    this->msg = msg; 
}
    
std::string World::greet() { 
    return msg; 
}

// eof
