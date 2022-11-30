#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string>

#define LOG_SIZE 5
using namespace std;

int main()
{
    list<string> list1;
    list<string *> list2;
    string oxygen;
    string co2;
    int ones = 0;

    // Creating our data
    for (string line; getline(cin, line);)
    {
        list1.push_back(line);
        list2.push_back((new string(line)));
    }

    // Computing oxygen
    for (int i = 0; i < LOG_SIZE; ++i)
    {
        ones = 0;

        for (string s : list1)
        {
            if (s[i] == '1')
                ones++;
        }
        char common_bit = (ones >= list1.size() - ones) ? '1' : '0';

        for (auto iter = list1.begin(); iter != list1.end();)
        {
            if (iter->at(i) != common_bit)
            {
                list1.erase(iter++);
            }
            else
            {
                ++iter;
            }
        }
    }

    // Computing co2
    for (int i = 0; i < LOG_SIZE; ++i)
    {
        ones = 0;

        for (string *s : list2)
        {
            if (s->at(i) == '1')
                ones++;
        }
        char common_bit = (list2.size() - ones >= ones) ? '1' : '0';

        for (auto iter = list2.begin(); iter != list2.end();)
        {
            auto val = **iter;
            if ((**iter)[i] != common_bit)
            {
                delete *iter;
                list2.erase(iter++);
            }
            else
            {
                ++iter;
            }
        }
    }

    oxygen = list1.front();
    co2 = *list2.front();
    cout << "Result: " << stoi(oxygen, 0, 2) * stoi(co2, 0, 2) << endl;
    return 0;
}