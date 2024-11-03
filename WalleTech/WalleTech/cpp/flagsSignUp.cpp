#include "../Include/InputHandler.h"
#include "../Include/Questions.h"
void flagsChangeSignUp(Textures* t)
{
    bool hoverFirstName = CheckCollisionPointRec(GetMousePosition(), { 759, 255, (float)t->blankFirstLastName.width, (float)t->blankFirstLastName.height });
    //  bool hoverLastName = CheckCollisionPointRec(GetMousePosition(), { 953, 255, (float)t->blankFirstLastName.width, (float)t->blankFirstLastName.height });
    if (hoverFirstName && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        flagFirstName = 1; // if we press on first name field activate
        flagLastName = 0;
    }
    bool hoverLogIn = CheckCollisionPointRec(GetMousePosition(), { 950, 132, (float)t->blankCreateOne.width, (float)t->blankCreateOne.height });
        // blankCreateOne, 950, 132
    if (hoverLogIn && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        flagCreateOne = 0; // if we click on log in without clicking on create account button
        resetVariablesAndFlags();
    }
}