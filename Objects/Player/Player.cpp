#include "Player.h"

#include "../../tools/checking.cpp"


Player::Player() {
    user_name = "";
    password = "";

}

string Player::get_name() {
    return user_name;
}

bool Player::login(string name, string pass) {
    if(check_user(name, pass) == true){
        user_name = name;
        password = pass;
        return true;
    }
    return false;
}

bool Player::logout() {
    if(user_name == ""){
        return false;
    }
    user_name = "";
    password = "";
    return true;

}

bool Player::logged_in() {
    return user_name != "";
}

bool Player::sign_in(string name, string pass) {
    if(pass == "" || name == ""){
        return false;
    }
    if(user_exists(name) == true){
        cout << "User already exists" << endl;
        return false;
    }
    write_user(name, pass);
    login(name, pass);
    return true;
}
bool Player::remove_user(string name, string pass){
    if(check_user(name, pass) == true){
        delete_user(name);
        logout();
        return true;
    }
    return false;
}

/////////////////////////////////////////////////////////////////////////

bool Player::write_user(string name, string pass) {
    fstream file;

    string res[256];
    string s = "";
    int i = 0;

    file.open(settings.USERS_PATH + settings.USERS_FILENAME, ios::in);
    if(file){
        while(file.eof() == false){
            getline(file, s);
            res[i] = s;
            i++;
        }
        file.close();
    }

    res[i] = name;
    i++;
    pass = encrypt_password(pass);
    res[i] = pass;
    i++;

    file.open(settings.USERS_PATH + settings.USERS_FILENAME,ios::out);
    if(!file){
        #if defined(_WIN32)
                _mkdir(settings.USERS_PATH.c_str());
        #else
                mkdir(settings.USERS_PATH.c_str(), 0777);
        #endif
        file.open(settings.USERS_PATH + settings.USERS_FILENAME,ios::out);
    }
    for(unsigned int j = 0; j < i; j++){
        file << res[j];
        file << '\n';
    }
    file.close();
    return true;
}

bool Player::check_user(string name, string pass) {
    if(user_exists(name) == false){
        cout << "User does not exists" << endl;
        return false;
    }
    string p = "";

    p = get_password(name);
    p = decrypt_password(p);
    if(p == pass){
        return true;
    }
    cout << "Invalid password" << endl;
    return false;
}

bool Player::user_exists(string name){
    string p = "";

    p = get_password(name);
    if(p == ""){
        return false;
    }
    return true;
}

string Player::get_password(string name) {
    fstream file;
    string s = "";

    file.open(settings.USERS_PATH + settings.USERS_FILENAME,ios::in);
    if(!file){
        #if defined(_WIN32)
                _mkdir(settings.USERS_PATH.c_str());
        #else
                mkdir(settings.USERS_PATH.c_str(), 0777);
        #endif
        file.open(settings.USERS_PATH + settings.USERS_FILENAME,ios::in);
    }
    if(!file){
        return s;
    }

    while(file.eof() == false){
        getline(file, s);
        if(s == name){
            getline(file, s);
            file.close();
            return s;
        }
    }
    file.close();
    return "";
}


string Player::encrypt_password(const string &pass) {
    int cislo = 1;
    if(pass == " "){
        return pass;
    }
    string p = pass;

    for(int i = 0; i < pass.size(); i++) {
        if (is_letter(p[i])) {
            if ('z' - p[i] < cislo && !is_capital_letter(p[i])) {
                p[i] = 'a' + cislo - ('z' - p[i]) - 1;
            } else {
                if ('Z' - p[i] < cislo && is_capital_letter(p[i])) {
                    p[i] = 'A' + cislo - ('Z' - p[i]) - 1;
                } else {
                    p[i] += cislo;
                }
            }
        }
        cislo += 1;
        if (cislo > 6) {
            cislo = 1;
        }
    }
    return p;
}

string Player::decrypt_password(const string &encrypted_password) {
    string pass = encrypted_password;
    int cislo = 1;

    if(pass == " "){
        return pass;
    }
    for(int i = 0; i < encrypted_password.size(); i++) {
        if (is_letter(pass[i])) {
            if (pass[i] - 'a' < cislo && !is_capital_letter(pass[i])) {
                pass[i] = 'z' - cislo + (pass[i] - 'a') + 1;
            } else {
                if (pass[i] - 'A' < cislo && is_capital_letter(pass[i])) {
                    pass[i] = 'Z' - cislo + (pass[i] - 'A') + 1;
                } else {
                    pass[i] -= cislo;
                }
            }
        }
        cislo += 1;
        if (cislo > 6) {
            cislo = 1;
        }
    }
    return pass;
}

void Player::delete_user(string name) {
    fstream file;

    string res[256];
    string s = "";
    int i = 0;

    file.open(settings.USERS_PATH + settings.USERS_FILENAME,ios::in);
    if(file){
        while(file.eof() == false){
            getline(file, s);
            if(s == name){
                getline(file, s); // get password
                continue;
            }
            res[i] = s;
            i++;
        }
        file.close();
    }
    file.open(settings.USERS_PATH + settings.USERS_FILENAME,ios::out);
    if(!file){
        #if defined(_WIN32)
                _mkdir(settings.USERS_PATH.c_str());
        #else
                mkdir(settings.USERS_PATH.c_str(), 0777);
        #endif
        file.open(settings.USERS_PATH + settings.USERS_FILENAME,ios::out);
    }
    for(unsigned int j = 0; j < i; j++){
        file << res[j];
        file << '\n';
    }
    file.close();
}