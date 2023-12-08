#pragma once
#include <fstream>
#include <set>
#include <iostream>
#include <string>
#include <windows.h>
#include <forward_list>

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
	
	const int size_x = 118;
	const int size_y = 28;
	set<int> birth_rule = { 3,4};
	set<int> survive_rule = { 2,3};
	
public:
	int count_around_alive(int x, int y);
	set<Cell> cells;
	void insert(int x, int y);
	int get_size_x();
	int get_size_y();
	void calculate_next();
};

class FormatReader {
private:
	int add_cell(string cells_string, Universe universe);
public:
	int analyze_string(string s, Universe universe);
};

class Console {
public:
	void show_by_position(Universe universe);
	void show_sync(Universe universe);
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
