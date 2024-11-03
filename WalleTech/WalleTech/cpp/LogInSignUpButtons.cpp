#include "../Include/LogInSignUpButtons.h"
#include "../Include/Questions.h"
void buttonsLogInSignUp(Textures*t)
{
    if (!flagCreateOne) // login sql server credentials check
    {
        bool hoverLogIn = CheckCollisionPointRec(GetMousePosition(), { 759, 595, (float)t->blankLogInButton.width, (float)t->blankLogInButton.height });
        if (hoverLogIn && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            bool isThere = SQLCheckLoginInformation(username, password); // check if login credentials are valid
            if (!isThere)
            {
                flagNotRegistered = 1; // 1 if no data corresponds to the login credentials
            }
            else
            {
                flagIsRegistered = 1; // signal to show that you are registered
            }
        }

        if (flagNotRegistered)
        { // when no username and password are found wait for a few seconds, show "please try again message" and reset all flags for the page
            DrawTexture(t->pleaseRegisterMessage, 790, 575, RAYWHITE);
            static bool flag3Sec = 0;
            double secondsSinceStart = double(clock() - startTime3) / CLOCKS_PER_SEC;

            if (secondsSinceStart >= 3)
            {
                flag3Sec = 1; // wait for 3 seconds and reset fields if not registered already
                startTime3 = clock();
            }
            if (flag3Sec)
            {
                resetVariablesAndFlags();
                starSet.clear(); // reset flags and strings

            }
        }
    }
    else
    {
        bool hoverCreateAnAccount = CheckCollisionPointRec(GetMousePosition(), { 759, 595, (float)t->blankLogInButton.width, (float)t->blankLogInButton.height });
        if (hoverCreateAnAccount && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            if (!username.empty() && !password.empty() && !firstName.empty() && !lastName.empty())
            {
                resultRegister = SQLCreateAccount(username, password, firstName, lastName);  // insert first,last name username and password into the sql server 
                if (resultRegister)
                {
                    flagCreateOne = 0; // if you're signup data is valid go to the login page and reset all flags                  
                    resetVariablesAndFlags();
                }
                else
                {
                    startTime = clock(); // time since start counting
                    while (1)
                    {
                        double sinceStartTime = double(clock() - startTime) / CLOCKS_PER_SEC; // current clock ticks

                        if (sinceStartTime >= 1)
                        {
                            resetVariablesAndFlags();  // wait one second with the please try again message and reset all flags and vars
                            break;
                        }
                    }
                    resetVariablesAndFlags(); // reset flags and variables in create one page    
                }
            }
        }
    }
}