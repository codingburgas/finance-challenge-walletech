#include "../Include/InputHandler.h"
#include "../Include/SQL.h"

void passwordInput(Textures* t)
{
    if ((flagPassword && !flagCreateOne) || (flagCreateOne && flagPasswordSignUp)) // if password field is clicked handle for both login and signup page
    {
        static bool showText = 1;
        int interval = 1;
       
        DrawTexture(t->blankUsernamePassword, 760, (flagCreateOne && flagPasswordSignUp) ? 415 : 372, WHITE);
        double secondsSinceStart = double(clock() - startTime2) / CLOCKS_PER_SEC;

        if (secondsSinceStart >= interval)
        {
            showText = !showText;
            startTime2 = clock();
        }

        for (int i = 1; i <= 170; i++) // add symbols by using ascii codes
        {
            if (IsKeyPressed(i) && password.size() <= 10)
            {
                password += (char)i;
                starSet += '*';
            }
        }

        if (showText && password.empty()) // show pipe over one second interval if there's no data entered
        {
            DrawText("|", 767, (flagCreateOne && flagPasswordSignUp) ? 425 : 382, 30, WHITE);
        }
        else
        {
            DrawText(starSet.c_str(), 767, (flagCreateOne && flagPasswordSignUp) ? 425 : 382, 30, WHITE);
        }

        if (IsKeyPressed(KEY_BACKSPACE) && !password.empty())
        {
            password.pop_back(); // remove last character when backspace is pressed, starset is also affected
            starSet.pop_back();
        }
    }
}