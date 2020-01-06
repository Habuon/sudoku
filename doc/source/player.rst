Player
======

This class is meant to represent one player


Functionality
-------------

Functionality of the player class is following:

    - player can log in or sign in if he does not have an acount
    - player can log out if he finished game or if he does not need to be logged in anymore for whatever reason
    - player can save his actual game under his username and load it later

You can simply get information whether player is logged in or not by calling a logged_in function and the you can also get username of logged player.

If you know users username and password you can also remove specific user by calling function remove_user and providing correct credentials.

Sign in process
---------------
When player chooses to sign in he is prompted to provide his username and after that his password. When the username provided by user already exists
user is told so and asked for another username.

When player provides valid username and password these are saved into file users.txt. Before the password is saved it is hashed with specific
algorithm so only a program can decode it.

After successful sing in the player is forwarded to the next step in game and he is also automatically logged in with his new account.

