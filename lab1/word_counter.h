#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Word_counter {
	map<string, int> alf;
public:
	void countWords(istream& in);
	void write_result(ostream& out);
	void clear();
};