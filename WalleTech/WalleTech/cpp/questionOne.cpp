#include "../Include/Questions.h"

void QuestionOne(Textures* t)
{
    if (flagQuestion[0]) // if-clauses to know which question tab to draw
    {
        DrawTexture(t->question1, 0, 0, RAYWHITE);
        DrawTexture(t->blankNext, 1001, 618, RAYWHITE); // draw next blank
        DrawTexture(t->dot, 536, 253, BLANK); // option a)
        DrawTexture(t->dot, 536, 337, BLANK); // option b)
        DrawTexture(t->dot, 536, 420, BLANK); // option c)
        DrawTexture(t->dot, 536, 504, BLANK); // option d)
        bool hoverA = CheckCollisionPointRec(GetMousePosition(), { 536, 253, (float)t->dot.width, (float)t->dot.height }); // is true if option a) is pressed, same with b,c,d
        bool hoverB = CheckCollisionPointRec(GetMousePosition(), { 536, 337, (float)t->dot.width, (float)t->dot.height });
        bool hoverC = CheckCollisionPointRec(GetMousePosition(), { 536, 420, (float)t->dot.width, (float)t->dot.height });
        bool hoverD = CheckCollisionPointRec(GetMousePosition(), { 536, 504, (float)t->dot.width, (float)t->dot.height });
        if (hoverA && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            flagOptions[0] = 1; // set the flag and use it to draw the dot blue
            flagOptions[1] = 0;
            flagOptions[2] = 0;
            flagOptions[3] = 0;
        }
        if (hoverB && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            flagOptions[0] = 0;
            flagOptions[1] = 1;
            flagOptions[2] = 0;
            flagOptions[3] = 0;
        }
        if (hoverC && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            flagOptions[0] = 0;
            flagOptions[1] = 0;
            flagOptions[2] = 1;
            flagOptions[3] = 0;
        }
        if (hoverD && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            flagOptions[0] = 0;
            flagOptions[1] = 0;
            flagOptions[2] = 0;
            flagOptions[3] = 1;
        }

        if (flagOptions[0])
            DrawTexture(t->dot, 536, 253, BLUE);
        if (flagOptions[1])
            DrawTexture(t->dot, 536, 337, BLUE);
        if (flagOptions[2])
            DrawTexture(t->dot, 536, 420, BLUE);
        if (flagOptions[3])
            DrawTexture(t->dot, 536, 504, BLUE);
    }
}