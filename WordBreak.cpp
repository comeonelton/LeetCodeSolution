/*
 * WordBreak.cpp
 *
 *  Created on: 2014/5/16
 *      Author: comeonelton
 */

#include "WordBreak.h"
#include <stack>

using namespace std;

WordBreak::WordBreak() {
	// TODO Auto-generated constructor stub

}

WordBreak::~WordBreak() {
	// TODO Auto-generated destructor stub
}

int WordBreak::wordBreak(string s, unordered_set<string> &dict) {
	static vector<string> words;

	int combination = 0;
	unordered_set<string>::iterator iter = dict.begin();

	if (s.empty())
		return false;

	while (iter != dict.end()) {
		string w = *iter;
		if (!s.compare(0, w.length(), w)) {
			words.push_back(w);

			if (s.length() == w.length()) {
				dumpWords(words);
				combination++;
			}

			combination += wordBreak(s.substr(w.length(), s.length()-w.length()), dict);

			words.pop_back();
		}

		iter++;
	}

	return combination;
}

void WordBreak::dumpWords(const vector<string> &v) {
	for (int i=0 ; i<v.size() ; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

// Act like BFS, but I don't know how to store segmented words and print them out.
int WordBreak::wordBreak_iterative(string s, unordered_set<string> &dict) {
	int combination = 0;
	vector<string> words;
	stack<string> todo;

	todo.push(s);
	while (!todo.empty()) {
		string s = todo.top();
		todo.pop();

		unordered_set<string>::iterator iter = dict.begin();
		while (iter != dict.end()) {
			string w = *iter;
			if (!s.compare(0, w.length(), w)) {

				if (s.length() == w.length()) {
					dumpWords(words);
					combination++;
				} else {
					todo.push(s.substr(w.length(), s.length()-w.length()));
				}
			}
			iter++;
		}
	}

	return combination;
}

struct stack_entry {
	string s;
	unordered_set<string>::iterator dict_iter;
};

// Act like DFS(human way)
int WordBreak::wordBreak_iterative2(string s, unordered_set<string> &dict) {
	int combination = 0;
	stack<stack_entry> todo;
	vector<string> words;

	stack_entry se;
	se.s = s;
	se.dict_iter = dict.begin();

	todo.push(se);
	while (!todo.empty()) {
		stack_entry se = todo.top();
		todo.pop();

		string s = se.s;
		unordered_set<string>::iterator &iter = se.dict_iter;  // reference here!
		/*
		if (iter != dict.end())
			cout << "(" << s << ", " << *iter << ")" << endl;
		else
			cout << "(" << s << ", " << "NULL)" << endl;
			*/

		bool matchInThisIteration = false;
		while (iter != dict.end()) {
			string w = *iter;
			//cout << "compare " << w << endl;
			if (!s.compare(0, w.length(), w)) {
				matchInThisIteration = true;
				words.push_back(w);
				//cout << "push " << w << endl;
				//cout<< "stack: ";  dumpWords(words);

				se.dict_iter = ++iter;
				todo.push(se);

				if (s.length() == w.length()) {
					dumpWords(words);
					combination++;

					//cout << "pop1 " << words.back() << endl;
					words.pop_back();  //cout<< "stack: ";  dumpWords(words);
				} else {
					stack_entry new_se;
					new_se.s = s.substr(w.length(), s.length()-w.length());
					new_se.dict_iter = dict.begin();

					todo.push(new_se);
				}
				break;  // Use 'break' here to act like DFS
			}

			iter++;
		}

		if (!matchInThisIteration) {
			if (words.empty()) {
				cout << "pop2, already empty!" << endl;
			} else {
				//cout << "pop2 " << words.back() << endl;
				words.pop_back(); //cout<< "stack: ";  dumpWords(words);
			}
		}
	}

	return combination;
}

void WordBreak::execute() {
	unordered_set<string> dict;
	/*
	dict.insert("leet");
	dict.insert("code");
	dict.insert("abc");
	dict.insert("ab");
	dict.insert("ccode");
	*/
	dict.insert("a");
	dict.insert("b");
	dict.insert("ab");
	dict.insert("bc");
	dict.insert("aba");
	dict.insert("abc");
	dict.insert("cab");

	//string s = "leetcodeleetabccode";
	string s = "abababcabcab";
	cout << "Target string: " << s << endl;
	cout << "Expect > 0, wordBreak() = " << wordBreak(s, dict) << endl;
	cout << "Expect > 0, wordBreak_iterative() = " << wordBreak_iterative(s, dict) << endl;
	cout << "Expect > 0, wordBreak_iterative2() = " << wordBreak_iterative2(s, dict) << endl;
}
