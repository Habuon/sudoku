#include <time.h>
#include <stdlib.h>
#include <fstream>

#include "../settings/settings.h"

using namespace std;

Settings s;

void null_field(int arr[9][9]) {
    for(unsigned int i = 0; i < 9; i++){
        for(unsigned int j = 0; j < 9; j++){
            arr[i][j] = 0;
        }
    }
}

bool is_in(int * arr, int num, int what){
    for(unsigned int i = 0; i < num ; i++){
        if(arr[i] == what){
            return true;
        }
    }
    return false;
}

int * generate_random_range() {
    static int result[10];
    int num = 1;
    int rand_num = 0;
    for(unsigned int i = 0; i < 10; i++){
        result[i] = 0;
    }
    srand((unsigned int)time(NULL));

    while(result[num] == 0 && num < 10){
        rand_num = rand() % 9 + 1;
        if(is_in(result, num, rand_num) == false){
            result[num] = rand_num;
            num++;
        }
    }
    return result;
}

bool compare(int arr1[9][9], int arr2[9][9]){
    for(unsigned int i = 0; i < 9; i++){
        for(unsigned int j = 0; j < 9; j++){
            if(arr1[i][j] != arr2[i][j]){
                return false;
            }
        }
    }
    return true;
}

const char *create_file_name(const string name){
    const string file_name = s.SAVED_PATH + name + ".txt";
    char *result = new char[256];
    for(unsigned int i = 0; i < file_name.size(); i++){
        result[i] = file_name[i];
    }
    result[file_name.size()] = '\0';
    return result;
}
