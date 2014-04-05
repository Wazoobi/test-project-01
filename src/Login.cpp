// Login.cpp
// File containing classes and functions related to login functionality.

#include <stdlib.h>

#include "Login.h"
#include "HelperFunctions.h"

// Globals
LoginCredentials *validLogins;

// LoginCredentials Functions
// Constructor
LoginCredentials::LoginCredentials()
{
    // Initialize Members
    permission = -1;
    username = "";
    password = "";
}

void LoginCredentials::SetPermission(int perm)
{
    if( permission > ADMIN_PERMISSION )
    {
        //TODO: Error checking
        return;
    }

    permission = perm;
}

bool LoginCredentials::CheckUserName(std::string user)
{
    if(ToLower(username) != user)
    {
        //TODO: Message and/or error checking

        return false;
    }

    return true;
}

bool LoginCredentials::CheckPassword(std::string pass)
{
    if(password != pass)
    {
        //TODO: message and/or error checking

        return false;
    }

    return true;
}

// CompareCredentials: Checks provided LoginCredential's username and password
//                      against *this.
bool LoginCredentials::CompareCredentials(LoginCredentials loginB)
{
    // Check Username & Password of loginB against this.
    if(!CheckUserName(loginB.GetUserName()))
        return false;
    if(!CheckPassword(loginB.GetPassword()))
        return false;

    return true;
}
bool LoginCredentials::CompareCredentials(std::string user, std::string pass)
{
    // Check provided Username & Password against this.
    if(!CheckUserName(user))
        return false;
    if(!CheckPassword(pass))
        return false;

    return true;
}


// Other Functions
// InitializeValidLogin: Initializes the validLogins list.
void InitializeValidLogins(void)
{
    validLogins = new LoginCredentials[MAX_VALID_CREDENTIALS];

    for(int i = 0; i < MAX_VALID_CREDENTIALS; i++)
    {
        validLogins[i].SetUser("");
        validLogins[i].SetPass("");
        validLogins[i].SetPermission(INVALID_PERMISSION);
    }

    //temp
    validLogins[0].SetUser("wazoobi");
    validLogins[0].SetPass("admin");
    validLogins[0].SetPermission(ADMIN_PERMISSION);

    //TODO: Read-in validLogins from a file.
}

// CheckLogin: Checks given username and password or full credentials against
//              global list of valid credentials. Prefered use is the 2nd
//              verions that takes LoginCredentials as a parameter due to its
//              ability to properly set the permission upon finding a match.
bool CheckLogin(std::string user, std::string pass)
{
    // Create a loginCredential with given username and pass
    LoginCredentials login;
    login.SetUser(user);
    login.SetPass(pass);

    // Loop through validLogins and check given credentials against valid ones.
    for(int i = 0; validLogins[i].GetPermission() > INVALID_PERMISSION; i++)
    {
        if(validLogins[i].CompareCredentials(login))
            return false;
    }

    return true;
}
bool CheckLogin(LoginCredentials login)
{
    // Loop through validLogins and check given credentials against valid ones.
    for(int i = 0; validLogins[i].GetPermission() > INVALID_PERMISSION; i++)
    {
        if(validLogins[i].CompareCredentials(login))
        {
            // If we found the login details in the list of valid logins then
            // set the permission to allow correct access.
            login.SetPermission(validLogins[i].GetPermission());
            return true;
        }
    }

    return false;
}
