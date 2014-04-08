// Main.cpp
// The main file that runs the tool.

//#include <iostream>
#include <stdio.h>
#include <string>

#include "Commands.h"
#include "HelperFunctions.h"
#include "Login.h"

// Windows doesn't have snprintf
#if _WIN32
#define snprintf _snprintf
#endif

//main: 
int main()
{
    // Login
    // Variables to store entered userName and passWord
    std::string userName;
    std::string passWord;

    // Initialize the valid logins
    InitializeValidLogins();

    // Get userName from user input
    //printf("user: ");
    OutputText("user: ", MSG_TERMINAL_OUTPUT);
    userName = GetInput();

    // Get passWord from user input
    //printf("password: ");
    OutputText("password: ", MSG_TERMINAL_OUTPUT);
    passWord = GetInput();

    LoginCredentials login;
    login.SetUser(userName);
    login.SetPass(passWord);

    if(!CheckLogin(login))
    {
        OutputText("Incorrect username and/or password. Exiting.\n", MSG_ERROR);
        return 0;
    }

    // Successful login
    OutputText("Successful Login.\n'?' or 'HELP' will display commands.\n\n", MSG_TERMINAL_OUTPUT);

    // Enter main loop
    while(_running)
    {
        std::string command;

        // Parse user input for commands and run them
        //printf("Enter Command: ");
        OutputText("Enter Command: ", MSG_TERMINAL_OUTPUT);
        command = GetInput();

        //temp
        //TODO: use ParseCommand to create a command based on user input string.
        //      change the following if check to check if a command was created
        //      (non-null) and run the command if so.
        if(ParseCommand(command))
        {
            // Run the command
        }
        else
        {
            //printf("Invalid Command.\n\n");
            // Format the error message for sending in OutputText()
            std::string msg;
            char buffer[50];
            snprintf(buffer, 50, "Invalid Command. %s\n\n", command.c_str());
            msg = buffer;
            OutputText(msg, MSG_ERROR);
        }
    }

    // Shutdown

    // Old Hello World Template
    /*auto hello = []() -> void {
        // Print Hello World! to the standard output.
    	cout << "Hello World from Compilr.com!";
    };

    // Call the lambda function
    hello();*/

    return 0;
}
