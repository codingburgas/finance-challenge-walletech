#include "../Include/InputHandler.h"

// static variables are used so their values are saved and they don't get wiped at the end of the call

void usernameInput(Textures* t)
{
    // Check if we are in the signup or the normal input mode
    if ((flagCreateOne && flagUsernameSignUp && flagLastNameEntered) || (flagUsername && !flagEnter && !flagCreateOne))
    {
        static bool showText = 1; // boolean to check if 1 second has passed and you can print the text and reset startTime
        int interval = 1; // time to wait

        DrawTexture(t->blankUsernamePassword, 759, (flagCreateOne && flagUsernameSignUp && flagLastNameEntered) ? 335 : 292, WHITE); // if create one page is activated

        double secondsSinceStart = double(clock() - startTime) / CLOCKS_PER_SEC; // calculate seconds
        if (secondsSinceStart >= 1) // if 1 second has passed
        {
            showText = !showText; // toggle cursor visibility
            startTime = clock(); // reset start time
        }

        for (int i = 1; i <= 170; i++)
        {
            if (IsKeyPressed(i) && username.size() <= 15)
            {
                username += (char)i; // add character to username
            }
        }

        if (showText && username.empty())
        {
            DrawText("|", 767, (flagCreateOne && flagUsernameSignUp && flagLastNameEntered) ? 345 : 302, 30, WHITE); // show pipe symbol if there's no username entered yet      
        }
        else
        {
            DrawText(username.c_str(), 767, (flagCreateOne && flagUsernameSignUp && flagLastNameEntered) ? 345 : 302, 30, WHITE); // show the username when we are entering it
        }

        if (IsKeyPressed(KEY_BACKSPACE) && !username.empty())
        {
            username.pop_back(); // remove last character if backspace is pressed
        }

        if (IsKeyPressed(KEY_ENTER) && !username.empty())
        {  // first if-clause flag handle for signup page, second for login page
            if (flagCreateOne && flagUsernameSignUp && flagLastNameEntered)
            {
                flagUsernameSignUp = 0;
                flagPasswordSignUp = 1;
                flagEnter = 1;
            }
            else if (flagUsername && !flagEnter && !flagCreateOne)
            {
                flagUsername = 0;
                flagPassword = 1;
                flagEnter = 1;
            }
        }
    }

    if (flagEnter)
    {
        DrawTexture(t->blankUsernamePassword, 759, flagCreateOne ? 335 : 292, WHITE); // Display the username after ENTER has been pressed
        DrawText(username.c_str(), 767, flagCreateOne ? 345 : 302, 30, WHITE);
    }
}