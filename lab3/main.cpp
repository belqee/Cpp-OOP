#include "GameLife.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// поле 0 1 .. 117
//      1 ...
//      ...
//      27

int main(int argc, char* argv[])
{
    if (argc < 2) {
        cout << "Not enought parameters, random field will be chosen\n";
        
        srand(static_cast<unsigned int>(time(nullptr)));
        int num = rand() % 4 + 1;
        cout << "Field number " << num << " was chosen\n";
        Sleep(2000);
        char* fake_argv[2];
        fake_argv[0] = argv[0];
        switch (num) {
        case 1:
            fake_argv[1] = "../../../Fields/Field_1.txt";
            break;
        case 2:
            fake_argv[1] = "../../../Fields/Field_2.txt";
            break;
        case 3:
            fake_argv[1] = "../../../Fields/Field_3.txt";
            break;
        case 4:
            fake_argv[1] = "../../../Fields/Field_4.txt";
            break;
        }
        OnlineMode game;
        game.start(fake_argv);
    } else if (argc == 6 && strcmp(argv[2], "-i") == 0 && strcmp(argv[4], "-o") == 0) {
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
