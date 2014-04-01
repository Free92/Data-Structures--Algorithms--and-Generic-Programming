#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <stack>
#include <ctype.h>
#include "bet.h"

using namespace std;

BET::BET(){
	root = nullptr;
}

BET::BET(const string postfix){
	if(!empty())
		makeEmpty(root);
	root = nullptr;
	if(!buildFromPostfix(postfix)){
		cout << "ERROR OCCURRED!" << endl;
	}
}

BET::BET(const BET &rhs){
	*this = rhs;	
}

BET::~BET(){
	makeEmpty(root);
}

bool BET::buildFromPostfix(const string postfix){
	stringstream ss(postfix);
	stringstream ss2;
	string tempString;
	stack<BinaryNode> oStack;
	

	while(ss >> tempString){
		if(tempString == "+" || tempString == "-" || tempString == "*" || tempString == "/"){
			BinaryNode temp;
			temp.element = tempString;
			temp.right = new BinaryNode(oStack.top());
			oStack.pop();
			temp.left = new BinaryNode(oStack.top());
			oStack.pop();

			oStack.push(temp);
		} else {
			BinaryNode temp;
			temp.element = tempString;
			temp.left = NULL;
			temp.right = NULL;
			oStack.push(temp);
		}

	}

	
	root = &oStack.top();

	return true;
}

const BET & BET::operator=(const BET & rhs){
	root = clone(rhs.root);
	return *this;	
}

void BET::printInfixExpression(){
	printInfixExpression(root);
	cout << endl;
}

void BET::printPostfixExpression(){
	printPostfixExpression(root);
	cout << endl;
}

size_t BET::size(){
	return size(root);
}

size_t leaf_nodes(){
	return leaf_nodes(root);
}

bool BET::empty(){
	if(size() == 0)
		return true;
	return false;
}

void BET::makeEmpty(BinaryNode* &t){
	//TO_DO
	if(t != nullptr){
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
}

BET::BinaryNode * BET::clone(BinaryNode *t) const{
	//TO_DO
	if(t == NULL){
        	return NULL;
    	}
    	BinaryNode newNode;
  
        string element(t->element);
        newNode.element = element;
    	
 
   	newNode.left = clone(t->left);
    	newNode.right = clone(t->right);
	BinaryNode * returnNode = new BinaryNode(newNode);
    	return returnNode;
}

void BET::printInfixExpression(BinaryNode *n){
	if(n){
		if(n->element == "+" || n->element == "-" || n->element == "*" || n->element == "/")
			if(n != root)
				cout << " ( ";
		printInfixExpression(n->left);
		cout << " " << n->element << " ";
		printInfixExpression(n->right);
		if(n->element == "+" || n->element == "-" || n->element == "*" || n->element == "/")
			if(n != root)
				cout << " ) ";
	}
}

void BET::printPostfixExpression(BinaryNode *n){
	if(n){
		printPostfixExpression(n->left);
		printPostfixExpression(n->right);
		cout << n->element << " ";
	}
}

size_t BET::size(BinaryNode *t){
	if(t)
	  	return( size(t->left) + size(t->right) + 1 );
	return 0;
}

size_t BET::leaf_nodes(BinaryNode *t){
	//TO_DO
cout << "Have to do stuff here still!" << endl;
}
