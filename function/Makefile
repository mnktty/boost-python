# Makefile to build a python extension with boost python. Boost Python uses bjam
# and does not explain (in as many words), how to build an python extension
# module with a Makefile

# Attention: The build should mirror the commmand as follows. It is important
# that the obj files are linked in prior to the boost libs

# g++ -o hello_ext.so -shared -Wl,-soname,"hello_ext.so" -fpic -g -Wall -I /usr/include/python2.7 hello.cpp hello_py.cpp -L /usr/lib -lboost_python -lpython2.7

CC=g++
CFLAGS=-fpic -g -Wall
INCLUDE=-I /usr/include/python2.7

LDFLAGS=-L /usr/lib
LIBS=-lboost_python -lpython2.7

SRCS=hello.cpp hello_py.cpp
OBJS = $(SRCS:.cpp=.o)

all: test

test: hello_ext.so
	@echo "Executing test_hello.py"
	./test_hello.py

hello_ext.so: $(OBJS)
	$(CC) -o hello_ext.so -shared -Wl,-soname,"hello_ext.so" $(CFLAGS) $(OBJS) $(LDFLAGS) $(LIBS)

.cpp.o:
	$(CC) -c $(CFLAGS) $(INCLUDE) -c $< -o $@

.PHONY=clean

clean:
	rm *.o *.so

# eof