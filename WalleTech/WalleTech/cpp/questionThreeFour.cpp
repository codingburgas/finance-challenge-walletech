#include "../Include/Questions.h"

void QuestionThreeFour(Textures* t)
{
    if (flagQuestion[2] || flagQuestion[3])
    { // hoverQuestionTwoOneTwoThree, is true if you hover on a option from one of the three subquestions
        bool hoverQuestionOTT[3][3] =
        {
            {
                CheckCollisionPointRec(GetMousePosition(), { (flagQuestion[2]) ? 401.f : 402.f, (flagQuestion[2]) ? 228.f : 229.f, (float)t->dot.width, (float)t->dot.height }),
                CheckCollisionPointRec(GetMousePosition(), { (flagQuestion[2]) ? 642.f : 643.f, (flagQuestion[2]) ? 228.f : 229.f, (float)t->dot.width, (float)t->dot.height }),
                CheckCollisionPointRec(GetMousePosition(), { (flagQuestion[2]) ? 895.f : 896.f, (flagQuestion[2]) ? 228.f : 229.f, (float)t->dot.width, (float)t->dot.height })
            },
            {
                CheckCollisionPointRec(GetMousePosition(), { (flagQuestion[2]) ? 401.f : 402.f, (flagQuestion[2]) ? 349.f : 350.f, (float)t->dot.width, (float)t->dot.height }),
                CheckCollisionPointRec(GetMousePosition(), { (flagQuestion[2]) ? 642.f : 643.f, (flagQuestion[2]) ? 349.f : 350.f, (float)t->dot.width, (float)t->dot.height }),
                CheckCollisionPointRec(GetMousePosition(), { (flagQuestion[2]) ? 895.f : 896.f, (flagQuestion[2]) ? 349.f : 350.f, (float)t->dot.width, (float)t->dot.height })
            },
            {
                CheckCollisionPointRec(GetMousePosition(), { (flagQuestion[2]) ? 401.f : 402.f, (flagQuestion[2]) ? 466.f : 468.f, (float)t->dot.width, (float)t->dot.height }),
                CheckCollisionPointRec(GetMousePosition(), { (flagQuestion[2]) ? 642.f : 643.f, (flagQuestion[2]) ? 466.f : 468.f, (float)t->dot.width, (float)t->dot.height }),
                CheckCollisionPointRec(GetMousePosition(), { (flagQuestion[2]) ? 895.f : 896.f, (flagQuestion[2]) ? 466.f : 468.f, (float)t->dot.width, (float)t->dot.height })
            },
        };

        DrawTexture((flagQuestion[2]) ? t->question3 : t->question4, 0, 0, RAYWHITE);
        if (hoverQuestionOTT[0][0] && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) // 2-1-1 option button
        {
            flagQuestionOTT[0][0] = 1; // set flag for each subquestion option and make other flags 0 if they have been activated by clicking other options
            flagQuestionOTT[0][1] = 0;
            flagQuestionOTT[0][2] = 0;
        }
        if (hoverQuestionOTT[0][1] && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) // 2-1-2 option button
        {
            flagQuestionOTT[0][1] = 1;
            flagQuestionOTT[0][0] = 0;
            flagQuestionOTT[0][2] = 0;
        }
        if (hoverQuestionOTT[0][2] && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) // 2-1-3 option button
        {
            flagQuestionOTT[0][2] = 1;
            flagQuestionOTT[0][1] = 0;
            flagQuestionOTT[0][0] = 0;
        }
        if (hoverQuestionOTT[1][0] && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) // 2-2-1 option button
        {
            flagQuestionOTT[1][0] = 1;
            flagQuestionOTT[1][1] = 0;
            flagQuestionOTT[1][2] = 0;
        }
        if (hoverQuestionOTT[1][1] && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))  // 2-2-2 option button
        {
            flagQuestionOTT[1][1] = 1;
            flagQuestionOTT[1][0] = 0;
            flagQuestionOTT[1][2] = 0;
        }
        if (hoverQuestionOTT[1][2] && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) // 2-2-3 option button
        {
            flagQuestionOTT[1][2] = 1;
            flagQuestionOTT[1][0] = 0;
            flagQuestionOTT[1][1] = 0;
        }
        if (hoverQuestionOTT[2][0] && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) // 2-3-1 option button
        {
            flagQuestionOTT[2][0] = 1;
            flagQuestionOTT[2][1] = 0;
            flagQuestionOTT[2][2] = 0;
        }
        if (hoverQuestionOTT[2][1] && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) // 2-3-2 option button
        {
            flagQuestionOTT[2][1] = 1;
            flagQuestionOTT[2][0] = 0;
            flagQuestionOTT[2][2] = 0;
        }
        if (hoverQuestionOTT[2][2] && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) // 2-3-3 option button
        {
            flagQuestionOTT[2][2] = 1;
            flagQuestionOTT[2][1] = 0;
            flagQuestionOTT[2][0] = 0;
        }

        //first month
        if (flagQuestionOTT[0][0])
            DrawTexture(t->dot, (flagQuestion[2]) ? 401.f : 402.f, (flagQuestion[2]) ? 228.f : 229.f, BLUE);
        if (flagQuestionOTT[0][1])
            DrawTexture(t->dot, (flagQuestion[2]) ? 642.f : 643.f, (flagQuestion[2]) ? 228.f : 229.f, BLUE);
        if (flagQuestionOTT[0][2])
            DrawTexture(t->dot, (flagQuestion[2]) ? 895.f : 896.f, (flagQuestion[2]) ? 228.f : 229.f, BLUE);
        //second month
        if (flagQuestionOTT[1][0])
            DrawTexture(t->dot, (flagQuestion[2]) ? 401.f : 402.f, (flagQuestion[2]) ? 349.f : 350.f, BLUE);
        if (flagQuestionOTT[1][1])
            DrawTexture(t->dot, (flagQuestion[2]) ? 642.f : 643.f, (flagQuestion[2]) ? 349.f : 350.f, BLUE);
        if (flagQuestionOTT[1][2])
            DrawTexture(t->dot, (flagQuestion[2]) ? 895.f : 896.f, (flagQuestion[2]) ? 349.f : 350.f, BLUE);
        // third month
        if (flagQuestionOTT[2][0])
            DrawTexture(t->dot, (flagQuestion[2]) ? 401.f : 402.f, (flagQuestion[2]) ? 466.f : 468.f, BLUE);
        if (flagQuestionOTT[2][1])
            DrawTexture(t->dot, (flagQuestion[2]) ? 642.f : 643.f, (flagQuestion[2]) ? 466.f : 468.f, BLUE);
        if (flagQuestionOTT[2][2])
            DrawTexture(t->dot, (flagQuestion[2]) ? 895.f : 896.f, (flagQuestion[2]) ? 466.f : 468.f, BLUE);

    }
}