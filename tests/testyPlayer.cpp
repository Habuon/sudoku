#include <iostream>
#include "../gtest/gtest.h"

using namespace std;

#include "../Objects/Player/Player.h"

using namespace ::testing;

TEST(TestPlayer, NoName) {
    Player p;
    ASSERT_EQ("", p.get_name());
}

TEST(TestPlayer, SignIn) {
    Player p;
    string user_name = "Test";
    string pass = "test";

    ASSERT_TRUE(p.sign_in(user_name,pass));
}

TEST(TestPlayer, SignInWithoutUserName) {
    Player p;
    string user_name = "";
    string pass = "test";

    ASSERT_FALSE(p.sign_in(user_name,pass));
}

TEST(TestPlayer, SignInWithoutPassword) {
    Player p;
    string user_name = "Test";
    string pass = "";

    ASSERT_FALSE(p.sign_in(user_name,pass));
}


TEST(TestPlayer, SignInWithSameName) {
    Player p;
    string user_name = "Test";
    string pass = "test";

    ASSERT_FALSE(p.sign_in(user_name,pass));
}

TEST(TestPlayer, LogInNull) {
    Player p;
    string user_name = "";
    string pass = "";

    ASSERT_FALSE(p.login(user_name,pass));
}

TEST(TestPlayer, LogIn) {
    Player p;
    string user_name = "Test";
    string pass = "test";

    ASSERT_TRUE(p.login(user_name,pass));
}

TEST(TestPlayer, LogInWithWrongUserName) {
    Player p;
    string user_name = "Test1";
    string pass = "test";

    ASSERT_FALSE(p.login(user_name,pass));
}

TEST(TestPlayer, LogInWithWrongPass) {
    Player p;
    string user_name = "Test";
    string pass = "test1";

    ASSERT_FALSE(p.login(user_name,pass));
}

TEST(TestPlayer, LoggedIn) {
    Player p;
    string user_name = "Test";
    string pass = "test";

    p.login(user_name, pass);

    ASSERT_TRUE(p.logged_in());
    ASSERT_EQ(user_name, p.get_name());
}
TEST(TestPlayer, LogOut) {
    Player p;
    string user_name = "Test";
    string pass = "test";

    p.login(user_name, pass);

    ASSERT_TRUE(p.logout());
    ASSERT_EQ("", p.get_name());
}

TEST(TestPlayer, LogOutWithoutLoggedIn) {
    Player p;

    ASSERT_FALSE(p.logout());
}

TEST(TestPlayer, RemoveUserWithWrongPassword) {
    Player p;
    string user_name = "Test";
    string pass = "test1";

    ASSERT_FALSE(p.remove_user(user_name,pass));
}

TEST(TestPlayer, RemoveFromMultipleUsers) {
    Player p;
    string user_name1 = "Test";
    string pass1 = "test";
    string user_name2 = "Test1";
    string pass2 = "test";

    p.sign_in(user_name2, pass2);
    ASSERT_TRUE(p.remove_user(user_name2,pass2));
    ASSERT_TRUE(p.login(user_name1, pass1));
}

TEST(TestPlayer, Remove) {
    Player p;
    string user_name = "Test";
    string pass = "test";

    p.remove_user(user_name,pass);
    ASSERT_FALSE(p.login(user_name, pass));
    ASSERT_EQ("", p.get_name());
}

TEST(TestPlayer, RemoveNonExistingUser) {
    Player p;
    string user_name = "Test";
    string pass = "test";

    ASSERT_FALSE(p.remove_user(user_name,pass));
}
