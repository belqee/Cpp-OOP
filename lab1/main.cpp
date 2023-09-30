#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include "word_counter.h"

using namespace std;

int main(int argc, char** argv) {
	if (argc < 3) return -1;
	fstream in, out;
	in.open(argv[1], ios::in);
	out.open(argv[2], ios::out);
	if ((!in.is_open()) || (!out.is_open())) return -1;

	Word_counter counter;
	counter.countWords(in);
	counter.write_result(out);

	in.close();
	out.close();
}