#include "world.hpp"

#include "boost/python.hpp"
using namespace boost::python;

// Note: class_ is one word. And we could define it to be in whatever module
BOOST_PYTHON_MODULE(world_ext)
{
    class_ <World>("World")
        .def("greet", &World::greet)
        .def("set", &World::set)
    ;
}

