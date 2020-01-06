#include "../Game.h"
#include <iostream>
#include "../gtest/gtest.h"

using namespace std;

using namespace ::testing;

TEST(TestGame, testMainMenu) {
    Game g;
    g.set_state(0);
    string msg = "Test";
    string result = "---------------------------------------------\n"
                    "|                 Main Menu                 |\n"
                    "|  1) new game                2) load game  |\n"
                    "---------------------------------------------\n"
                    "Test\n"
                    "# host --> ";

    testing::internal::CaptureStdout();
    g.run(true);
    string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(result,output);

}

TEST(TestGame, testHaveAccount) {
    Game g;
    g.set_state(1);
    string msg = "Test";
    string result = "---------------------------------------------\n"
                    "|           Do you have an account?         |\n"
                    "|     1) Yes                      2) No     |\n"
                    "---------------------------------------------\n"
                    "Test\n"
                    "# host --> ";

    testing::internal::CaptureStdout();
    g.run(true);
    string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(result,output);
}

TEST(TestGame, testDoNotHaveAccount) {
    Game g;
    g.set_state(2);
    string msg = "Test";
    string result = "---------------------------------------------\n"
                    "|              Let's sign in                |\n"
                    "|   Please fill in your name and password   |\n"
                    "---------------------------------------------\n"
                    "Test\n"
                    "Enter your username: \n"
                    "# host --> ";

    testing::internal::CaptureStdout();
    g.run(true);
    string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(result,output);

}

TEST(TestGame, testDoHaveAccount) {
    Game g;
    g.set_state(3);
    string msg = "Test";
    string result =  "---------------------------------------------\n"
                     "|               Let's log in                |\n"
                     "|   Please fill in your name and password   |\n"
                     "---------------------------------------------\n"
                     "Test\n"
                     "Enter your username: \n"
                    "# host --> ";

    testing::internal::CaptureStdout();
    g.run(true);
    string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(result,output);
}

TEST(TestGame, testDifficulty) {
    Game g;
    g.set_state(4);
    string msg = "Test";
    string result = "Hello Test,\n"
                    "What difficulty would you like to try?\n"
                    "1 - easy / 2 - medium / 3 - hard\n"
                     "# host --> ";

    testing::internal::CaptureStdout();
    g.run(true);
    string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(result,output);
}

TEST(TestGame, testHelp){
    Game g;
    g.set_state(5);
    string msg = "Test";
    string result = "To add a number into sudoku chart one have to type command: add <row-number><column-letter> <value>\n"
                    "To save an actual sudoku state one have to type command: save\n"
                    "To see the help again one have to type command: help\n"
                    "To quit the game simply type exit\n"
                    "Do you understand it? Y/N\n"
                    "# host --> ";

    testing::internal::CaptureStdout();
    g.run(true);
    string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(result,output);
}

TEST(TestGame, testSudokuPrint){
    Game g;
    g.set_state(6);
    Sudoku s;
    s.make(1);
    g.set_sudoku(s);
    string msg = "Test";

    testing::internal::CaptureStdout();
    s.print(msg);
    string result = testing::internal::GetCapturedStdout();
    result += "# host --> ";

    testing::internal::CaptureStdout();
    g.run(true);
    string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(result,output);
}

TEST(TestGame, testEnd){
    Game g;
    g.set_state(8);
    Sudoku s;
    s.make(1);
    g.set_sudoku(s);

    string result = "Thanks for playing. Hope you liked the game, check out my git for more content: https://github.com/Habuon\n";

    testing::internal::CaptureStdout();
    g.run(true);
    string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(result,output);
}