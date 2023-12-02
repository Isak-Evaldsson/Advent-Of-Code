#pragma once
#include <string>
#include <vector>

// trim from left
std::string& ltrim(std::string& s, const char* t = " \t\n\r\f\v");

// trim from right
std::string& rtrim(std::string& s, const char* t = " \t\n\r\f\v");

// trim from left & right
std::string& trim(std::string& s, const char* t = " \t\n\r\f\v");

std::vector<std::string> split(const std::string& s, char delim);
