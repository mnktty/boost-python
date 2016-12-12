#ifndef _WORLD_HPP_
#define _WORLD_HPP_

#include <string>

// You might prefer as struct rather than class if you want to use it in python
// (typically no private vars) and default ctor is available.

// Deliberately made *not inline* unlike in the tutorial
struct World
{
    std::string msg;

    // methods
    void set(std::string msg);
    std::string greet();
};

#endif /* _WORLD_HPP_ */
