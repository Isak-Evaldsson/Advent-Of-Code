#include "AdventOfCodeRunner.hpp"
#include "string_functions.hpp"
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>

/*
    Day 2: Cube Conundrum
*/

class Day2 : public AdventOfCodeRunner {
    virtual void task1()
    {
        int i = 1;
        int sum = 0;

        std::map<std::string, int> limits { { "red", 12 }, { "green", 13 }, { "blue", 14 } };

        for (auto bag : games) {

            bool correct = true;
            for (auto pair : bag) {

                if (pair.second > limits[pair.first]) {
                    correct = false;
                }
            }

            if (correct) {
                sum += i;
            }
            i++;
        }
        std::cout << "task1: " << sum << std::endl;
    }

    virtual void task2()
    {
        int sum = 0;

        for (auto bag : games) {
            // Compte the power with a loop when you can use std algorithm :)
            auto lambda = [](int value, std::map<std::string, int>::value_type& p) { return value * p.second; };
            sum += std::accumulate(std::begin(bag), std::end(bag), 1, lambda);
        }
        std::cout << "task2: " << sum << std::endl;
    }

    virtual int process_input(std::ifstream& file)
    {
        std::string line;
        while (std::getline(file, line)) {
            // Remove "Game xxx: " header
            line = line.substr(line.find(":") + 2, line.size());

            // Replacing ; with , makes parsing easier
            std::replace(line.begin(), line.end(), ';', ',');

            // Count the colored cubes
            std::map<std::string, int> bag { { "red", 0 }, { "green", 0 }, { "blue", 0 } };

            // Create string stream...
            std::string str;
            std::stringstream stream(line);

            // ...and iterate over it
            while (getline(stream, str, ',')) {

                trim(str);
                size_t split = str.find(' ');
                int count = std::atoi(str.substr(0, split).c_str());
                std::string color = str.substr(split + 1, str.length());

                // Update counter if we found a higher number of balls of a particular color
                if (bag[color] < count) {
                    bag[color] = count;
                }
            }
            games.push_back(bag);
        }
        return 0;
    }

private:
    std::vector<std::map<std::string, int>> games;
};

AOC_MAIN(Day2)
