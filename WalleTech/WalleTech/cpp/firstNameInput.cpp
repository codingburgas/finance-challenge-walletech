#include "../Include/InputHandler.h"


void firstNameInput(Textures* t)
{
    if (flagFirstName)
    {
        static bool showText = 1; // boolean to check if 1 second has passed and you can print the text and reset startTime
        int interval = 1; // time to wait
        DrawTexture(t->blankFirstLastName, 759, 255, WHITE); // draw empty blank
        double secondsSinceStart = double(clock() - startTime4) / CLOCKS_PER_SEC; // calculate seconds using the clocks_per_sec macro

        if (secondsSinceStart >= interval) // if start time is or is over 1 sec
        {
            showText = !showText; // change flag value to true/false
            startTime4 = clock();  // reset start time
        }
        for (int i = 1; i <= 170; i++) // get key input using ascii codes
        {
            if (IsKeyPressed(i) && firstName.size() <= 10)
            {
                firstName += (char)i;
            }
        }

        if (showText && firstName.empty()) // if-clause to check if the pipe symbol or the firstName should be printed
        {
            DrawText("|", 765, 265, 30, WHITE);
        }
        else
        {
            DrawText(firstName.c_str(), 765, 270, 20, WHITE);
        }
        if (IsKeyPressed(KEY_BACKSPACE) && !firstName.empty())
        {
            firstName.pop_back(); // remove last element of the string firstName when backspace is pressed
        }


        if (IsKeyPressed(KEY_ENTER)) // move to the last name field if you have entered a first name
        {
            if (!firstName.empty())
            {
                flagFirstName = 0;
                flagLastName = 1;
                firstNameEntered = 1;
            }
        }


    }
    if (firstNameEntered) // print first name after enter
    {
        DrawTexture(t->blankFirstLastName, 759, 255, WHITE); // draw empty blank
        DrawText(firstName.c_str(), 765, 270, 20, WHITE); // print the enterd first name
    }
}