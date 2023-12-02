#include "AdventOfCodeRunner.hpp"
#include <algorithm>
#include <cctype>
#include <cstring>
#include <vector>

/*
    Day 1: Trebuchet?
*/

/* Checks if str begins with word, retuns length of word if true, else 0 */
size_t begins_with(const char* str, const char* word)
{
    size_t len = std::strlen(word);
    return std::strncmp(str, word, len) == 0 ? len : 0;
}

bool non_digit(char a)
{
    return !std::isdigit(a);
}

class Day1 : public AdventOfCodeRunner {
    virtual void task1()
    {
        int sum = 0;

        for (auto line : lines) {
            sum += calibration_value(line);
        }

        std::cout << "task1: " << sum << std::endl;
    }
    virtual void task2()
    {
        int sum = 0;

        for (auto line : lines) {
            size_t len = 0;
            size_t i = 0;
            std::string str;
            const char* c_str = line.c_str();

            while (i < line.size()) {
                /* could be refactored a bit, but it works */
                if ((len = begins_with(c_str + i, "one"))) {
                    str += '1';
                    i += len;
                } else if ((len = begins_with(c_str + i, "two"))) {
                    str += '2';
                    i += len;
                } else if ((len = begins_with(c_str + i, "three"))) {
                    str += '3';
                    i += len;
                } else if ((len = begins_with(c_str + i, "four"))) {
                    str += '4';
                    i += len;
                } else if ((len = begins_with(c_str + i, "five"))) {
                    str += '5';
                    i += len;
                } else if ((len = begins_with(c_str + i, "six"))) {
                    str += '6';
                    i += len;
                } else if ((len = begins_with(c_str + i, "seven"))) {
                    str += '7';
                    i += len;
                } else if ((len = begins_with(c_str + i, "eight"))) {
                    str += '8';
                    i += len;
                } else if ((len = begins_with(c_str + i, "nine"))) {
                    str += '9';
                    i += len;
                } else {
                    str += c_str[i];
                    i++;
                }
            }
            sum += calibration_value(str);
        }
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

    int calibration_value(std::string s)
    {
        s.erase(std::remove_if(s.begin(), s.end(), &non_digit), s.end());
        int front = s.front() - '0';
        int back = s.back() - '0';
        return front * 10 + back;
    }
};

AOC_MAIN(Day1)
