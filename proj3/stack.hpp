#include "stack.h"

using namespace cop4530;

template <typename T>
Stack<T>::Stack(){}

template <typename T>
Stack<T>::~Stack(){}

template <typename T>
Stack<T>::Stack(const Stack<T> & rhs){
	this = rhs;
}

template <typename T>
Stack<T>::Stack(Stack<T> && rhs){
	this = rhs;
}
template <typename T>
Stack<T> & Stack<T>::operator=(const Stack<T> & rhs){
	stack = rhs.stack;
	return *this;
}

template <typename T>
Stack<T> & Stack<T>::operator=(Stack<T> && rhs){
	stack = rhs.stack;
	return *this;
}

template <typename T>
bool Stack<T>::empty() const{
	return stack.empty();
}

template <typename T>
void Stack<T>::clear(){
	stack.clear();
}

template <typename T>
void Stack<T>::push(const T & x){
	stack.push_back(x);
}

template <typename T>
void Stack<T>::push(T && x){
	stack.push_back(x);
}

template <typename T>
void Stack<T>::pop(){
	stack.pop_back();
}

template <typename T>
T & Stack<T>::top(){
	return stack.back();
}

template <typename T>
const T & Stack<T>::top() const{
	return stack.back();
}

template <typename T>
int Stack<T>::size() const{
	return stack.size();
}

template <typename T>
void Stack<T>::print(ostream & os, char ofc) const{
	for(auto itr = stack.begin(); itr != stack.end(); ++itr)
		os << *itr << ofc;
}

template <typename T>
vector<T> Stack<T>::retrieve() const{
	return stack;
}

template <typename T>
ostream & operator <<(ostream & os, const Stack<T> & a){
	a.print(os);
	return os;
} 

template <typename T>
bool operator ==(const Stack<T> & lhs, const Stack<T> & rhs){
	return lhs.retrieve() == rhs.retrieve();
}

template <typename T>
bool operator !=(const Stack<T> & lhs, const Stack<T> & rhs){
	return !(lhs == rhs);
}

template <typename T>
bool operator <(const Stack<T> & lhs, const Stack<T> & rhs){
	return lhs.retrieve() < rhs.retrieve();
}
