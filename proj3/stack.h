#ifndef STACK_H
#define STACK_H

#include <vector>

using namespace std;

namespace cop4530{

template <typename T>
class Stack{
public:
	Stack();
	~Stack();
	Stack(const Stack<T>&);
	Stack(Stack<T> &&);
	Stack<T> & operator=(const Stack<T> &);
	Stack<T> & operator=(Stack<T> &&);
	bool empty() const;
	void clear();
	void push(const T & x);
	void push(T && x);
	void pop();
	T & top();
	const T & top() const;
	int size() const;
	void print(ostream & os, char ofc = ' ') const;
	
	vector<T> retrieve() const;
private:
	vector<T> stack;
};

template <typename T>
ostream & operator <<(ostream & os, const Stack<T> & a);

template <typename T>
bool operator ==(const Stack<T> & lhs, const Stack<T> & rhs);

template <typename T>
bool operator !=(const Stack<T> & lhs, const Stack<T> & rhs);

template <typename T>
bool operator <(const Stack<T> & lhs, const Stack<T> & rhs);

#include "stack.hpp"

}

#endif
