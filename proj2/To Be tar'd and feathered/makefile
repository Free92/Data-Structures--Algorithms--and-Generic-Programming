CCC = g++47
CCFlags = -std=c++11 -Wall -g -pedantic
INCLUDES = -I.

all: clean test2

clean:
	rm -f *.o *~
test2:
	$(CCC) $(CCFlags) -o proj2.x test_list.cpp
test:
	./proj2.x

