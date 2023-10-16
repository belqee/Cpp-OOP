#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class word_counter_class {
	map<string, int> alf;
public:
	void count_words(istream& in);
	void write_result(ostream& out);
};