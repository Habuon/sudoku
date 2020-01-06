#include <iostream>

using namespace std;


bool is_digit(char character) {
    if (character >= '0' && character <= '9' ){
        return true;
    }
    return false;
}

bool is_letter(char character) {
    if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z')){
        return true;
    }
    return false;
}

bool is_capital_letter(char character) {
    if (character >= 'A' && character <= 'Z') {
        return true;
    }
    return false;
}

bool not_allowed_char(char character) {
    switch(character) {
        case ' ':
        case '\0':
        case '\n':
        case '\t':
        case '\r':
        case '\"':
        case '\'':
        case '\\':
            return true;
        default:
            return false;
    }
}

bool other_char(char character) {
    if (is_digit(character) || is_letter(character) || not_allowed_char(character)){
        return false;
    }
    return true;
}

int number_of_characters(const string &letters) {
    return letters.size();

}

int number_of_digits(const string &letters) {
    int num = 0;
    for(int i = 0; i < letters.size(); i++){
        if(is_digit(letters[i])) {
            num++;
        }
    }
    return num;
}

int number_of_capital_letters(const string &letters) {
    int num = 0;
    for(int i = 0; i < letters.size(); i++){
        if(is_capital_letter(letters[i])) {
            num++;
        }
    }
    return num;
}

int number_of_all_letters(const string &letters) {
    int num = 0;
    for(int i = 0; i < letters.size(); i++){
        if(is_letter(letters[i])) {
            num++;
        }
    }
    return num;
}

bool not_allowed_character(const string &letters) {
    int num = 0;
    for(int i = 0; i < letters.size(); i++){
        if(not_allowed_char(letters[i])) {
            num++;
        }
    }
    return num;
}

int number_of_other_characters(const string &letters){
    int num = 0;
    for(int i = 0; i < letters.size(); i++){
        if(other_char(letters[i])) {
            num++;
        }
    }
    return num;
}

//
// Created by danci on 03/11/2019.
//
