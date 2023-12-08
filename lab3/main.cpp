#include <iostream>
#include "GameLife.h"
#include <windows.h>
using namespace std;

// поле 0 1 .. 117
//      1 ...
//      ...  
//      27

int main() {
    Universe universe;
    universe.insert(1, 0);
    universe.insert(0, 2);
    universe.insert(1, 2);
    universe.insert(2, 2);
    universe.insert(2, 1);

    universe.insert(20, 5);
    universe.insert(20, 6);
    universe.insert(21, 5);
    universe.insert(21, 6);
    Console console;
    

    for (int i = 0; i < 500; ++i) {
        console.show_sync(universe);
        universe.calculate_next();
        Sleep(50);
        cout << universe.count_around_alive(0,2);
    }

  
  
	return EXIT_SUCCESS;
}