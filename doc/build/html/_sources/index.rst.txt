.. Sudoku documentation master file, created by
   sphinx-quickstart on Tue Dec  3 15:49:10 2019.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Welcome to Sudoku's documentation!
==================================

This Sudoku project is done because of subject Programovanie(3).

To switch between game mode and running test one have to modify CMakeLists.txt.
On the top of the file there is a line that says set(TESTING TRUE). When the variable TESTING is set to TRUE
the sudoku will run all the tests. When the testing is set to FALSE the game will start and prompt user to play.


The Sudoku project contains following classes:
----------------------------------------------

.. toctree::
   :maxdepth: 10

   game.rst
   player.rst
   sudoku.rst
   print1.rst


