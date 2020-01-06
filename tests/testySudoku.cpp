#include <iostream>
#include "../gtest/gtest.h"

using namespace std;

#include "../Objects/Sudoku/Sudoku.h"

using namespace ::testing;

TEST(TestSudoku, NumberOfZerosDifficulty1) {
    Sudoku s (1);
    int num_zeros = 0;
    int **sudoku;

    sudoku = s.get();
    for(unsigned int i = 0; i < 9; i++){
        for(unsigned int j = 0; j < 9; j++){
            if(sudoku[i][j] == 0){
                num_zeros++;
            }
        }
    }
    ASSERT_EQ(32,num_zeros);
}

TEST(TestSudoku, NumberOfZerosDifficulty2) {
    Sudoku s (2);
    int num_zeros = 0;
    int **sudoku;

    sudoku = s.get();
    for(unsigned int i = 0; i < 9; i++){
        for(unsigned int j = 0; j < 9; j++){
            if(sudoku[i][j] == 0){
                num_zeros++;
            }
        }
    }
    ASSERT_EQ(44,num_zeros);
}

TEST(TestSudoku, NumberOfZerosDifficulty3) {
    Sudoku s (3);
    int num_zeros = 0;
    int **sudoku;

    sudoku = s.get();
    for(unsigned int i = 0; i < 9; i++){
        for(unsigned int j = 0; j < 9; j++){
            if(sudoku[i][j] == 0){
                num_zeros++;
            }
        }
    }
    ASSERT_EQ(56,num_zeros);
}

TEST(TestSudoku, Save) {
    Sudoku s (1);

    ASSERT_TRUE(s.save("test"));
}

TEST(TestSudoku, Load) {
    Sudoku s;

    ASSERT_TRUE(s.load("test"));
}

TEST(TestSudoku, RemoveExistingSave) {
    Sudoku s;

    ASSERT_TRUE(s.remove_saved("test"));
}

TEST(TestSudoku, RemoveNotExistingSave) {
    Sudoku s;

    ASSERT_FALSE(s.remove_saved("test"));
}

TEST(TestSudoku, SaveAndLoad) {
    Sudoku s1 (1);
    Sudoku s2;
    int **s1_sudoku;
    int **s2_sudoku;

    s1.save("test");
    s2.load("test");

    s1_sudoku = s1.get();
    s2_sudoku = s2.get();

    for(unsigned int i = 0; i < 9; i++){
        for(unsigned int j = 0; j < 9; j++){
            ASSERT_EQ(s1_sudoku[i][j], s2_sudoku[i][j]);
        }
    }
}
