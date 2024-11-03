#include "../Include/InputHandler.h"
#include "../Include/Questions.h"
void resetVariablesAndFlags()
{
    flagUsername = 0; // reset all flags and variables if you are not registered or you switch log and sign up tabs
    flagPassword = 0;
    flagEnter = 0;
    flagUsernameEntered = 0;
    flagNotRegistered = 0;
    flagIsRegistered = 0; //
    flagFirstName = 0;
    flagLastName = 0;
    firstNameEntered = 0;
    flagLastNameEntered = 0;
    flagUsernameSignUp = 0;
    flagPasswordSignUp = 0;
    username.clear();
    password.clear();
    starSet.clear();
    startTime = clock();
    startTime2 = clock();
    startTime3 = clock();
    startTime4 = clock();
    startTime5 = clock();
    firstName.clear();
    lastName.clear();
  //  flagQuestion[0] = flagQuestion[1] = flagQuestion[2] = flagQuestion[3] = 0;
   // flagOptions[0] = flagOptions[1] = flagOptions[2] = flagOptions[3] = 0;
   // flagTypeHere = 0;
}