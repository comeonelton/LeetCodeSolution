/*
 * EvaluateReversePolishNotation.cpp
 *
 *  Created on: 2014/3/17
 *      Author: comeonelton
 */

#include "EvaluateReversePolishNotation.h"

#include <iostream>
#include <string>
#include <sstream>

#include <stdlib.h>

using namespace std;

string int2str(int i)
{
	string s;
	stringstream ss(s);
	ss << i;

	return ss.str();
}

int value(string& token)
{
	int i;
	istringstream(token) >> i;
	return i;
}

bool isValue(string& s)
{
	if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;

	char * p ;
	strtol(s.c_str(), &p, 10) ;

	return (*p == 0) ;
}

bool isOp(string& s)
{
	return s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/';
}

int eval(string& value1, string& value2, string& op)
{
	int v1 = value(value1);
	int v2 = value(value2);
	int result;

	switch (op[0])
	{
	case '+':
		result = v1 + v2;
		break;
	case '-':
		result = v1 - v2;
		break;
	case '*':
		result = v1 * v2;
		break;
	case '/':
		result = v1 / v2;
		break;

	}
	return result;
}

void printVector(vector<string> &tokens, int mark)
{
	for (int i=0 ; i< tokens.size() ; i++) {
		//cout << "[" << tokens[i] << ((i == mark) ? "]  " : "]* ");
		cout << "[" << tokens[i] << "]  ";
	}
	cout << endl;
}

// TODO: don't manipulate on original vector
int evalRPN(vector<string> &tokens)
{
	if (tokens.size() == 1) {
		return value(tokens[0]);
	}

	printVector(tokens, 0);

	int tmp;
	int i = 1;
	while (tokens.size() > 3) {
		// Begin from 2nd second or roll back when last 2 element
		if (i == 0 || i == tokens.size()-1)
			i = 1;

		if (isValue(tokens[i-1]) && isValue(tokens[i]) && isOp(tokens[i+1])) {
			tmp = eval(tokens[i-1], tokens[i], tokens[i+1]);
			// *** Erase in 'reverse' order
			tokens.erase(tokens.begin() + i+1);
			tokens.erase(tokens.begin() + i);
			tokens.erase(tokens.begin() + i-1);
			tokens.insert(tokens.begin()+i-1, int2str(tmp));

			printVector(tokens, i-1);

			i--;
			continue;
		}

	    i++;
	}
	return eval(tokens[0], tokens[1], tokens[2]);
}

void test()
{
	const char* a[] = {"1", "2", "+", "3", "4", "+", "*"};  // 21
	vector<string> v1(a, a+7);  //FIXME
	cout << "evalRPN = " << evalRPN(v1) << endl;

	const char* b[] = {"2", "2", "3", "4", "+", "-", "*"};  // -10
	vector<string> v2(b, b+7);  //FIXME
	cout << "evalRPN = " << evalRPN(v2) << endl;

	const char* c[] = {"2", "3", "4", "+", "*", "5", "+"};  // 19
	vector<string> v3(c, c+7);  //FIXME
	cout << "evalRPN = " << evalRPN(v3) << endl;

	const char* d[] = {"2", "2", "3", "+", "*", "3", "4", "+", "*"};  // 70
	vector<string> v4(d, d+9);  //FIXME
	cout << "evalRPN = " << evalRPN(v4) << endl;

	const char* e[] = {"2", "2", "3", "+", "*", "5", "3", "4", "+", "*", "+"};  // 45
	vector<string> v5(e, e+11);  //FIXME
	cout << "evalRPN = " << evalRPN(v5) << endl;
}




