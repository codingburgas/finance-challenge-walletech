#include "../Include/Dashboad.h"
#include "../Include/InputHandler.h"
#include "../Include/Questions.h"
void dashboardPlus(Textures* t)
{
	if (flagPlus) // if plus button has been pressed
	{
		DrawTexture(t->makeRequest, 370, 150, RAYWHITE); // make request screen
		DrawTexture(t->blankCancelSubmit, 770, 480, BLANK); // blank cancel
		DrawTexture(t->blankAmountDateDescription, 409, 250, BLANK); // Amount blank
        DrawTexture(t->blankCancelSubmit, 932, 479, BLANK); // blank submit

		bool hoverCancel = CheckCollisionPointRec(GetMousePosition(), { 770, 480, (float)t->blankCancelSubmit.width, (float)t->blankCancelSubmit.height }); // is true if you hover on cancel button
        bool hoverSubmit = CheckCollisionPointRec(GetMousePosition(), { 932, 479, (float)t->blankCancelSubmit.width, (float)t->blankCancelSubmit.height }); // is true if you hover on submit button
		bool hoverAmount = CheckCollisionPointRec(GetMousePosition(), { 409, 250, (float)t->blankAmountDateDescription.width, (float)t->blankAmountDateDescription.height });// is true if you hover on amount field
		if (hoverCancel && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
            flagPlus = 0; // reset all flags if we press cancel
            flagAmount = 0;
            flagDescription = 0;
            amount.clear();
            description.clear();
            date.clear();
            flagAmountEntered = 0;
            flagDescriptionEntered = 0;
		}
        if (hoverSubmit && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) // if we submit the data
        {
            if (SQLInsertTransactionRevenues(username, amount, description, date))  // check if is valid by inserting it and returning a true or false value
            {
                SQLUpdateBalanceAfterRevenue(username,date, amount); // update our balance account
               flagPlus = 0; //if date, amount and description are valid close the tabs and reset all flags to be ready for the next query else only reset the flags
               balanceChanged = 1;
               
               lastFourTransactions[countI][countJ++] = amount; // insert the data from the transaction into the 2d array, it will overwrite if we insert more than four transactions
               lastFourTransactions[countI][countJ++] = date;
               lastFourTransactions[countI][countJ++] = description;  
               countJ = 0; // reset j to be ready for the next transaction
               countI++; // increment i
               if (countI > 3) // if i has exceeded its 3 which is the max index for the 2d array it will be reset to 0 and old transactions will be overwriten
                   countI = 0;
            }
            
            
            amount.clear(); // reset string used for input
            date.clear();
            description.clear();
            flagAmount = flagDate = flagDescription = flagAmountEntered = flagDescriptionEntered = flagDateEntered = 0;//reset flag
        }
		if (hoverAmount && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			flagAmount = 1; // // if amount has been clicked the flag is set
		}

		if (flagAmount && flagPlus) // if amount has been clicked
		{
			DrawTexture(t->blankAmountDateDescription, 409, 250, RAYWHITE); // show white blank when clicked

            static bool showText = 1;
            int interval = 1;
            double secondsSinceStart = double(clock() - startTime2) / CLOCKS_PER_SEC;
            if (secondsSinceStart >= interval)
            {
                showText = !showText;
                startTime2 = clock();
            }
            if (showText && amount.empty()) // if there's text
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
                    if (amount.empty() && i == '0') // if 0 is typed first, it won't be added
                        continue;
                    if (amount.find('.') != string::npos)
                    {
                        if (amount.size() - amount.find('.') > 2)
                        {
                            continue; // if you try to insert more than two numbers after the decimal point it won't be added to the amount string
                        }
                    }
                        amount += (char)i;
                }
                if (IsKeyPressed('.') && amount.size() <= getBalance.size() && amount.find('.') == string::npos) // check whether there's already an entered dot
                {
                    amount += '.'; // insert decimal point(dot) if there's no one already
                }                   
            }
            if (IsKeyPressed(KEY_BACKSPACE) && !amount.empty())
            {
                amount.pop_back(); // remove last character when backspace is pressed                   
            }            

		}
        if (flagDescription && flagPlus) // if description has been clicked
        {
            DrawTexture(t->blankAmountDateDescription, 409, 339, RAYWHITE);

            static bool showText = 1;
            int interval = 1;
            double secondsSinceStart = double(clock() - startTime2) / CLOCKS_PER_SEC; // secs calculated before
            if (secondsSinceStart >= interval)
            {
                showText = !showText;
                startTime2 = clock(); // clock renew
            }
            if (showText && description.empty())
            {
                DrawText("|", 412, 342, 30, WHITE); // pipe shows if there're no text entered, over 1 second interval
            }
            else
            {
                DrawText(description.c_str(), 412, 342, 30, WHITE);
            }
            for (char i = 'a'; i <= 'z'; i++) // add only letters from 'a' to 'z'
            {
                if(IsKeyPressed(i) && description.size() <= 10)
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
        if (flagDate && flagPlus)
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
                    if(date.size() != 4 && date.size() != 7)  
                    date += (char)i;
                }
            }
            if (IsKeyPressed('-') && (date.size() == 4 || date.size() == 7))  // for specific indexes it will only allow '-', yy-mm-dd
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
            flagAmountEntered = 1; // if we press enter reset amount flags and set  description, same logic for others
            flagAmount = 0;
            flagDescription = 1;
        }
        if (IsKeyPressed(KEY_ENTER) && flagDescription && !description.empty()) // move to date
        {
            flagDescriptionEntered = 1;
            flagDescription = 0;
            flagDate = 1;
        }
        if (flagAmountEntered) // if we have pressed enter, data to stay
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
