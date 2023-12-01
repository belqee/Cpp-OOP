#include <iostream>
#include "GameLife.h"
#include <windows.h>
using namespace std;

int main() {
    Universe universe;
    universe.insert(0, 0);
    universe.insert(1,1);
    universe.insert(2, 2);
    universe.insert(3, 3);
    Console console;
    console.show(universe);
    universe.insert(3, 4);
    console.show(universe);
	return EXIT_SUCCESS;
}