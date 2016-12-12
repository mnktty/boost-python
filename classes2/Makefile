# Makefile to build a python extension with boost python. Boost Python uses bjam
# and does not explain (in as many words), how to build an python extension
# module with a Makefile

CC=g++
CFLAGS=-fpic -g -Wall
INCLUDE=-I /usr/include/python2.7

LDFLAGS=-L /usr/lib
LIBS=-lboost_python -lpython2.7

SRCS=world.cpp world_ext.cpp
OBJS = $(SRCS:.cpp=.o)

all: world_ext.so

test: world_ext.so
	@echo "Executing test_world.py"
	./test_world.py

world_ext.so: $(OBJS)
	$(CC) -o world_ext.so -shared -Wl,-soname,"world_ext.so" $(CFLAGS) $(OBJS) $(LDFLAGS) $(LIBS)

.cpp.o:
	$(CC) -c $(CFLAGS) $(INCLUDE) -c $< -o $@

.PHONY=clean

clean:
	rm *.o *.so

# eof