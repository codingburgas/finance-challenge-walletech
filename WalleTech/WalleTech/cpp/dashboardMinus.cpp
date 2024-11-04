#include "../Include/Dashboad.h"
#include "../Include/InputHandler.h"
#include "../Include/SQL.h"
#include "../Include/Questions.h"
void dashboardMinus(Textures* t)
{
    if (flagMinus) // if flag minus is pressed
    {
        DrawTexture(t->makeRequest, 370, 150, RAYWHITE); // make request screen
        DrawTexture(t->blankCancelSubmit, 770, 480, BLANK); // blank cancel
        DrawTexture(t->blankAmountDateDescription, 409, 250, BLANK); // Amount blank
        DrawTexture(t->blankCancelSubmit, 932, 479, BLANK); // blank submit
        static bool showText = 1;
        int interval = 1;

        bool hoverCancel = CheckCollisionPointRec(GetMousePosition(), { 770, 480, (float)t->blankCancelSubmit.width, (float)t->blankCancelSubmit.height }); // if hover on cancel button
        bool hoverSubmit = CheckCollisionPointRec(GetMousePosition(), { 932, 479, (float)t->blankCancelSubmit.width, (float)t->blankCancelSubmit.height }); //if we hover on submit field
        bool hoverAmount = CheckCollisionPointRec(GetMousePosition(), { 409, 250, (float)t->blankAmountDateDescription.width, (float)t->blankAmountDateDescription.height });// if hover on amount field
        if (hoverCancel && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            flagMinus = 0; // if cancel is pressed reset flags and clear strings
            flagAmount = 0;
            flagDescription = 0;
            amount.clear();
            description.clear();
            date.clear();
            flagAmountEntered = 0;
            flagDescriptionEntered = 0;
        }
        if (hoverSubmit && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            if (SQLInsertTransactionExpenses(username, amount, description, date)); // check and submit transaction data
            {
                SQLUpdateBalanceAfterExpense(username, date, amount);
                flagMinus = 0; //if date, amount and description are valid close the tabs and reset all flags to be ready for the next query else only reset the flags
                balanceChanged = 1;

                lastFourTransactions[countI][countJ++] = amount; // copy all data from last query if it is a fifth one it will rewrite the first
                lastFourTransactions[countI][countJ++] = date;
                lastFourTransactions[countI][countJ++] = description;
                countJ = 0;
                countI++;
                if (countI > 3) // reset i if it has exceeded 3
                    countI = 0;
            }
            amount.clear(); // clear strings and flags 
            date.clear();
            description.clear();
            flagAmount = flagDate = flagDescription = flagAmountEntered = flagDescriptionEntered = flagDateEntered = 0;
        }
        if (hoverAmount && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            flagAmount = 1; // // if amount has been clicked the flag is set
        }

        if (flagAmount && flagMinus) // if amount has been clicked
        {
            DrawTexture(t->blankAmountDateDescription, 409, 250, RAYWHITE);

            static bool showText = 1;
            int interval = 1;
            double secondsSinceStart = double(clock() - startTime2) / CLOCKS_PER_SEC;
            if (secondsSinceStart >= interval)
            {
                showText = !showText;
                startTime2 = clock();
            }
            if (showText && amount.empty())
            {
                DrawText("|", 411, 253, 30, WHITE); // pipe shows if there're no numbers entered, over 1 second interval
            }
            else
            {
                DrawText(amount.c_str(), 411, 253, 30, WHITE);
            }
            for (int i = 48; i <= 57; i++) // insert numbers between 0-9 only
            {
                if (IsKeyPressed(i) && amount.size() <= 6)
                {
              
                        stringstream conv; // convert and calculate if the amount for the query is bigger than the balance, only for Minus (to know if amount is valid so we don't get a negative balance)
                        string charA(1, i);
                        conv << amount + charA;
                        double enteredAmount;
                        conv >> enteredAmount;

                        conv.clear();
                        conv << SQLGetBalance(username);
                        double sqlBalance;
                        conv >> sqlBalance;

                        if (enteredAmount <= sqlBalance)
                            amount += (char)i;
                        else
                            continue;
                    

                    if (amount.empty() && i == '0') // if 0 is typed first, it won't be added
                        continue;
                    if (amount.find('.') != string::npos)
                    {
                        if (amount.size() - amount.find('.') > 2)
                        {
                            continue; // if you try to insert more than two numbers after the decimal point it won't be added to the amount string
                        }
                    }                                  
                }
                if (IsKeyPressed('.') && amount.size() <= getBalance.size() && amount.find('.') == std::string::npos) // check whether there's already an entered dot
                {
                    amount += '.'; // insert decimal point(dot) if there's no one already
                }
            }
            if (IsKeyPressed(KEY_BACKSPACE) && !amount.empty())
            {
                amount.pop_back(); // remove last character when backspace is pressed                   
            }

        }
        if (flagDescription && flagMinus) // if description has been clicked
        {
            DrawTexture(t->blankAmountDateDescription, 409, 339, RAYWHITE);

            static bool showText = 1;
            int interval = 1;
            double secondsSinceStart = double(clock() - startTime2) / CLOCKS_PER_SEC;
            if (secondsSinceStart >= interval)
            {
                showText = !showText;
                startTime2 = clock();
            }
            if (showText && description.empty())
            {
                DrawText("|", 412, 342, 30, WHITE); // pipe shows if there're no numbers entered, over 1 second interval
            }
            else
            {
                DrawText(description.c_str(), 412, 342, 30, WHITE);
            }
            for (char i = 'a'; i <= 'z'; i++) // add only letters from 'a' to 'z'
            {
                if (IsKeyPressed(i) && description.size() <= 10)
                    description += (char)i;
            }
            for (char i = 'A'; i <= 'Z'; i++) // add only letters from 'A' to 'Z'
            {
                if (IsKeyPressed(i) && description.size() <= 10)
                    description += (char)i;
            }
            if (IsKeyPressed(KEY_BACKSPACE) && !description.empty())
            {
                description.pop_back(); // remove last character when backspace is pressed                   
            }
        }
        if (flagDate && flagMinus)
        {
            DrawTexture(t->blankAmountDateDescription, 409, 428, RAYWHITE); // date white blank

            static bool showText = 1;
            int interval = 1;
            double secondsSinceStart = double(clock() - startTime2) / CLOCKS_PER_SEC;
            if (secondsSinceStart >= interval)
            {
                showText = !showText;
                startTime2 = clock();
            }
            if (showText && date.empty())
            {
                DrawText("|", 413, 431, 30, WHITE); // pipe shows if there're no numbers entered, over 1 second interval
            }
            else
            {
                DrawText(date.c_str(), 413, 431, 30, WHITE);
            }

            if (IsKeyPressed(KEY_BACKSPACE) && !date.empty())
            {
                date.pop_back(); // remove last character when backspace is pressed                   
            }

            // date yyyy-mm-dd total 10 chars

            for (int i = 48; i <= 57; i++) // insert numbers between 0-9 only when we insert year,month or day, else for specific indexes it will only allow '-'
            {
                if (IsKeyPressed(i) && date.size() <= 10)
                {
                    if (date.empty() && i == '0') // if 0 is typed first, it won't be added
                        continue;
                    if (date.size() != 4 && date.size() != 7) //  check if we are on indexes other than 4 or 7
                        date += (char)i;
                }
            }
            if (IsKeyPressed('-') && (date.size() == 4 || date.size() == 7)) // for specific indexes '-' is only allowed to keep up with the yy-mm-dd data format
            {
                date += '-';
            }
            if (IsKeyPressed(KEY_BACKSPACE) && !date.empty())
            {
                date.pop_back(); // remove last character when backspace is pressed                   
            }

        }
        if (IsKeyPressed(KEY_ENTER) && flagAmount && !amount.empty()) // move to description
        {
            flagAmountEntered = 1;
            flagAmount = 0;
            flagDescription = 1;
        }
        if (IsKeyPressed(KEY_ENTER) && flagDescription && !description.empty()) // move to date
        {
            flagDescriptionEntered = 1;
            flagDescription = 0;
            flagDate = 1;
        }
        if (flagAmountEntered) // if amount is entered show it until the tab is active, same logic for description
        {
            DrawTexture(t->blankAmountDateDescription, 409, 250, RAYWHITE);
            DrawText(amount.c_str(), 411, 253, 30, WHITE);
        }
        if (flagDescriptionEntered)
        {
            DrawTexture(t->blankAmountDateDescription, 409, 339, RAYWHITE);
            DrawText(description.c_str(), 412, 342, 30, WHITE);
        }

    }
}
// DrawTexture(t->blankAmountDateDescription, 409, 250, RAYWHITE); // Description white field
