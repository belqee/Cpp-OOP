#include "GameLife.h"

Cell::Cell(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Cell::get_x()
{
    return x;
}

int Cell::get_y()
{
    return y;
}

void Universe::set_name(string name)
{
    this->name = name;
}

int Universe::count_around_alive(int x, int y)
{
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i != 0 || j != 0) {
                Cell cell((x + i + size_x) % size_x, (y + j + size_y) % size_y);
                // cout << "\n" << (x + i + size_x) % size_x << "." << (y + j + size_y) % size_y;
                auto it = cells.find(cell);
                if (it != cells.end()) {
                    ++count;
                }
            }
        }
    }
    return count;
}

void Universe::insert(int x, int y)
{
    Cell cell(x % size_x, y % size_y);
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

void Universe::calculate_next()
{
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

void Universe::set_rules(set<int> B, set<int> S)
{
    this->birth_rule = B;
    this->survive_rule = S;
}

int Console::read_command(OnlineMode& game)
{
    string is_dump;
    string filename;
    string is_tick = "";
    string tick = "";
    cin >> is_dump >> filename >> is_tick >> tick;
    if (is_dump == "dump" && filename != "") {
        game.output_filename = filename;
    } else
        return 1;
    if (is_tick == "tick" && tick != "") {
        game.iterations_count = stoi(tick);
    } else
        return 2;
    return 0;
}

void Console::clear()
{
    system("cls");
}

int Console::show_errors(forward_list<string> errors)
{
    for (const auto& error : errors) {
        cout << error << endl;
        if (error == "Critical error: Not enough information for starting") {
            return 1;
        }
    }
    return 0;
}

void Console::show_by_position(Universe universe)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    for (int i = 0; i < 28; ++i) {
        cout << "                                                                                                      "
                "                \n";
    }
    for (Cell cell : universe.cells) {
        coord.X = cell.get_x();
        coord.Y = cell.get_y();
        SetConsoleCursorPosition(hConsole, coord);
        // cout << '#';
        WriteConsoleW(hConsole, L"\u2588", 1, NULL, NULL);
        coord.X = 0;
        coord.Y = 0;
        SetConsoleCursorPosition(hConsole, coord);
    }
}

void Console::show_sync(Universe universe)
{
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

forward_list<string> FormatReader::analyze_file(ifstream& input, Universe& universe)
{
    string line;
    forward_list<string> errors;
    int k = 0;
    while (getline(input, line)) {
        ++k;
        if (k == 1 && line != "#Life 1.06") {
            errors.push_front("First line suggested to be format line of Life 1.06");
        } else if (k == 2) {
            if (line.length() >= 3) {
                if (line[0] != '#' || line[1] != 'N') {
                    errors.push_front("Second line suggested to be unviverse name line or should consist a name");
                } else {
                    if (line[2] != ' ' || line[2] != '\n') {
                        line.erase(0, 3);
                        universe.set_name(line);
                    }
                }
            } else {
                errors.push_front("Second line suggested to be unviverse name, this line is too short");
            }
        } else if (k == 3) {
            set<int> birth_rule;
            set<int> survive_rule;
            size_t found_b = line.find("B");
            size_t found_s = line.find("S");
            if (line.length() <= 3) {
                errors.push_front("Third line suggested to be unviverse name, the setting will be B3/S23");
                birth_rule.insert(3);
                survive_rule.insert(2);
                survive_rule.insert(3);
                goto EndFlag;
            } else if (line[0] != '#' || line[1] != 'R') {
                errors.push_front("Third line suggested to be unviverse name, the setting will be B3/S23");
                birth_rule.insert(3);
                survive_rule.insert(2);
                survive_rule.insert(3);
                goto EndFlag;
            } else if (found_b != string::npos && found_s != string::npos) {
                if (found_s + 1 > line.length() || found_b + 1 > line.length()) {
                    errors.push_front("There isn't enought information, the rules will be standart");
                    birth_rule.insert(3);
                    survive_rule.insert(2);
                    survive_rule.insert(3);
                    goto EndFlag;
                }
                int index = (int)found_b + 1;

                bool repeating_flag = 0;
                while (line[index] != '/' && line[index] != '\n' && line[index] != '\0') {
                    if (line[index] == '1' || line[index] == '2' || line[index] == '3' || line[index] == '4' || line[index] == '5'
                        || line[index] == '6' || line[index] == '7' || line[index] == '8') {
                        auto result = birth_rule.insert((int)(line[index] - '0'));
                        if (!result.second) {
                            repeating_flag = 1;
                        }
                    } else {
                        errors.push_front("There is a rubbish in birth rule");
                        break;
                    }
                    ++index;
                }
                if (index == (int)found_b + 1) {
                    errors.push_front("There isn't enought information, the rules will be standart");
                    birth_rule.insert(3);
                    survive_rule.insert(2);
                    survive_rule.insert(3);
                    goto EndFlag;
                }
                index = (int)found_s + 1;

                while (line[index] != '\n' && line[index] != '\0') {
                    if (line[index] == '1' || line[index] == '2' || line[index] == '3' || line[index] == '4' || line[index] == '5'
                        || line[index] == '6' || line[index] == '7' || line[index] == '8') {
                        auto result = survive_rule.insert((int)(line[index] - '0'));
                        if (!result.second) {
                            repeating_flag = 1;
                        }
                    } else {
                        errors.push_front("There is a rubbish in survive rule");
                        birth_rule.insert(3);
                        survive_rule.insert(2);
                        survive_rule.insert(3);
                        break;
                    }
                    ++index;
                }

                if (repeating_flag == 1) {
                    errors.push_front("There is repeating numbers in birth or survival rule");
                }
            } else {
                cout << "Substring not found" << endl;
            }
        EndFlag:
            universe.set_rules(birth_rule, survive_rule);
        } else if (k >= 4) {
            int x, y;
            std::istringstream iss(line);
            iss >> x >> y;
            universe.insert(x, y);
        }
    }
    if (k < 4) {
        errors.push_front("Critical error: Not enough information for starting");
    }

    return errors;
}

int OfflineMode::start(char* argv[])
{
    ifstream input;
    input.open(argv[1]);
    if (!input.is_open()) {
        cout << "Something went wrong while opening input file" << endl;
        return 1;
    }
    ofstream output;
    output.open(argv[5]);
    if (!output.is_open()) {
        cout << "Something went wrong while opening output file" << endl;
        return 1;
    }
    forward_list<string> errors = reader.analyze_file(input, universe);
    console.clear();
    if (console.show_errors(errors) == 1)
        return 1;
    input.clear();
    input.seekg(0, ios::beg);
    iterations_count = atoi(argv[3]);
    for (int i = 0; i < iterations_count; ++i) {
        universe.calculate_next();
    }
    console.show_sync(universe);

    string line;
    for (int i = 0; i < 3 && getline(input, line); ++i) {
        output << line << endl;
    }
    for (Cell cell : universe.cells) {
        line = "";
        line += to_string(cell.get_x());
        line += ' ';
        line += to_string(cell.get_y());
        output << line << endl;
    }
    cout << "game saved succesfully";
    input.close();
    output.close();
    return 0;
}

int OnlineMode::start(char* argv[])
{
    ifstream input;
    input.open(argv[1]);
    if (!input.is_open()) {
        cout << "Something went wrong while opening input file" << endl;
        return 1;
    }
    forward_list<string> errors = reader.analyze_file(input, universe);
    console.clear();
    if (console.show_errors(errors) == 1)
        return 1;
    input.clear();
    input.seekg(0, ios::beg);
    cout << "Waiting for command: ";
    int flag = console.read_command(*this);
    if (flag != 0) {
        return 1;
    }
    cout << "3 ";
    Sleep(1000);
    cout << "2 ";
    Sleep(1000);
    cout << "1 ";
    Sleep(1000);
    cout << "The game starts";
    Sleep(1000);
    console.clear();
    for (int i = 0; i < iterations_count; ++i) {
        console.show_sync(universe);
        universe.calculate_next();
        Sleep(50);
    }
    ofstream output;
    output.open(output_filename);
    string line;
    for (int i = 0; i < 3 && getline(input, line); ++i) {
        output << line << endl;
    }
    for (Cell cell : universe.cells) {
        line = "";
        line += to_string(cell.get_x());
        line += ' ';
        line += to_string(cell.get_y());
        output << line << endl;
    }
    cout << "game saved succesfully";
    return 0;
}
