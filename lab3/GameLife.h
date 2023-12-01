#pragma once
#include <fstream>
#include <set>
#include <iostream>
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
	friend bool operator==(const Cell& a, const Cell& b) {
		return (a.x == b.x) && (a.y == b.y);
	}
	friend bool operator<(const Cell& a, const Cell& b) {
		return (a.y < b.y) || (a.y == b.y && a.x < b.x);
	}
};

class Universe {
private:
	
	int size_x = 100;
	int size_y = 100;
	int birth_rule[9];
	int survive_rule[9];
public:
	set<Cell> cells;
	void insert(int x, int y);
	int get_size_x();
	int get_size_y();
	int calculate_next();
};

class FormatReader {
private:
	int add_cell(string cells_string, Universe universe);
public:
	int analyze_string(string s, Universe universe);
};

class Console {
public:
	void show(Universe universe);
	void change_console_size(Universe universe);
};

class OnlineMode {
private:
	int iterations_count;
	string initial_filename;
	string output_filename;
	void exit();
public:
	
	int start();
};

class OfflineMode {
private:
	int iterations_count;
	string initial_filename;
	string output_filename;
public:
	
	int start();
};
