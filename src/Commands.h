// Commands.h
// File containing available commands in the tool.

#ifndef _COMMANDS_H_
#define _COMMANDS_H_

#include <string>

// Globals
extern bool _running; // boolean used to exit main loop.

// Function Declarations
bool ParseCommand(std::string cmd);
void PrintHelp(void);

// Classes
//TODO: What does the command class need? A string for the command? A list of
//      strings for additional parameters/arguments? What else? What commands
//      are there? Quit, certainly, which just sets _running to false, and
//      prints out a message.
//Command:

#endif //_COMMANDS_H_
