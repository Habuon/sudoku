#include "Sudoku.h"

#include "../../tools/common.cpp"

#include <time.h>
#include <stdlib.h>
#include <cstdio>
#include <utility>
#if defined(_WIN32)
    #include <io.h>
#else
    #include <libnet.h>
#endif


using namespace std;

Sudoku::Sudoku()= default;

Sudoku::Sudoku(int diff){
    make(diff);
}

bool Sudoku::add(int x, int y, int num){
    if(num < 1 || num > 9 ){
        return false;
    }
    if(sudoku_template[x][y] != 0){
        cout << "Invalid template" << endl;
        return false;
    }

    if(check_all(x, y, num)){
        sudoku[x][y] = num;
        return true;
    }
    return false;
}

void Sudoku::make(int difficulty) {
    null_field(sudoku);
    generate_sudoku_backtracking(0,0);
    transfer(solved_sudoku);
    erase(difficulty);
    transfer(sudoku_template);
}

bool Sudoku::done() {
    return compare(sudoku, solved_sudoku);
}

bool Sudoku::save(string name) {
    ofstream file;
    string file_name = create_file_name(std::move(name));

    file.open(file_name);
    if(!file){

        #if defined(_WIN32)
                _mkdir(SAVED_PATH.c_str());
        #else
                mkdir(s.SAVED_PATH.c_str(), 0777);
        #endif

        file.open(file_name);
    }
    file << get_str_sudoku(sudoku,0,9) << endl;
    file << get_str_sudoku(solved_sudoku, 9, 0) << endl;
    file << get_str_sudoku(sudoku_template, 9, 0) << endl;
    file.close();
    return true;
}

bool Sudoku::load(string name) {
    fstream file;
    string str;

    file.open(create_file_name(std::move(name)), ios::in);
    if(!file){
        return false;
    }
    getline(file, str);
    load_str_sudoku(str,0,9, sudoku);
    getline(file, str);
    load_str_sudoku(str, 9, 0, solved_sudoku);
    getline(file, str);
    load_str_sudoku(str, 9, 0, sudoku_template);
    file.close();
    return true;
}

bool Sudoku::remove_saved(string name) {

    const int result = remove(create_file_name(std::move(name)));

    return result == 0;
}

int** Sudoku::get() {
    int** result = nullptr;
    result = new int*[9];

    for (int h = 0; h < 9; h++){
        result[h] = new int[9];

        for (int w = 0; w < 9; w++){
            result[h][w] = sudoku[h][w];
        }
    }

    return result;
}

void Sudoku::print(const string& msg) {
    p.print_sudoku(sudoku, msg);
}

////////////////////////////////////////////////////////////////////////////////

bool Sudoku::check_row(int y, int num) {
    for(auto & i : sudoku){
        if(i[y] == num){
            return false;
        }
    }
    return true;
}

bool Sudoku::check_column(int x, int num){
    for(unsigned int i = 0; i < 9; i++){
        if(sudoku[x][i] == num){
            return false;
        }
    }
    return true;
}

bool Sudoku::check_square(int x, int y, int num) {
    int x_part = x % 3;
    int y_part = y % 3;

    for(unsigned int i = x - x_part; i < x - x_part + 3; i++ ){
        for(unsigned int j = y - y_part; j < y - y_part + 3; j++){
            if(sudoku[i][j] == num){
                return false;
            }
        }

    }
    return true;
}

bool Sudoku::check_all(int x, int y, int num) {
    if(check_row(y, num) == false){
        return false;
    }
    if(check_column(x, num) == false){
        return false;
    }
    if(check_square(x, y, num) == false){
        return false;
    }
    return true;
}

bool Sudoku::generate_sudoku_backtracking(int x, int y) {
    int myX = x;
    int myY = y;
    int *rand_range;
    rand_range = generate_random_range();

    if(myY > 8) {
        myX++;
        myY = 0;
    }
    if(myX > 8) {
        return true;
    }
    for (int num = 1; num <= 9; num++){
        if (check_all(myX, myY, *(rand_range + num))){
            sudoku[myX][myY] = *(rand_range + num);
            if (generate_sudoku_backtracking(myX,myY + 1)) {
                return true;
            }
            sudoku[myX][myY] = 0;
        }
    }
    return false;
}

void Sudoku::transfer(int pole[9][9]){
    for(unsigned int i = 0; i < 9; i++){
        for(unsigned int j = 0; j < 9; j++){
            pole[i][j] = sudoku[i][j];
        }
    }
}
void Sudoku::erase(int difficulty) {
    int x = 0;
    int y = 0;
    int con = 0;
    switch(difficulty){
        case 1:
            con = 32;
            break;
        case 2:
            con = 44;
            break;
        case 3:
            con = 56;
            break;
    }

    srand((unsigned int)time(NULL));

    for(unsigned int i = 0; i < con; i++){
        x = rand() % 9;
        y = rand() % 9;
        while(sudoku[x][y] == 0){
            x = rand() % 9;
            y = rand() % 9;
        }
        sudoku[x][y] = 0;
    }
}

string Sudoku::get_str_sudoku(int pole[9][9], int zac, int kon) {
    string result;
    if(zac < kon) {
        for (unsigned int i = zac; i < kon; i++) {
            for (unsigned int j = zac; j < kon; j++) {
                result += pole[i][j] + '0';
            }
        }
    }
    else{
        for (int i = zac - 1; i > kon - 1; i--) {
            for (int j = zac - 1; j > kon - 1; j--) {
                result += pole[i][j] + '0';
            }
        }
    }
    return result;
}

void Sudoku::load_str_sudoku(string str, int zac, int kon, int pole[9][9]) {
    if(zac < kon) {
        for (unsigned int i = zac; i < kon; i++) {
            for (unsigned int j = zac; j < kon; j++) {
                pole[i][j] = str[i * 9 + j] - '0';
            }
        }
    }
    else{
        for (int i = zac - 1; i > kon - 1; i--) {
            for (int j = zac - 1; j > kon - 1; j--) {
                pole[i][j] = str[(zac - i - 1) * 9 +  zac - j - 1] - '0';
            }
        }
    }


}