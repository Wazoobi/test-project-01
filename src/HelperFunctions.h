// HelperFunctions.h

#ifndef _HELPERFUNCTIONS_H_
#define _HELPERFUNCTIONS_H_

#include <algorithm>
#include <string>

// Globals
enum MessageType { MSG_ERROR = -1, MSG_TERMINAL_OUTPUT, MSG_PLAYER_INPUT };

//ToLower: Converts an std::string to lowercase and returns it.
std::string ToLower(std::string str);

//GetInput: 
std::string GetInput(bool logging = true);

//OutputText: Function that prints text to the terminal. Made in preparation
//            for adding logging functionality to messages from the program.
int OutputText(std::string msg, int msgType, bool print = true);
int OutputText(const char* msg, int msgType, bool print = true);

#endif //_HELPERFUNCTIONS_H_
