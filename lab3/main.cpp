#include "GameLife.h"
#include <iostream>
#include <windows.h>
using namespace std;

// поле 0 1 .. 117
//      1 ...
//      ...
//      27

int main(int argc, char* argv[])
{
    if (argc == 6 && strcmp(argv[2], "-i") == 0 && strcmp(argv[4], "-o") == 0) {
        OfflineMode game;
        game.start(argv);
    } else if (argc == 2) {
        OnlineMode game;
        game.start(argv);
    } else {
        cout << "!" << argc << argv[2] << argv[4];
    }

    return EXIT_SUCCESS;
}
