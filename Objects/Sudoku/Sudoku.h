#ifndef SUDOKU_SUDOKU_H
#define SUDOKU_SUDOKU_H

#include <iostream>
#include "../../visual/Print.h"

using namespace std;

class Sudoku{
    Print p;
    int sudoku[9][9]{};
    int sudoku_template[9][9]{};
    int solved_sudoku[9][9]{};
public:
    Sudoku();
    explicit Sudoku(int diff);
    bool add(int x, int y, int num);
    void print(const string& msg);
    void make(int difficulty);
    bool done();
    bool save(string name);
    bool load(string name);
    static bool remove_saved(string name);
    int **get();

private:
    bool check_all(int x, int y, int num);
    bool check_row(int y, int num);
    bool check_column(int x, int num);
    bool check_square(int x, int y, int num);
    bool generate_sudoku_backtracking(int x, int y);
    void transfer(int pole[9][9]);
    void erase(int difficulty);
    static void load_str_sudoku(string str, int zac, int kon, int pole[9][9]);
    static string get_str_sudoku(int pole[9][9], int zac, int kon);
};

#endif //SUDOKU_SUDOKU_H
