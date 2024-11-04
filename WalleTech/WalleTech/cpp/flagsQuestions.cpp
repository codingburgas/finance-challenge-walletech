#include "../Include/Questions.h"

void flagQuestions(Textures* t)
{
    bool hoverNext = CheckCollisionPointRec(GetMousePosition(), { 1001, 618, (float)t->blankNext.width, (float)t->blankNext.height });

    if (hoverNext && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        if (flagQuestion[0] && (flagOptions[0] || flagOptions[1] || flagOptions[2] || flagOptions[3]))
        {
            flagQuestion[0] = 0; // if next is pressed on 1-st page
            flagQuestion[1] = 1;
        }
        else if (flagQuestion[1])
        {
            flagQuestion[1] = 0; // if next is pressed on 2-nd page
            flagQuestion[2] = 1;
            SQLSetBalance(username, balance);
            getBalance = SQLGetBalance(username);
        }
        else if (flagQuestion[2] || flagQuestion[3])
        { 
            if (flagQuestion[2])
            {
                bool isNotEmpty[3] = { 0 };
                for(int i = 0; i < 3;i++)
                    for (int j = 0; j < 3; j++)                   
                        if (flagQuestionOTT[i][j])
                            isNotEmpty[i] = 1;
                    
                if (isNotEmpty[0] && isNotEmpty[1] && isNotEmpty[2])
                {
                    flagQuestion[2] = 0; // if next is pressed on 3-rd page
                    flagQuestion[3] = 1;                    

                    string subQ1, subQ2, subQ3;
                    if (flagQuestionOTT[0][0])
                    {
                        subQ1 = "2-1-1"; // second page, first subquestion, first option (same logic for others)
                    }
                    else if (flagQuestionOTT[0][1])
                    {
                        subQ1 = "2-1-2";
                    }
                    else if (flagQuestionOTT[0][2])
                    {
                        subQ1 = "2-1-3";
                    }

                    if (flagQuestionOTT[1][0])
                    {
                        subQ2 = "2-2-1";
                    }
                    else if (flagQuestionOTT[1][1])
                    {
                        subQ2 = "2-2-2";
                    }
                    else if (flagQuestionOTT[1][2])
                    {
                        subQ2 = "2-2-3";
                    }

                    if (flagQuestionOTT[2][0])
                    {
                        subQ3 = "2-3-1";
                    }
                    else if (flagQuestionOTT[2][1])
                    {
                        subQ3 = "2-3-2";
                    }
                    else if (flagQuestionOTT[2][2])
                    {
                        subQ3 = "2-3-3";
                    }    
                    for (int i = 0; i < 3; i++)
                        for (int j = 0; j < 3; j++)
                            flagQuestionOTT[i][j] = 0; // reset all flags for the next question

                    SQLInsertIncomeLastThreeMonths(username, subQ1, subQ2, subQ3); // Insert username and income answers for the last three months in the server
                }
            }
            else if (flagQuestion[3]) // if next is pressed on 4-thd page
            {
                bool isNotEmpty[3] = { 0 };
                for (int i = 0; i < 3; i++)
                    for (int j = 0; j < 3; j++)
                        if (flagQuestionOTT[i][j])
                            isNotEmpty[i] = 1;

                if (isNotEmpty[0] && isNotEmpty[1] && isNotEmpty[2])
                {                  
                    flagQuestion[3] = 0;

                    string subQ1, subQ2, subQ3;
                    if (flagQuestionOTT[0][0])
                    {
                        subQ1 = "2-1-1"; // second page, first subquestion, first option (same logic for others)
                    }
                    else if (flagQuestionOTT[0][1])
                    {
                        subQ1 = "2-1-2";
                    }
                    else if (flagQuestionOTT[0][2])
                    {
                        subQ1 = "2-1-3";
                    }

                    if (flagQuestionOTT[1][0])
                    {
                        subQ2 = "2-2-1";
                    }
                    else if (flagQuestionOTT[1][1])
                    {
                        subQ2 = "2-2-2";
                    }
                    else if (flagQuestionOTT[1][2])
                    {
                        subQ2 = "2-2-3";
                    }

                    if (flagQuestionOTT[2][0])
                    {
                        subQ3 = "2-3-1";
                    }
                    else if (flagQuestionOTT[2][1])
                    {
                        subQ3 = "2-3-2";
                    }
                    else if (flagQuestionOTT[2][2])
                    {
                        subQ3 = "2-3-3";
                    }
                    for (int i = 0; i < 3; i++)
                        for (int j = 0; j < 3; j++)
                            flagQuestionOTT[i][j] = 0; // reset all flags
                    SQLInsertSpendingsLastThreeMonths(username, subQ1, subQ2, subQ3); // Insert username and income answers for the last three months in the server
                    flagShowQuestionaire = 0; // flag to show that the questionaire is over and you have moved to the dashboard                    
                }
            }         
        }
    }
}