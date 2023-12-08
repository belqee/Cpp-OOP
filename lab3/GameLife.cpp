#include "GameLife.h"

Cell::Cell(int x, int y) {
	this->x = x;
	this->y = y;
}

int Cell::get_x() {
	return x;
}

int Cell::get_y() {
	return y;
}

int Universe::count_around_alive(int x, int y){
	int count = 0;
	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {
			if (i != 0 || j != 0) {
				Cell cell((x + i + size_x) % size_x, (y + j + size_y) % size_y);
				//cout << "\n" << (x + i + size_x) % size_x << "." << (y + j + size_y) % size_y;
				auto it = cells.find(cell);
				if (it != cells.end()) {
					++count;
				}
			}
		}
	}
	return count;
}

void Universe::insert(int x, int y) {
	Cell cell(x % size_x,y % size_y);
	cells.insert(cell);
}

int Universe::get_size_x()
{
	return size_x;
}

int Universe::get_size_y()
{
	return size_y;
}

void Universe::calculate_next(){
	set<Cell> new_cells;
	for (Cell cell : cells) {
		auto it1 = survive_rule.find(count_around_alive(cell.get_x(), cell.get_y()));
		if (it1 != survive_rule.end()) {
			new_cells.insert(cell);
		}

		for (int i = -1; i <= 1; ++i) {
			for (int j = -1; j <= 1; ++j) {
				if (i != 0 || j != 0) {
					Cell cell2((cell.get_x() + i + size_x) % size_x, (cell.get_y() + j + size_y) % size_y);
					auto it2 = cells.find(cell2);
					if (it2 == cells.end()) {
						auto it3 = birth_rule.find(count_around_alive(cell2.get_x(), cell2.get_y()));
						if (it3 != birth_rule.end()) {
							new_cells.insert(cell2);
						}
					}
				}
			}
		}
	}
	cells = new_cells;
}

void Console::show_by_position(Universe universe) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	for (int i = 0; i < 28; ++i) {
		//cout << "......................................................................................................................\n";
		cout << "                                                                                                                      \n";
	}
	for (Cell cell : universe.cells) {
		coord.X = cell.get_x();
		coord.Y = cell.get_y();
		SetConsoleCursorPosition(hConsole, coord);
		//cout << '#';
		WriteConsoleW(hConsole, L"\u2588", 1, NULL, NULL);
		coord.X = 0;
		coord.Y = 0;
		SetConsoleCursorPosition(hConsole, coord);
	}
}

void Console::show_sync(Universe universe) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = 0;
	coord.Y = 0;
	string output = "";
	for (int i = 0; i < universe.get_size_y(); ++i) {
		for (int j = 0; j < universe.get_size_x(); ++j) {
			output += ' ';
		}
		output += '\n';
	}
	
	for (Cell cell : universe.cells) {
		int index = cell.get_y() * (universe.get_size_x() + 1) + cell.get_x();
		output[index] = 219;
	}
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	cout << output;
}