// HelperFunctions.cpp

#include <stdio.h>
#include <string.h>

#include "HelperFunctions.h"
#include "FileIO.h"

std::string ToLower(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int OutputText(std::string msg)
{
    //TODO: Add error checking on msg.
    
    printf(msg.c_str());
    
    //TODO: Add functionality for saving msg to .log file.
    void *data = &msg;
    Write("logs/log", data);
    
    return 0;
}

int OutputText(const char* msg)
{
    //TODO: Add error checking on msg.
    
    printf(msg);
    
    //TODO: Add functionality for saving msg to .log file.
    std::string str = msg;
    void *data = &str;
    Write("logs/log", data);
    
    return 0;
}
