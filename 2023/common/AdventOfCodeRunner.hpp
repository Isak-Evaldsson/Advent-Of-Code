#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

/*
    Creates a main method
*/
#define AOC_MAIN(className)                       \
    int main(int argc, char* argv[])              \
    {                                             \
        className classNameInstance;              \
        return classNameInstance.run(argc, argv); \
    }

class AdventOfCodeRunner {

public:
    // Parse arguments and runs appropiate task, returns status code
    int run(int argc, char* argv[]);

    // Specific code for each task
    virtual void task1() = 0;
    virtual void task2() = 0;

private:
    // Shared code for input processing among both task, default implementation does nothing
    virtual int process_input(std::ifstream& file);
};
