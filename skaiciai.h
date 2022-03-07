#pragma once
#include <iostream>
#include <sstream>
#include <string>
bool isNumber(const std::string& str)
{
    for (char const& c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}
std::string sansas(std::string& nd, int a) {
    if (a % 8 != 0) {
        nd = std::to_string(a % 10 + 1);
    }
    else {
        nd = "oskaras";
    }
    return nd;
}
