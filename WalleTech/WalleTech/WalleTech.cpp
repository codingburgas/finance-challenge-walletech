#include "Include/WalleTech.h"

int main()
{
    
    InitWindow(1280, 720, "WalleTech"); // create exe name, width and height
    SetTargetFPS(60); // set fps

    SQLConnect(); // connect to the mysql server
    SQLCreateDBs(); // create the needed databases for this program
    SQLCreateTables(); // create tables in databases
    Textures *t = new Textures; // create a pointer to an anonymous object of class Textures to use
    t->load2DTextures(); // load all textures with their .png values
    while (!WindowShouldClose())
    {
        BeginDrawing();
        if (!flagCreateOne) // if signup page is not activated
        {
            t->drawLoginTextures(t); //draw login textures
            flagsChangeLogIn(t); // handle flags changing conditions for login
        }
        else
        {
            t->drawSignUpTextures(t);
            flagsChangeSignUp(t); // handle flags changing conditions for signup
            firstNameInput(t); // first anme input function
            lastNameInput(t); // last name input function
        }
        usernameInput(t); // get username input
        passwordInput(t); // get password input after username input
        buttonsLogInSignUp(t); // create an account and log in buttons checkup
        if (flagIsRegistered) // if you are already registered and you click log in button
        {
            SQLCreateFinanceTables(username); // create tables for the main program in the finance db
            SQLGetLastFourTransactions(lastFourTransactions, username);
            break; // go the survey if you are logged in           
        }
        EndDrawing();
    }
    flagShowQuestionaire = (SQLIncreaseAndReturnLogInCount(username) <= 1); // boolean to store the result 
    string getFirstName = SQLGetFirstName(username), getLastName = SQLGetLastName(username); // get first, last name and balance
    getBalance = SQLGetBalance(username); // get initial balance here to check if it hasn't been set
    while (!WindowShouldClose())
    {
        BeginDrawing();

        if (flagShowQuestionaire || getBalance == "NULL") // if this is your first login or you haven't entered a balance show the questionaire about your financial situation , else do the main program
        {           
            questions(t); // questionaire function
        }    
        else
        {
            if (!flagAvgCalculated)
            {
                avgIncomeLastThreeMonths = SQLGetAverageIncomeLastThreeMonths(username); // get question 3 answer
                avgSpendingsLastThreeMonths = SQLGetAverageSpendingsLastThreeMonths(username); // get question 4 answer
                avgIncome3 = to_string(avgIncomeLastThreeMonths); // get them into integers
                avgSpendings3 = to_string(avgSpendingsLastThreeMonths);
                flagAvgCalculated = 1;
            }
            if (balanceChanged) // if your balance has changed flag
            {
                getBalance = SQLGetBalance(username); // if balance is changed, a flag in dashboardPlus is set to show us that we need to update the getBalance string
                balanceChanged = 0; //reset the flag to be ready for the next query
            }
            t->drawDashboardTextures(t, getFirstName, getLastName, getBalance, avgIncome3, avgSpendings3);
            flagsDashboard(t); // flag handling function for dashboard page
            dashboardPlus(t); // plus button fucntion
            dashboardMinus(t); // minus function function
        }

        EndDrawing();
    }
    SQLCreateAndSaveLastFourTransactions(lastFourTransactions,username); // save lastFourTransactions array into a sql table
    t->unload2DTextures(); // unload all textures(pictures)
    SQLDelete(); // delete all ptrs associated with the cpp connector
    delete t; // delete the instance to the Textures class
}



