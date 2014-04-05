// Commands.cpp
// File containing available commands in the tool.

#include <stdio.h>

#include "Commands.h"
#include "HelperFunctions.h"

// Globals
bool _running = true;

// Function Declarations
void SetRunning(bool running);

// Function Definitions
// ParseCommand: Parse a given string to determine if it contains a command.
bool ParseCommand(std::string cmd)
{
    //TODO: lots of stuff, loop through valid commands and parse the string
    //      to determine if there is a valid command. Support additional
    //      arguments on a command-by-command basis.
    //      List of valid commands should eventually be read in by file.

    //temp
    // Simple implementation of a couple key commands
    if(ToLower(cmd) == "quit")
    {
        OutputText("Quitting...\n");
        SetRunning(false);
        return true;
    }

    return false;
}

//temp
// Want to make this private somehow, probably by implementing it in a
// CommandHandler class of some sort.
void SetRunning(bool running) {_running = running;}
