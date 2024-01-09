#include "AdventOfCodeRunner.hpp"
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

/*
     Day 4: Scratchcards
*/

class Day4 : public AdventOfCodeRunner {
    virtual void task1()
    {
        int points = 0;
        std::cout << "task1: " << points << std::endl;
    }

    virtual void task2()
    {
        std::cout << "task2: Not yet implemented" << std::endl;
    }

    virtual int process_input(std::ifstream& file)
    {
        std::string line;
        while (std::getline(file, line)) {
            // Remove Card XXX: header
            line = line.substr(line.find(":") + 1, line.size());

            std::set<int> w;
            std::string winningNumbers = line.substr(0, line.find("|") - 1);
            std::string yourNumbers = line.substr(line.find("|") + 1, line.size());

            int num;
            std::stringstream stream(winningNumbers);
            while (!stream.eof()) {
                stream >> num;
                w.insert(num);
            }

            stream.str(yourNumbers);
            while (!stream.eof()) {
                stream >> num;
                std::cout << num << ",";
            }
            std::cout << std::endl;
        }
        return 0;
    }
};

AOC_MAIN(Day4)
