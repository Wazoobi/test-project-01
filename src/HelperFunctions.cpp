// HelperFunctions.cpp

#include <iostream>
#include <stdio.h>
#include <string.h>

#include "HelperFunctions.h"
#include "FileIO.h"

//ToLower:
std::string ToLower(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

//GetInput: Get user input from the terminal. Also supports logging of
//          player input.
std::string GetInput(bool logging)
{
    std::string input;
    getline(std::cin, input);
    
    OutputText(input, MSG_PLAYER_INPUT, false);

    return input;
}

//OutputText: Function that prints text to the terminal. Made in preparation
//            for adding logging functionality to messages from the program.
int OutputText(std::string msg, int msgType, bool print)
{
    //TODO: Add error checking on msg.
    
    // Check if print enabled before calling printf(). This enables OutputText
    // to be used solely for logging.
    if(print)
        printf(msg.c_str());
    
    //TODO: Add functionality for saving msg to .log file.
    switch(msgType)
    {
        case MSG_ERROR:
        //TODO: Log as error.
        break;
        
        case MSG_TERMINAL_OUTPUT:
        //TODO: Check if set to logging Terminal Output then log as Terminal Output if set.
        break;
        
        case MSG_PLAYER_INPUT:
        //TODO: Check if set to logging Player INput then log as Player Input if set.
        break;
        
        default:
        //TODO: Error checking, not given a valid message type.
        break;
    }
    void *data = &msg;
    Write("logs/log", data);
    
    return 0;
}
int OutputText(const char* msg, int msgType, bool print)
{
    //TODO: Add error checking on msg.
    
    if(print)
        printf(msg);
    
    //TODO: Add functionality for saving msg to .log file.
    switch(msgType)
    {
        case MSG_ERROR:
        //TODO: Log as error.
        break;
        
        case MSG_TERMINAL_OUTPUT:
        //TODO: Check if set to logging Terminal Output then log as Terminal Output if set.
        break;
        
        case MSG_PLAYER_INPUT:
        //TODO: Check if set to logging Player INput then log as Player Input if set.
        break;
        
        default:
        //TODO: Error checking, not given a valid message type.
        break;
    }
    std::string str = msg;
    void *data = &str;
    Write("logs/log", data);
    
    return 0;
}
