#include <iostream>
#include "List.h"

using namespace cop4530;

// nested const_iterator class 
template <typename T>
List<T>::const_iterator::const_iterator() : current{ nullptr} {}

template <typename T>
const T & List<T>::const_iterator::operator* () const {
	return retrieve();
}

template <typename T>
typename List<T>::const_iterator & List<T>::const_iterator::operator++(){		//prefix
	current = current->next;
	return *this;;
}

template <typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator++(int){		//postfix
	const_iterator temp = *this;
	++( *this );

	return temp;
}

template <typename T>
typename List<T>::const_iterator & List<T>::const_iterator::operator--(){		//prefix
	current = current->prev;
	return *this;
}

template <typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator--(int){		//postfix
	const_iterator temp = *this;
	++( *this );
	return temp;
}

template <typename T>
bool List<T>::const_iterator::operator==(const const_iterator & rhs ) const{
	return current == rhs.current;
}

template <typename T>
bool List<T>::const_iterator::operator!=(const const_iterator & rhs ) const{
	return !(*this == rhs);
}
 

template <typename T>
T & List<T>::const_iterator::retrieve() const{
	return current->data;
}

template <typename T>
List<T>::const_iterator::const_iterator(Node *p) : current{p}{}
// End const_iterator class

// Nested iterator class
template <typename T>
T & List<T>::iterator::operator*(){
	return const_iterator::retrieve();
}

template <typename T>
const T & List<T>::iterator::operator*() const {
	return const_iterator::operator*();
}

template <typename T>
typename List<T>::iterator & List<T>::iterator::operator++(){
	this->current = this->current->next;
	return *this;
}

template <typename T>
typename List<T>::iterator List<T>::iterator::operator++(int){
	iterator temp = *this;
	++(*this);
	return temp;
}

template <typename T>
typename List<T>::iterator & List<T>::iterator::operator--(){
	this->current = this->current->prev;
	return *this;
}

template <typename T>
typename List<T>::iterator List<T>::iterator::operator--(int){
	iterator temp = *this;
	--(*this);
	return temp;
}

template <typename T>
List<T>::iterator::iterator(Node *p) : const_iterator {p}{}

// End of nested iterator class

// List Constructors
// Default zero parameter constructor
template <typename T>
List<T>::List(){
	init();
}

// Copy constructor
template <typename T>
List<T>::List(const List &rhs){
	init();
	for( auto & x : rhs)
		push_back(x);
}

// Move constructor
template <typename T>
List<T>::List(List && rhs): theSize{rhs.theSize}, head{rhs.head}, tail{rhs.tail}{
	rhs.theSize = 0;
	rhs.head = nullptr;
	rhs.tail = nullptr;
}

// num elements with value of val
template <typename T>
List<T>::List(int num, const T& val){
	init();
	for(int i = 0; i < num; ++i)
		push_back(val);
}

// Constructs with elements [start, end)
template <typename T>
List<T>::List(const_iterator start, const_iterator end){
	init();
	for(const_iterator itr = start; itr != end; ++itr)
		push_back(itr.retrieve());
}

// Destructor
template <typename T>
List<T>::~List(){
	clear();
	delete head;
	delete tail;
}

// Copy Assignment operator
template <typename T>
const List<T> & List<T>::operator=(const List<T> & rhs){
	List copy = rhs;
	std::swap(*this, copy);
	return *this;
}

// Move Assignment operator
template <typename T>
List<T> & List<T>::operator=(List<T> && rhs){
	std::swap(theSize, rhs.theSize);
	std::swap(head, rhs.head);
	std::swap(tail, rhs.tail);
	return *this;
}

// Member Functions
template <typename T>
int List<T>::size() const{
	return theSize;
}

template <typename T>
bool List<T>::empty() const{
	return size() == 0;
}

template <typename T>
void List<T>::clear(){
	while(!empty())
		pop_front();
}

template <typename T>
void List<T>::reverse(){
	Node *ptr = head;
	while (ptr != nullptr){
		Node *temp = ptr->next;
		ptr->next = ptr->prev;
		ptr->prev = temp;
		if(temp== nullptr){
			tail = head;
			head = ptr;
		}
		ptr = temp;
	}
	

}

template <typename T>
T & List<T>::front(){
	return *begin();
}

template <typename T>
const T & List<T>::front() const{
	return *begin();
}

template <typename T>
T & List<T>::back(){
	return *--end();
}

template <typename T>
const T & List<T>::back() const{
	return *--end();
}

template <typename T>
void List<T>::push_front(const T & val){
	insert( begin(), val);
}

template <typename T>
void List<T>::push_front(T && val){
	insert( begin(), std::move(val));
}

template <typename T>
void List<T>::push_back(const T & val){
	insert( end(), val);
}

template <typename T>
void List<T>::push_back(T && val){
	insert(end(), std::move(val));
}

template <typename T>
void List<T>::pop_front(){
	erase(begin());
}

template <typename T>
void List<T>::pop_back(){
	erase(--(end()));
}

template <typename T>
void List<T>::remove(const T & val){
	for(iterator itr = begin(); itr != end(); ++itr){
		if(itr.retrieve() == val)
			erase(itr);
	}
}

template <typename T>
void List<T>::print(std::ostream& os, char ofc) const{
	for(const_iterator itr = begin(); itr != end(); ++itr)
		os << itr.retrieve() << ofc;
	os << std::endl;
	
}

// Iterator Stuff
template <typename T>
typename List<T>::iterator List<T>::begin(){
	return iterator(head->next);
}

template <typename T>
typename List<T>::const_iterator List<T>::begin() const {
	return const_iterator(head->next);
}

template <typename T>
typename List<T>::iterator List<T>::end(){
	return iterator(tail);
}

template <typename T>
typename List<T>::const_iterator List<T>::end() const {
	return const_iterator(tail);
}

template <typename T>
typename List<T>::iterator List<T>::insert(iterator itr, const T& val){
	Node *n = itr.current;
	++theSize;
	return iterator( n->prev = n->prev->next = new Node{val,n->prev, n});
}

template <typename T>
typename List<T>::iterator List<T>::insert(iterator itr, T && val){
	Node *n = itr.current;
	++theSize;
	return iterator(n->prev = n->prev->next = new Node{std::move(val), n->prev, n});
}

template <typename T>
typename List<T>::iterator List<T>::erase(iterator itr){
	Node *n = itr.current;
	iterator returnVal(n->next);
	n->prev->next = n->next;
	n->next->prev = n->prev;
	delete n;
	--theSize;
	return returnVal;
}

template <typename T>
typename List<T>::iterator List<T>::erase(iterator start, iterator end){
	for(iterator itr = start; itr != end;)
		itr = erase(itr);
	return end;
}


template <typename T>
void List<T>::init(){
	theSize = 0;
	head = new Node;
	tail = new Node;
	head->next = tail;
	tail->prev = head;
}

// Overloaded comparison operators
template <typename T>
bool operator==(const List<T> &lhs, const List<T> &rhs){
	return !(lhs!=rhs);
}

template <typename T>
bool operator!=(const List<T> &lhs, const List<T> &rhs){
	if(lhs.size() != rhs.size())
		return true;
	for(auto litr = lhs.begin(); litr != lhs.end(); ++litr)
		for(auto ritr = rhs.begin(); ritr != rhs.end(); ++ritr)
			if(*litr == *ritr)
				return false;
	return true;
}

// Overloaded output operator
template <typename T>
std::ostream & operator<<(std::ostream &os, const List<T> &l){
	l.print(os);
	return os;
}
