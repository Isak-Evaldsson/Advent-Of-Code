#include "AdventOfCodeRunner.hpp"
#include <iostream>
#include <vector>

/*
    Day 3: Gear Ratios
*/

class Day3 : public AdventOfCodeRunner {
    virtual void task1()
    {
        int sum = 0;

        for (size_t i = 0; i < lines.size(); i++) {
            int num = 0;
            bool found = false;
            char c, prev;
            std::string line = lines[i];

            for (size_t j = 0; j < line.size(); j++) {
                c = line[j];

                if (std::isdigit(c)) {
                    num = num * 10 + (c - '0');
                    if (check_vertical(i, j)) {
                        found = true;
                    }

                    // check before digit and vertical if prev is non-digit
                    if (j > 0 && !std::isdigit(prev)) {
                        if (prev != '.' || check_vertical(i, j - 1)) {
                            found = true;
                        }
                    }
                } else if (!std::isdigit(c) && std::isdigit(prev)) {

                    // check both
                    if (c != '.' || check_vertical(i, j)) {
                        found = true;
                    }

                    if (found) {
                        sum += num;
                    }
                    num = 0;
                    found = false;
                }
                prev = c;
            }

            // handle number at the end of line
            if (found) {
                sum += num;
            }
        }

        std::cout << "task1: " << sum << std::endl;
    }

    virtual void task2()
    {
        int sum = 0;
        std::cout << "task2: " << sum << std::endl;
    }

    virtual int process_input(std::ifstream& file)
    {
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        return 0;
    }

private:
    std::vector<std::string> lines;

    // check if theres a star above and below looking at (i, j)
    bool check_vertical(size_t i, size_t j)
    {
        if (i > 1 && !isdigit(lines[i - 1][j]) && lines[i - 1][j] != '.') {
            return true;
        } else if ((i + 1) < lines.size() && !isdigit(lines[i + 1][j]) && lines[i + 1][j] != '.') {
            return true;
        }
        return false;
    }
};

AOC_MAIN(Day3)
