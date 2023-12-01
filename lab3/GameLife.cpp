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

void Universe::insert(int x, int y) {
	Cell cell(x,y);
	cells.insert(cell);
}

void Console::show(Universe universe) {
	set<Cell> &cells = universe.cells;
	system("cls");
	SetConsoleOutputCP(CP_UTF8);
	for (Cell cell : cells) {
		COORD coord; // Структура для хранения координат
		coord.X = cell.get_x(); // Устанавливаем координату X
		coord.Y = cell.get_y(); // Устанавливаем координату Y
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		//wcout << L"\u25A0";
		wprintf(L"\u25A0");
	}
}