#pragma once
#include "pch.h"
#include "Textures.h"
#include "SQL.h"
using namespace std;
extern bool flagUsername, flagPassword, flagEnter, flagUsernameEntered, flagNotRegistered,flagIsRegistered,flagCreateOne,resultRegister; //flags to check if different fields and buttons are being presseed

extern clock_t startTime;  // Clock ticks since the program has started
extern clock_t startTime2;  // Clock ticks since the program has started
extern clock_t startTime3;
extern clock_t startTime4;
extern clock_t startTime5;
// seperate variables, one for Username field, Password field, First Name field, Last Name field

extern string username; // your account username
extern string password; // your account password
extern string starSet;// star set which we be showed instead of your password
//logIn
void flagsChangeLogIn(Textures*); // flag handling function for log in screen
void usernameInput(Textures*); // username input function
void passwordInput(Textures*); // password input

//signUp
void flagsChangeSignUp(Textures*); // flags for signup page
void firstNameInput(Textures*); // first name input function
void lastNameInput(Textures*); // last name input function
void resetVariablesAndFlags(); // function to reset all flags if needed

extern bool flagFirstName, flagLastName, firstNameEntered, flagLastNameEntered, flagUsernameSignUp, flagPasswordSignUp; // flags to know which field are we in and which has been filled with data already
extern string firstName, lastName; // first last name of your account



