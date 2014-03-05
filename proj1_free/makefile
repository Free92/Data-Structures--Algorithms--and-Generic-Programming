CCC = g++
CCFlags = -std=c++0x -Wall -g -pedantic  
INCLUDES = -I.

all: proj1.x clean

proj1.x: proj1.o
	$(CCC) $(CCFlags) -o proj1.x proj1.o
proj1.o: proj1.cpp
	$(CCC) -c $(CCFlags) $(INCLUDES) proj1.cpp
clean:
	rm -f *.o *~


.SUFFIXES :

test:
	./proj1.x

