#include <iostream>
#include <sstream>
#include <cctype>
#include "stack.h"

using namespace std;
using namespace cop4530;

int opRank(string oper);
void parser(Stack<string> & outStack, string line);
string eval(Stack<string> & outStack);

int main(){
	Stack<string> outStack;
	string line;
int i = 0;
	cout << "Enter infix expression (\"exit\" to quit): ";
	while(getline(cin, line)){
		cout << endl;
		if(line == "exit")
			return 0;
cout << i << ")." << endl;
		parser(outStack, line);
		cout << "Enter infix expression (\"exit\" to quit): ";
		outStack.clear();
++i;
	}


	cout << endl;
	return 0;
}

int opRank(string oper){
	if(oper == "*" || oper == "/")
		return 1;
	else if ( oper == "+" || oper == "-")
		return 2;
}

string eval(Stack<string> & outStack){
	stringstream ss;
	Stack<int> evalStack;
	ss << outStack;

	string strTemp;
	stringstream returnSS;
	string returnStr;


	while(ss >> strTemp){
		stringstream ss2(strTemp);
		int intTemp;

		if(ss2 >> intTemp){
			evalStack.push(intTemp);
		} else if(strTemp.length() > 1){
			returnSS << outStack;
			getline(returnSS, returnStr);
			return returnStr;
		} else if(isalpha(strTemp[0])){
				returnSS << outStack;
				getline(returnSS, returnStr);
				return returnStr;
		} else if(strTemp == "+" || strTemp == "-" || strTemp == "*" || strTemp == "/"){
			if(evalStack.size() < 2)
				return "\nError: Missing operand in postfix string. Unable to evaluate postfix string!";
			int rhs = evalStack.top();
			evalStack.pop();
			int lhs = evalStack.top();
			evalStack.pop();

			switch(strTemp[0]){
				case '+':
					evalStack.push(lhs+rhs);
					break;
				case '-':
					evalStack.push(lhs-rhs);
					break;
				case '/':
					evalStack.push(lhs/rhs);
					break;
				case '*':
					evalStack.push(lhs*rhs);
					break;
			}
		} else
			cout << "ERROR ENCOUNTERED!" << endl;
	}

	returnSS << evalStack;
	getline(returnSS, returnStr);		
	return returnStr;
}


void parser(Stack<string> & outStack, string line){
	Stack<string> opStack;
	stringstream ss(line);
	string temp;
	// Checks to see if balanced parens
	int paren = 0;
	// Used to check if there are any operands
	int isNum = 0;
	// Use to check to see if there are any operators
	int isOp = 0;
	while(ss>>temp){
		if(temp == "+" || temp == "-" || temp == "*" || temp == "/"){
			isOp++;
			while(!opStack.empty() && opRank(opStack.top()) <= opRank(temp)){
				outStack.push(opStack.top());
				opStack.pop();
			}
			opStack.push(temp);
		} else if (temp == "("){
			paren++;
			opStack.push(temp);
		} else if (temp == ")"){
			paren--;
			if(!opStack.empty()){
				while(opStack.top() != "("){
					outStack.push(opStack.top());
					opStack.pop();
				}
			opStack.pop();
			} else {
								cout << "Error: Infix expression: " << line << " has mismatched parens!" << endl;
					return;
			}
		} else {
			outStack.push(temp);
			isNum++;
		}
	}
	
	while(!opStack.empty()){
		outStack.push(opStack.top());
		opStack.pop();

	}
	if(isNum == 0){
		cout << "Error: Missing operands in the expression" << endl;
		return;
	} else if(isOp == 0){
		cout << "Error: Missing operators in the expression" << endl;
		return;
	} else if(paren != 0){
		cout << "Error: Infix expression: " << line << "has mismatched parens!" << endl;
		return;
	} else {
		cout << "Postfix expression: " << outStack << endl;
		cout << "Postfix evaluation: " << outStack << " = " << eval(outStack) << endl;
	}		
}
