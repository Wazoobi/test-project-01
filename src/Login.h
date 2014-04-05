// Login.h
// File containing classes and functions related to login functionality.

#ifndef _LOGIN_H_
#define _LOGIN_H_

// Includes
#include <string>
#include <stdlib.h>

// Defines
#define MAX_VALID_CREDENTIALS 5

// Declare the class first to be used in Function Declarations
class LoginCredentials;

// Globals
namespace LoginGlobals
{
    // Dynamic list of valid LoginCredentials
    extern LoginCredentials *validLogins;
}

// enum of permission levels available to credentials.
enum permission {INVALID_PERMISSION = -1, USER_PERMISSION, ADMIN_PERMISSION};

// Function Declarations
void InitializeValidLogins();
bool CheckLogin(std::string username, std::string password);
bool CheckLogin(LoginCredentials login);


// Classes
// LoginCredentials: Class storing a username, password, and permission value.
class LoginCredentials
{
private:
    short permission;
    std::string username;
    std::string password;

    // Function Declarations
    bool CheckUserName(std::string user);
    bool CheckPassword(std::string pass);

public:
    // Inline Functions
    int GetPermission(void) { return permission; }
    std::string GetUserName(void) { return username; }
    std::string GetPassword(void) { return password; }
    void SetUser(std::string name) { username = name; }
    void SetPass(std::string pass) { password = pass; }

    // Function Declarations
    LoginCredentials();
    void SetPermission(int perm);
    bool CompareCredentials(LoginCredentials loginB);
    bool CompareCredentials(std::string user, std::string pass);
};

#endif //_LOGIN_H_
