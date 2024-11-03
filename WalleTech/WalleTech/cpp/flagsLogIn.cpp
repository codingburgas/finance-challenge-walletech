#include "../Include/InputHandler.h"

void flagsChangeLogIn(Textures* t)
{
    bool hoverUsername = CheckCollisionPointRec(GetMousePosition(), { 759, 292, (float)t->blank.width, (float)t->blank.height }); // is true if your mouse cursor is on the Username field
    bool hoverPassword = CheckCollisionPointRec(GetMousePosition(), { 765, 370, (float)t->blank.width, (float)t->blank.height }); // is true if your mouse cursor is on the Password field
    bool hoverBlankCreateOne = CheckCollisionPointRec(GetMousePosition(), { 913, 135, (float)t->blankCreateOne.width, (float)t->blankCreateOne.height }); // is true if your mouse cursor is on the create one button
    if (hoverUsername && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !flagUsername && !flagPassword)
    {
        flagUsername = !flagUsername; // change flag if Username field is clicked
        flagUsernameEntered = 1;
    }

    if (hoverPassword && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !flagPassword && !flagUsername && flagUsernameEntered)
    {
        flagPassword = !flagPassword; // change flag if Password field is clicked
    }
    if (hoverBlankCreateOne && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        flagCreateOne = 1;
        flagEnter = 0;
        resetVariablesAndFlags();// reset vars and flags if we go to create one page and we have entered data before
    }
}