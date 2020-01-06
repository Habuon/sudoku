#ifndef SUDOKU_PLAYER_H
#define SUDOKU_PLAYER_H

#include "../../settings/settings.h"

#include <iostream>
#include <fstream>
#if defined(_WIN32)
    #include <io.h>
#else
    #include <libnet.h>
#endif


using namespace std;

class Player{
    string user_name;
    string password;
    Settings settings;
public:
    Player();
    string get_name();
    bool login(string name, string pass);
    bool logout();
    bool logged_in();
    bool sign_in(string name, string pass);
    bool remove_user(string name, string pass);
private:
    bool check_user(string name, string pass);
    bool user_exists(string name);
    bool write_user(string name, string pass);
    void delete_user(string name);
    string encrypt_password(const string &pass);
    string decrypt_password(const string &encrypted_password);
    string get_password(string name);


};


#endif //SUDOKU_PLAYER_H
