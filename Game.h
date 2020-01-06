#ifndef SUDOKU_GAME_H
#define SUDOKU_GAME_H

#include "./Objects/Player/Player.h"
#include "./Objects/Sudoku/Sudoku.h"
#include "visual/Print.h"

class Game {
    Print p;
    Player player;
    Sudoku sudoku;
    int state = 0;
    string error;
    bool load = false;
public:
    bool operator<<(const string &input);
    void run(bool test = false);
    void set_state(const int s);
    void set_sudoku(Sudoku s){sudoku = s;};
private:
    bool chceck_input(const string &input);
    void process_input(const string &input);
    void print(const string& msg);
    void process_sudoku_input(const string &input);

};


#endif //SUDOKU_GAME_H
