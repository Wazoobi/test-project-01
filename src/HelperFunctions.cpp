// HelperFunctions.cpp

#include "HelperFunctions.h"

std::string ToLower(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}
