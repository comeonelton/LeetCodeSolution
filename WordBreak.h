/*
 * WordBreak.h
 *
 *  Created on: 2014/5/16
 *      Author: comeonelton
 */

#ifndef WORDBREAK_H_
#define WORDBREAK_H_

#include <iostream>
#include <unordered_set>
#include <vector>

class WordBreak {
public:
	WordBreak();
	virtual ~WordBreak();

	static int wordBreak(std::string s, std::unordered_set<std::string> &dict);
	static int wordBreak_iterative(std::string s, std::unordered_set<std::string> &dict);
	static int wordBreak_iterative2(std::string s, std::unordered_set<std::string> &dict);
	static void dumpWords(const std::vector<std::string> &words);
	static void execute();
};

#endif /* WORDBREAK_H_ */
