#ifndef _WORLD_HPP_
#define _WORLD_HPP_

#include <string>

// You might prefer as struct rather than class if you want to use it in python
// (typically no private vars) and default ctor is available.

// Deliberately made *not inline* unlike in the tutorial

// And it has a constructor and methods which pass args by reference

struct World
{
    std::string msg;

    // methods
    World();
    explicit World(const std::string& msg);
    void set(const std::string& msg);
    std::string greet();
};

#endif /* _WORLD_HPP_ */
