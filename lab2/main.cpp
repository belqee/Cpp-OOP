#include <iostream>
#include <string>
#include "bit_array_class.h"

using namespace std;

int main() {
	BitArray a(128,7);
	cout << a.to_string() << endl;
	a >>= 124;
	cout << a.to_string() << endl;
	return EXIT_SUCCESS;
}