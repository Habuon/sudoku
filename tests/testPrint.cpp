#include <iostream>
#include "../gtest/gtest.h"

using namespace std;

#include "../visual/Print.h"

using namespace ::testing;

TEST(TestPrint,testPrintMainMenu) {
    Print p;
    string msg = "Test";
    string result = "---------------------------------------------\n"
                    "|                 Main Menu                 |\n"
                    "|  1) new game                2) load game  |\n"
                    "---------------------------------------------\n"
                    "Test\n";

    testing::internal::CaptureStdout();
    p.print_main_menu(msg);
    string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(result,output);
}

TEST(TestPrint,testPrintHaveAccount) {
    Print p;
    string msg = "Test";
    string result = "---------------------------------------------\n"
                    "|           Do you have an account?         |\n"
                    "|     1) Yes                      2) No     |\n"
                    "---------------------------------------------\n"
                    "Test\n";

    testing::internal::CaptureStdout();
    p.print_have_account(msg);
    string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(result,output);
}

TEST(TestPrint,testSignIn) {
    Print p;
    string msg = "Test";
    string result = "---------------------------------------------\n"
                    "|              Let's sign in                |\n"
                    "|   Please fill in your name and password   |\n"
                    "---------------------------------------------\n"
                    "Test\n"
                    "Enter your username: \n";

    testing::internal::CaptureStdout();
    p.print_sign_in(msg);
    string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(result,output);
}

TEST(TestPrint,testPrintLogIn) {
    Print p;
    string msg = "Test";
    string result =  "---------------------------------------------\n"
                     "|               Let's log in                |\n"
                     "|   Please fill in your name and password   |\n"
                     "---------------------------------------------\n"
                     "Test\n"
                     "Enter your username: \n";

    testing::internal::CaptureStdout();
    p.print_log_in(msg);
    string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(result,output);
}

TEST(TestPrint,testPrintHelp) {
    Print p;
    string msg = "Test";
    string result = "To add a number into sudoku chart one have to type command: add <row-number><column-letter> <value>\n"
                    "To save an actual sudoku state one have to type command: save\n"
                    "To see the help again one have to type command: help\n"
                    "To quit the game simply type exit\n"
                    "Do you understand it? Y/N\n";
    testing::internal::CaptureStdout();
    p.print_help(msg);
    string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(result,output);
}

TEST(TestPrint,testPrintHelpNo) {
    Print p;
    string msg = "TestNo";
    string result = "To add a number into sudoku chart one have to type command: add <row-number><column-letter> <value>\n"
                    "To save an actual sudoku state one have to type command: save\n"
                    "To see the help again one have to type command: help\n"
                    "To quit the game simply type exit\n"
                    "How can you not understand it? Come on it could not be easier ...\n"
                    "I ask once again do you understand it? Y/N\n";

    testing::internal::CaptureStdout();
    p.print_help(msg);
    string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(result,output);
}

TEST(TestPrint,testPrintDifficulty) {
    Print p;
    string msg = "Test";
    string result = "Hello Test,\n"
                    "What difficulty would you like to try?\n"
                    "1 - easy / 2 - medium / 3 - hard\n";

    testing::internal::CaptureStdout();
    p.print_difficulty(msg);
    string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(result,output);
}

TEST(TestPrint,testPrintCongratulation) {
    Print p;
    string msg = "Test";
    string result = "---------------------------------------------\n"
                    "|                 Well done                 |\n"
                    "|       I am really proud of you Test       |\n"
                    "---------------------------------------------\n";

    testing::internal::CaptureStdout();
    p.print_congratulation(msg);
    string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(result,output);
}

TEST(TestPrint,testPrintFinish) {
    Print p;
    string msg = "Test";
    string result = "Thanks for playing. Hope you liked the game, check out my git for more content: https://github.com/Habuon\n";

    testing::internal::CaptureStdout();
    p.print_finish(msg);
    string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(result,output);
}
