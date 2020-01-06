#include "Print.h"
#include "../gtest/gtest.h"


#include <iostream>
#if defined(_WIN32)
    #include <windows.h>
#else
    #include <sys/ioctl.h>
    #include <unistd.h>
#endif


using namespace std;

Print::Print(){
    window_size();
}

void Print::window_size(){
    #if defined(_WIN32)
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        int c, r;

        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        c = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        r = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
        cols = c / 5;
        rows = r;
    #else
        struct winsize size;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
        cols = size.ws_col / 5;
        rows = size.ws_row + 2;
    #endif
}

void Print::clear_screen() {
    for(unsigned int i = 0; i < rows * 10; i++){
        cout << '\n' << '\n' << '\n' << endl;
    }
}


void Print::print_sudoku(int pole[9][9], const string& msg){
    clear_screen();
    cout << "      a   b   c   d   e   f   g   h   i  " << endl;
    cout << "    -------------------------------------" << endl;
    for(unsigned int i = 0; i < 9; i++){
        cout << i + 1 << "   |";
        for(unsigned int j = 0; j < 9; j++){
            if(pole[i][j] == 0){
                cout << "   |";
            }
            else{
                cout << ' ' <<  pole[i][j] << ' ' << '|';
            }
        }
        cout << endl;
        cout << "    -------------------------------------" << endl;
    }
    cout << msg << endl;
}

void Print::print_main_menu(const string& msg) {
    if(msg != "Test"){
        clear_screen();
    }
    cout << "---------------------------------------------" << endl;
    cout << "|                 Main Menu                 |" << endl;
    cout << "|  1) new game                2) load game  |" << endl;
    cout << "---------------------------------------------" << endl;
    cout << msg << endl;
}

void Print::print_have_account(const string& msg) {
    if(msg != "Test"){
        clear_screen();
    }
    cout << "---------------------------------------------" << endl;
    cout << "|           Do you have an account?         |" << endl;
    cout << "|     1) Yes                      2) No     |" << endl;
    cout << "---------------------------------------------" << endl;
    cout << msg << endl;
}

void Print::print_sign_in(const string& msg){
    if(msg != "Test"){
        clear_screen();
    }
    cout << "---------------------------------------------" << endl;
    cout << "|              Let's sign in                |" << endl;
    cout << "|   Please fill in your name and password   |" << endl;
    cout << "---------------------------------------------" << endl;
    cout << msg << endl;
    cout << "Enter your username: " << endl;
}

void Print::print_log_in(const string& msg){
    if(msg != "Test"){
        clear_screen();
    }
    cout << "---------------------------------------------" << endl;
    cout << "|               Let's log in                |" << endl;
    cout << "|   Please fill in your name and password   |" << endl;
    cout << "---------------------------------------------" << endl;
    cout << msg << endl;
    cout << "Enter your username: " << endl;
}

void Print::print_help(const string& msg) {
    if(msg != "Test" && msg != "TestNo"){
        clear_screen();
    }
    cout << "To add a number into sudoku chart one have to type command: add <row-number><column-letter> <value>"<< endl;
    cout << "To save an actual sudoku state one have to type command: save"<< endl;
    cout << "To see the help again one have to type command: help"<< endl;
    cout << "To quit the game simply type exit"<< endl;
    if(msg == "No" || msg == "TestNo"){
        cout << "How can you not understand it? Come on it could not be easier ..." << endl;
        cout << "I ask once again do you understand it? Y/N" << endl;
        return;
    }
    cout << "Do you understand it? Y/N" << endl;
}

void Print::print_difficulty(const std::string & msg) {
    if(msg != "Test"){
        clear_screen();
    }
    cout << "Hello " << msg << "," << endl;
    cout << "What difficulty would you like to try?" << endl;
    cout << "1 - easy / 2 - medium / 3 - hard" << endl;
}

void Print::print_congratulation(const std::string& msg) {
    string m = "I am really proud of you " + msg;
    int num = (45 - m.length() - 2) / 2;
    int i = 0;
    if(m.length() + 2 + 2 * num < 45){
        i = 1;
    }
    if(msg != "Test"){
        clear_screen();
    }
    cout << "---------------------------------------------" << endl;
    cout << "|                 Well done                 |" << endl;
    cout << "|" << string(num + i , ' ' ) << "I am really proud of you " << msg << string(num, ' ' ) << "|" << endl;
    cout << "---------------------------------------------" << endl;
}

void Print::print_finish(const string& msg) {
    if(msg != "Test"){
        clear_screen();
    }
    if (msg != "" && msg != "Test"){
        print_congratulation(msg);
    }
    cout << "Thanks for playing. Hope you liked the game, check out my git for more content: https://github.com/Habuon" << endl;
}