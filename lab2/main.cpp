#include <iostream>
#include <string>
#include "bit_array_class.h"

using namespace std;

int main() {
	BitArray a(6,9);
	cout << a.to_string() << endl;
	a >>= 2;
	cout << a.to_string() << endl;
	return EXIT_SUCCESS;
}