#include "world.hpp"

#include "boost/python.hpp"
using namespace boost::python;

// Note: class_ is one word. And we could define it to be in whatever
// module. Note adding the init for ctor (preferred with string) and also
// default ctor
BOOST_PYTHON_MODULE(world_ext)
{
    class_ <World>("World", init<std::string>())
        .def(init<>())
        .def("greet", &World::greet)
        .def("set", &World::set)
    ;
}

