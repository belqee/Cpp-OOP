#include "word_counter.h"
using namespace std;

static bool is_letter(char letter) {
	if (letter < 48 || letter > 122 || (letter < 65 && letter > 57) || (letter > 90 && letter < 97)) {
		return false;
	}
	else {
		return true;
	}
}

static bool compare(pair<string, int>& n1, pair<string, int>& n2) {
	return (bool)(n1.second > n2.second);
}

static int percent(int total, int part) {
	float res = (float)part / (float)total;
	return (int)(res * 100);
}

void word_counter_class::count_words(istream& in) {
	string line;
	string word;
	while (getline(in, line)) {
		for (auto it = line.begin(); it != line.end(); ++it) {
			if (!is_letter(*it)) {
				if (word.length() == 0) { 
					continue;
				}
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
		if (word.length() == 0) {
			continue;
		}
		else if (alf.find(word) == alf.end()) {
			alf[word] = 1;
		}
		else {
			alf[word]++;
		}
		word.clear();
	}
}

void word_counter_class::write_result(ostream& out) {
	vector< pair<string, int> > sorted_arr;
	copy(alf.begin(), alf.end(), back_inserter(sorted_arr));
	sort(sorted_arr.begin(), sorted_arr.end(), compare);

	int all_words_counter = 0;
	for (auto it : sorted_arr) {
		all_words_counter += it.second;
	}

	for (auto it : sorted_arr) {
		out << it.first << ';' << it.second << ';' << percent(all_words_counter, it.second) << '%' << endl;
	}
	alf.clear();
}
