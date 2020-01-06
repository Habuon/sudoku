#include "Game.h"



void Game::run(bool test) {
    string input;
    string name;
    while(state != 8){
        name = player.get_name();
        if(name == ""){
            name = "host";
        }
        if(test == true){
            error = "Test";
        }
        print(error);
        error = "";
        cout << "# " << name << " --> ";
        if(test == true){
            return;
        }
        getline(cin, input);
        this->operator<<(input);
    }
    if(sudoku.done() == true){
        p.print_finish(player.get_name());
        return;
    }
    if(test == true){
        p.print_finish("Test");
    }
    else{
        p.print_finish("");
    }
}

void Game::set_state(const int s) {
    state = s;
}

bool Game::operator<<(const string &input) {
    if (chceck_input(input)){
        process_input(input);
        return true;
    }
    if(state == 2){
        error = "Player already exists";
        return false;
    }
    if(state == 3){
        error = "Invalid username or password";
        return false;
    }
    error = "Invalid option";
    return false;
}


//////////////////////////////////////////////////////

bool Game::chceck_input(const string &input) {
    switch(state){
        case 0:
        case 1: return input[0] == '1' || input[0] == '2';
        case 2: {
            const string& username = input;
            string pass;
            cout << "Enter your password: " << endl;
            getline(cin, pass);
            return player.sign_in(username, pass);
        }
        case 3: {
            const string& username = input;
            string pass;
            cout << "Enter your password: " << endl;
            getline(cin, pass);
            return player.login(username, pass);
        }
        case 5:
            return input[0] == 'y' || input[0] == 'Y' || input[0] == 'n' || input[0] == 'N';
        case 4:{
            return input[0] - '0' > 0 && input[0] - '0' < 4;
        }
        case 6:
            return true;
    }
    return false;




}

void Game::process_input(const string &input) {
    switch(state){
        case 0: {
            if(input[0] == '1'){
                state = 1;
                return;
            }
            state = 3;
            load = true;
            return;
        };
        case 1: {
            if(input[0] == '1'){
                state = 3;
                return;
            }
            state = 2;
            return;
        };
        case 2:{
            state = 4;
            return;
        }
        case 3: {
            if(load == true){
                state = 5;
                if(sudoku.load(player.get_name()) == false){
                    state = 0;
                    error = "No saved game";
                };
                return;
            }
            state = 4;
            return;
        }
        case 5:{
            if (input[0] == 'y' || input[0] == 'Y' ){
                state = 6;
                return;
            }
            error = "No";
            return;
        }
        case 4:{
           sudoku = Sudoku(input[0] - '0');
           state = 5;
           return;
        }
        case 6:{
            process_sudoku_input(input);
            return;
        }
        case 8:{
            p.print_congratulation(player.get_name());
        }
    }

}


void Game::process_sudoku_input(const string &input) {
    int position = 0;
    string command;
    string rest;

    position = input.find(' ');
    if (position != -1) {
        command = input.substr(0, position);
        rest = input.substr(position, input.size());
    }
    else{
        command = input;
    }

    if(command == "add"){
        if (sudoku.add(rest[1] - '0' - 1,rest[2] - 'a', rest[4] - '0' )){
            if(sudoku.done() ==  true){
                state = 8;
            }
            return;
        }
        error = "Invalid option";
        return;
    }
    if(command == "save"){
        sudoku.save(player.get_name());
        error = "Done";
        return;
    }
    if(command == "exit"){
        state = 8;
        return;
    }
    if(command == "help"){
        state = 5;
        return;
    }
    error = "Unknown command!\nType help to see usage";
}





void Game::print(const string& msg){
    switch(state) {
        case 0: {
            p.print_main_menu(msg);
            return;
        }
        case 1 :{
            p.print_have_account(msg);
            return;
        }
        case 2: {
            p.print_sign_in(msg);
            return;
        }
        case 3:{
            p.print_log_in(msg);
            return;
        }
        case 5:{
            p.print_help(msg);
            return;
        }
        case 4:{
            if(error == "Test"){
                p.print_difficulty(error);
                return;
            }
            p.print_difficulty(player.get_name());
            return;
        }
        case 6:{
            sudoku.print(msg);
            return;
        }

    }
}





