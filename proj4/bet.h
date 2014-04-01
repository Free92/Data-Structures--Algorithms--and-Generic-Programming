#ifndef BET_H
#define BET_H

using namespace std;

class BET {
public:
	BET(); // Default zero-parameter constructor
	BET(const string postfix); // One-parameter constructor, where parameter "postfix" is string containing a postfix expression. The tree should be built based on the postfix expression. Tokens in the postfix expression are separated by space
	BET(const BET &rhs); // Copy Constructor
	~BET(); // Destructor
	bool buildFromPostfix(const string postfix); // Parameter "postfix" is string containing a postfix expression. The tree should be built based on the postfix expression. Tokens in the postfix expression are separated by space. If the tree contains nodes before the function is called, you need to first delete the existing nodes. Return true if the new tree is built successfully. Return false if an error is encountered.
	const BET & operator=(const BET & rhs); // Assignment operator
	void printInfixExpression();  // Call the private version of the printInfixExpression function to print out the infix expression.
	void printPostfixExpression(); // Call the private version of the printPostfixExpression function to print out the postfix expression.
	size_t size(); // Call the  private version of the size function to return the number of nodes in the tree.
	size_t leaf_nodes(); // Call the private version of the leaf_nodes function to return the number of leaf nodes in the tree.
	bool empty(); // return true if the tree is empty. Return false otherwise.

private:
	struct BinaryNode {
		string element;
		BinaryNode *left;
		BinaryNode *right;
	};
	BinaryNode *root;
	void printInfixExpression(BinaryNode *n); // Print to the standard output the corresponding infix expression. Note that you may need to add parentheses depending on the precedence of operators. You should not have unnecessary parentheses.
	void makeEmpty(BinaryNode* &t); // Delete all nodes in the subtree pointed to by t. Called by functions such as the destructor.
	BinaryNode * clone(BinaryNode *t) const; // Clone all nodes in the subtree pointed to by t. Called by functions such as the assignment operator=.
	void printPostfixExpression(BinaryNode *n); // Print to the standard output the corresponding postfix expression.
	size_t size(BinaryNode *t); // Return the number of nodes in the subtree pointed to by t.
	size_t leaf_nodes(BinaryNode *t); // Return the number of leaf nodes in the subtree pointed to by t.
};

#include "bet.hpp"

#endif
