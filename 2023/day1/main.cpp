#include "AdventOfCodeRunner.hpp"

class Day1 : public AdventOfCodeRunner {
    virtual void task1()
    {
        std::cout << "task1: here goes nothing or does it??" << std::endl;
    }
    virtual void task2()
    {
        std::cout << "task2: here goes nothing" << std::endl;
    }

    virtual int process_input(std::ifstream& file)
    {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        return 0;
    }
};

AOC_MAIN(Day1)
