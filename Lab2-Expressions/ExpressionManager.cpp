#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include "ExpressionManager.h"

const string ERROR = "invalid";

const string OPEN = "([{";
const string CLOSE = ")]}";

bool ExpressionManager::is_open(string ch) {
  return OPEN.find(ch) != string::npos;
}
bool ExpressionManager::is_close(string ch) {
  return CLOSE.find(ch) != string::npos;
}

vector<string> ExpressionManager::parseTokens(string expression)
{
	stringstream ss(expression);
	string token;
	vector<string> tokens;
	while(getline(ss, token, ' '))
{
	tokens.push_back(token);
}
	return tokens;
}
	
	

bool ExpressionManager::isBalanced(string expression){
	cout << "isBalanced: " << expression << endl; //Debug statement, REMOVE
	
	//INITIALIZE your stack here
	stack<string> parens;
	istringstream ss(expression);
        string next;
        while (ss >> next){ //reads each space-separated token from the expression
            if (is_open(next)){
                parens.push(next);
            }
		    else if (is_close(next)){
		        if (parens.empty()){
		            return false;
		        }
		        string last = parens.top();
		        parens.pop();
		        if ( (next == ")" && last != "(") ||
		             (next == "]" && last != "[") ||
		             (next == "}" && last != "{")){
		                 return false;
		             }
		    }
	}
	if (!parens.empty()){
	    return false;
	}
	return true;
}

string ExpressionManager::postfixEvaluate(string postfixExpression){
	cout << "postfixEvaluate: " << postfixExpression << endl; //Debug statement, REMOVE
	
	//INITIALIZE your stack here
	stack<int> operand;
	istringstream ss(postfixExpression);
    string next;
    while (ss >> next){ //reads each space-separated token from the expression
	    if (isdigit(next[0])){
	        if (next.find('.') != string::npos){
	            return ERROR;
	        }
	        int num = stoi(next);
	        operand.push(num);
	    }
        else if (next == "+" || next == "-" || next == "*" || next == "/" || next == "%"){
            if (operand.size() < 2){
                return ERROR;
            }
            else{
                int right = operand.top();
                operand.pop();
                int left = operand.top();
                operand.pop();
                
                int result = 0;
                char op = next[0];
                switch(op) {
                    case '+': (result = left + right); break;
                    case '-': (result = left - right); break;
                    case '*': (result = left * right); break;
                    case '/': 
                        if (right == 0){
                            return ERROR;
                        }
                        (result = left / right);
                        break;
                    case '%': (result = left % right); break;
                }
                operand.push(result);
            }
        }
        else{
            return ERROR;
        }
    }
	if (!operand.empty()){
	    return to_string(operand.top());
	}
}

string ExpressionManager::postfixToInfix(string postfixExpression){
	cout << "postfixToInfix: " << postfixExpression << endl; //Debug statement, REMOVE
	
	//INITIALIZE your stack here
	stack<string> myStack;
	istringstream ss(postfixExpression);
        string next;
        while (ss >> next){ //reads each space-separated token from the expression
		    if (isdigit(next[0])){
		        if (next.find('.') != string::npos){
		            return ERROR;
		        }
		        myStack.push(next);
		    }
		    else if (next == "+" || next == "-" || next == "*" || next == "/" || next == "%"){
		        if (myStack.size() < 2){
		            return ERROR;
		        }
		        string right = myStack.top();
		        myStack.pop();
		        string left = myStack.top();
		        myStack.pop();
		        
		        string exp = "( " + left + " " + next + " " + right + " )";
		        myStack.push(exp);
		    }
		    else {
		        return ERROR;
		    }
	}
	if (myStack.size() != 1){
	    return ERROR;
	}
	return myStack.top();
}
