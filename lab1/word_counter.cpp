#include "word_counter.h"

using namespace std;

static bool isNumbOrLetter(char Char) {
	if (Char > 122 || Char < 48 ||
		(Char > 57 && Char < 65) ||
		(Char > 90 && Char < 97)) {
		return false;
	}
	else {
		return true;
	}
}

static bool compare(pair<string, int> n1, pair<string, int> n2) {
	return n1.second > n2.second ? true : false;
}

static int percent(int total, int part) {
	float res = (float)part / (float)total;
	return (int)(res * 100);
}

void Word_counter::countWords(istream& in) {
	string line;
	string word;
	while (getline(in, line)) {
		for (auto it = line.begin(); it != line.end(); ++it) {
			if (!isNumbOrLetter(*it)) {
				if (word.length() == 0) { continue; }
				if (alf.find(word) == alf.end()) {
					alf[word] = 1;
				}
				else {
					alf[word]++;
				}
				word.clear();
			}
			else {
				word.push_back(*it);
			}
		}
		if (word.length() == 0) { continue; }
		else if (alf.find(word) == alf.end()) {
			alf[word] = 1;
		}
		else {
			alf[word]++;
		}
		word.clear();
	}
}

void Word_counter::write_result(ostream& out) {
	vector< pair<string, int> > sorted_arr;
	copy(alf.begin(), alf.end(), back_inserter(sorted_arr));
	sort(sorted_arr.begin(), sorted_arr.end(), compare);

	int totalCountWords = 0;
	for (auto it : sorted_arr) {
		totalCountWords += it.second;
	}

	for (auto it : sorted_arr) {
		out << it.first << ';' << it.second << ';' << percent(totalCountWords, it.second) << '%' << endl;
	}
}

void Word_counter::clear() {
	alf.clear();
}