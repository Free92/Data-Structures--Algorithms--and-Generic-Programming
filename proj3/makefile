CCC = g++-4.7
CCFlags = -std=c++11 -Wall -g -pedantic
INCLUDES = -I.

all: clean test2

clean:
	rm -f *.o *~
test2:
	$(CCC) $(CCFlags) -o proj3.x in2post.cpp
test:
	./proj3.x<test1.txt


