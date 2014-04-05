// HelperFunctions.h

#ifndef _HELPERFUNCTIONS_H_
#define _HELPERFUNCTIONS_H_

#include <algorithm>
#include <string>

// ToLower: Converts an std::string to lowercase and returns it.
std::string ToLower(std::string str);

// OutputText: Function that prints text to the terminal. Made in preparation
//              for adding logging functionality to messages from the program.
int OutputText(std::string msg);
int OutputText(const char* msg);

#endif //_HELPERFUNCTIONS_H_
