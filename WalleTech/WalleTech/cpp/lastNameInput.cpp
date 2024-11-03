#include "../Include/InputHandler.h"

void lastNameInput(Textures* t)
{
    if (flagLastName)
    {
        static bool showText = 1; // boolean to check if 1 second has passed and you can print the text and reset startTime
        int interval = 1; // time to wait
        DrawTexture(t->blankFirstLastName, 953, 255, WHITE); // draw empty blank
        double secondsSinceStart = double(clock() - startTime5) / CLOCKS_PER_SEC; // calculate seconds using the clocks_per_sec macro

        if (secondsSinceStart >= interval) // if start time is or is over 1 sec
        {
            showText = !showText; // change flag value to true/false
            startTime5 = clock();  // reset start time
        }
        for (int i = 1; i <= 170; i++) // get key input using ascii codes
        {
            if (IsKeyPressed(i) && lastName.size() <= 10)
            {
                lastName += (char)i;
            }
        }

        if (showText && lastName.empty()) // if-clause to check if the pipe symbol or the lastName should be printed
        {
            DrawText("|", 958, 265, 30, WHITE);
        }
        else
        {
            DrawText(lastName.c_str(), 958, 270, 20, WHITE);
        }
        if (IsKeyPressed(KEY_BACKSPACE) && !lastName.empty())
        {
            lastName.pop_back(); // remove last element of the string lastName when backspace is pressed
        }

        if (IsKeyPressed(KEY_ENTER) && !lastName.empty())
        {
            flagLastName = 0;
            flagUsernameSignUp = 1;
            flagLastNameEntered = 1;
        }

    }
    if (flagLastNameEntered)
    {
        DrawTexture(t->blankFirstLastName, 953, 255, WHITE); // draw empty blank
        DrawText(lastName.c_str(), 958, 270, 20, WHITE);
    }
}