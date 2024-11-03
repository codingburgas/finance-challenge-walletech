#include "../Include/Questions.h"

void QuestionTwo(Textures* t)
{
    if (flagQuestion[1]) // question 2 tab
    {
        DrawTexture(t->question2, 0, 0, RAYWHITE);
        DrawTexture(t->blankTypeHere, 417, 240, BLANK);
        bool hoverBlankTypeHere = CheckCollisionPointRec(GetMousePosition(), { 417, 240, (float)t->blankTypeHere.width, (float)t->blankTypeHere.height });
        if (hoverBlankTypeHere && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            flagTypeHere = 1; // if type here field is pressed, the flag is set
        }
        if (flagTypeHere)
        {
            static bool showText = 1;
            int interval = 1;
            double secondsSinceStart = double(clock() - startTime2) / CLOCKS_PER_SEC;
            DrawTexture(t->blankTypeHere, 417, 240, RAYWHITE);
            if (secondsSinceStart >= interval)
            {
                showText = !showText;
                startTime2 = clock();
            }
            if (showText && balance.empty())
            {
                DrawText("|", 421, 247, 30, WHITE); // pipe shows if there're no numbers entered, over 1 second interval
            }
            else
            {
                DrawText(balance.c_str(), 421, 247, 30, WHITE);
            }
            for (int i = 48; i <= 57; i++) // insert numbers between 0-9 only
            {
                if (IsKeyPressed(i) && balance.size() <= 6)
                {
                    if (balance.empty() && i == '0') // if 0 is typed first, it won't be added
                        continue;
                    if (balance.find('.') != string::npos)
                    {
                        if (balance.size() - balance.find('.') > 2)
                        {
                            continue; // if you try to insert more than two numbers after the decimal point it won't be added to the balance string
                        }
                    }
                    balance += (char)i;
                }
            }
            if (IsKeyPressed('.') && balance.size() <= 6 && balance.find('.') == string::npos) // check whether there's already an entered dot
            {
                balance += '.'; // insert decimal point(dot) if there's no one already
            }
            if (IsKeyPressed(KEY_BACKSPACE) && !balance.empty())
            {
                balance.pop_back(); // remove last character when backspace is pressed
            }

        }
    }
}