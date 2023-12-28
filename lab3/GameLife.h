#pragma once
#include <cstdlib>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <windows.h>

using namespace std;

class Cell {
private:
    int x;
    int y;

public:
    int get_x();
    int get_y();
    Cell(int x, int y);
    friend bool operator==(const Cell& a, const Cell& b)
    {
        return (a.x == b.x) && (a.y == b.y);
    }
    friend bool operator<(const Cell& a, const Cell& b)
    {
        return (a.y < b.y) || (a.y == b.y && a.x < b.x);
    }
};

class Universe {
private:
    string name = "";
    const int size_x = 118;
    const int size_y = 28;
    set<int> birth_rule = { 3 };
    set<int> survive_rule = { 2, 3 };
    int count_around_alive(int x, int y);

public:
    void set_name(string name);

    set<Cell> cells;
    void insert(int x, int y);
    int get_size_x();
    int get_size_y();
    void calculate_next();
    void set_rules(set<int> B, set<int> S);
};

class FormatReader {
private:
    int add_cell(string cells_string, Universe universe);

public:
    forward_list<string> analyze_file(ifstream& input, Universe& universe);
};

class OnlineMode;

class Console {
public:
    int read_command(OnlineMode& game);
    void clear();
    int show_errors(forward_list<string> errors);
    void show_by_position(Universe universe);
    void show_sync(Universe universe);
};

class OnlineMode {
private:
    Universe universe;
    FormatReader reader;
    Console console;
    int iterations_count = 1;
    string initial_filename;
    string output_filename;

public:
    int start(char* argv[]);
    friend int Console::read_command(OnlineMode& game);
};

class OfflineMode {
private:
    Universe universe;
    FormatReader reader;
    Console console;
    int iterations_count = 1;
    string initial_filename;
    string output_filename;

public:
    int start(char* argv[]);
};
