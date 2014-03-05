CCC = g++
CCFlags = -std=c++0x -Wall -g -pedantic
INCLUDES = -I.

all: clean

clean:
	rm -f *.o *~
test1:
	$(CCC) $(CCFlags) -o test.x test.cpp
test2:
	$(CCC) $(CCFlags) -o test.x test_list.cpp
test:
	./test.x

