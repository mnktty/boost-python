# Introduction

Boost Python tutorial does not explain how to use a Makefile to build the
extension module. Here is a feeble attempt to do so.

# Basic example

## Compiling the hello world example

The example refers to
<http://www.boost.org/doc/libs/1_54_0/libs/python/doc/tutorial/doc/html/index.html#python.quickstart>

In one shot, you can compile the entire code as follows:

    g++ -o hello_ext.so -shared -Wl,-soname,"hello_ext.so" -fpic -g -Wall -I /usr/include/python2.7 hello.cpp hello_py.cpp -L /usr/lib -lboost_python -lpython2.7

Please note the following constraints / gotchas:

-   `hello.h` need not have the extern "C" for C functions
-   Specifying `-Wl,-soname` is very important - both output and soname should
    **match** the module name defined with `BOOST_PYTHON_MODULE()` macro - in this
    case `hello_ext`
-   Obviously do not forget to link against the libboost and libpython - their
    correct versions depend on the installed version of boost and python.
-   In case, the C/C++ files are built separately (as object files and then
    linked), ensure that the object files precede linking against the boost and
    python libs

Then the python example works out of the box !

    import hello_ext
    print hello_ext.greet()

## A deeper look

Let us assume the extension library was built as `libhello.so` purely by
specifying the output name `-o`. The output of nm is as follows:

    nm -C libhello.so | grep init
    000042d8 T init_module_hello_ext()
    00004308 t __static_initialization_and_destruction_0(int, int)
             U boost::python::detail::init_module(char const*, void (*)())
    00005250 r boost::initialized_value
    000081a0 b std::__ioinit
    00003be4 T _init
    000042a8 T inithello_ext

The lib initialization code is in `inithello_ext`, and we have specified our
extension module to be `hello_ext` (using `BOOST_PYTHON_MODULE()`). However,
when we import the `libhello.so`, it tries to call `initlibhello` and fails. To
match the name, we specify the output and also the linker option for the soname

If the libnames are not correct, import gives error in python: `ImportError:
dynamic module does not define init function (initlibhello)`

Yet another thing: A properly built extension module will depend on boost<sub>python</sub>
and python as follows

    precise@pingu ~/svn/experiment/boopy/hello $ ldd hello_ext.so 
            linux-gate.so.1 =>  (0x004a8000)
            libboost_python-py27.so.1.46.1 => /usr/lib/libboost_python-py27.so.1.46.1 (0x00110000)
            libpython2.7.so.1.0 => /usr/lib/libpython2.7.so.1.0 (0x00158000)
            libstdc++.so.6 => /usr/lib/i386-linux-gnu/libstdc++.so.6 (0x008c4000)
            libgcc_s.so.1 => /lib/i386-linux-gnu/libgcc_s.so.1 (0x00b31000)
            libc.so.6 => /lib/i386-linux-gnu/libc.so.6 (0x004a9000)
            libpthread.so.0 => /lib/i386-linux-gnu/libpthread.so.0 (0x0041e000)
            libssl.so.1.0.0 => /lib/i386-linux-gnu/libssl.so.1.0.0 (0x00439000)
            libcrypto.so.1.0.0 => /lib/i386-linux-gnu/libcrypto.so.1.0.0 (0x00653000)
            libz.so.1 => /lib/i386-linux-gnu/libz.so.1 (0x0048f000)
            libdl.so.2 => /lib/i386-linux-gnu/libdl.so.2 (0x00869000)
            libutil.so.1 => /lib/i386-linux-gnu/libutil.so.1 (0x00f7c000)
            libm.so.6 => /lib/i386-linux-gnu/libm.so.6 (0x00ae7000)
            /lib/ld-linux.so.2 (0x00c14000)

# Working with classes

NOTE: In case any C++ code was changed (e.g. signature change), rebuilding the
entire extension module was important for correct functioning of the extension

-   You can separate the C++ class to header and implementation.

-   You can pass method args by value or reference - e.g. `World::set(const
      string& s)`

-   Default ctor will be implicitly exposed, unless made private or disabled.

-   pyste does not seem to work - is it broken ?
