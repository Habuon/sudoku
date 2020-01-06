Sudoku
======

This class is meant to represent one sudoku game

Functionality
-------------

Functionality of the sudoku class is following:

    - sudoku can be loaded from file if the logged in player have saved one
    - sudoku can be saved into file and it can be resumed later

Variables
---------

Sudoku contains 3 important variables :

    - sudoku - sudoku template into which can player add his solution
    - sudoku_solution - it is solved sudoku on which players solution is compared
    - sudoku_template - inside this array there is original sudoku template so the user can not change the original numbers that were given

All of the variables are private so the player should not be able to access them.

Sudoku also have possibility of changing difficulty of the game which affects number of empty fields inside of the sudoku template.

You can add a number into sudoku variable using function add which check your input and if it is correct then it will insert your input into sudoku variable and return true else it returns false.

You can also print the sudoku variable using print function where you have to pass an message which will be printed after the sudoku is printed.

Saving process
--------------

When player decides to save his game he can simply call method save which will save his actual gae into file which name will be <players username>.txt

All 3 important variables will be saved but only sudoku variable will be saved in normal form the rest two will be saved in changed order
so no one should be possible to read the solution from the saved file.
After file is successfully saved the save function will return true and player can either logout or continue playing.


As i mentioned before there is an possibility of saving and loading game but there is also a possibility of removing saved game if the player wish so.