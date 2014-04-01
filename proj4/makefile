CCC = g++
CCFlags = -std=c++0x -Wall -g -pedantic
INCLUDES = -I.

all: clean test2

clean:
	rm -f *.o *~
test2:
	$(CCC) $(CCFlags) -o proj4.x proj4_driver.cpp
test:
	./proj4.x<test.txt


