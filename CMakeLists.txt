## Uhliarik

cmake_minimum_required(VERSION 3.6.2)

project(sudoku)

set(CMAKE_CXX_STANDARD 14)

set(TESTING TRUE)

find_package(Threads)

set(SOURCE_FILES
        Objects/Player/Player.cpp
        Objects/Player/Player.h

        Objects/Sudoku/Sudoku.cpp
        Objects/Sudoku/Sudoku.h

        visual/Print.cpp
        visual/Print.h

        Game.cpp
        Game.h)

if (${TESTING})
    set(SOURCE_FILES ${SOURCE_FILES}
            tests/testyPlayer.cpp
            tests/testySudoku.cpp
            tests/testGame.cpp
            tests/testPrint.cpp

            GoogleTest/gtest-death-test.cc
            GoogleTest/gtest-filepath.cc
            GoogleTest/gtest-port.cc
            GoogleTest/gtest-printers.cc
            GoogleTest/gtest-test-part.cc
            GoogleTest/gtest-typed-test.cc
            GoogleTest/gtest.cc
            GoogleTest/gtest_main.cc)
else(${TESTING})
    set(SOURCE_FILES ${SOURCE_FILES}
            main.cpp)

endif()

include_directories(GoogleTest)
add_executable(sudoku ${SOURCE_FILES})
target_link_libraries(sudoku ${CMAKE_THREAD_LIBS_INIT})
