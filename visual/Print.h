#ifndef SUDOKU_PRINT_H
#define SUDOKU_PRINT_H

#include <iostream>


using namespace std;

class Print {
    int cols = 0;
    int rows = 0;

public:
    Print();
    void print_sudoku(int pole[9][9], const string& msg = "");
    void print_main_menu(const string& msg);
    void print_have_account(const string& msg);
    void print_sign_in(const string& msg);
    void print_log_in(const string& msg);
    void print_help(const string& msg);
    void print_congratulation(const string& msg);
    void print_difficulty(const string& msg);
    void print_finish(const string& msg);
private:
    void window_size();
    void clear_screen();

};


#endif //SUDOKU_PRINT_H
