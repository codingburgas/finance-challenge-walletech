#include "../Include/Textures.h"
#include "../Include/Dashboad.h"
void Textures::load2DTextures()
{
	logIn1 = LoadTexture("pictures/login1.png"); // load all textures
	blank = LoadTexture("pictures/blank.png");
	blankUsernamePassword = LoadTexture("pictures/blankUsername.png");
	pleaseRegisterMessage = LoadTexture("pictures/PleaseRegister.png");
	blankLogInButton = LoadTexture("pictures/blankLogIn.png");
	blankCreateOne = LoadTexture("pictures/blankCreateOne.png");
	blankCreateAnAccount = LoadTexture("pictures/createAnAccount.png");
	blankFirstLastName = LoadTexture("pictures/blankFirstLastName.png");
	takenPleaseTryAgain = LoadTexture("pictures/TakenPleaseTryAgain.png");
	question1 = LoadTexture("pictures/question1.png");
    question2 = LoadTexture("pictures/question2.png");
    question3 = LoadTexture("pictures/question3.png");
    question4 = LoadTexture("pictures/question4.png");
	blankNext = LoadTexture("pictures/blankNext.png");
	dot = LoadTexture("pictures/dot.png");
	blankTypeHere = LoadTexture("pictures/blankTypeHere.png");
	dashboard = LoadTexture("pictures/dashboard.png");
	blankPlusMinus = LoadTexture("pictures/blankPlusMinus.png");
	makeRequest = LoadTexture("pictures/makeRequest.png");
	blankCancelSubmit = LoadTexture("pictures/blankCancelSubmit.png");
	blankAmountDateDescription = LoadTexture("pictures/blankAmountDateDescription.png");
}

void Textures::unload2DTextures()
{
	UnloadTexture(logIn1); // unload all textures
	UnloadTexture(blank);
	UnloadTexture(blankUsernamePassword);
	UnloadTexture(pleaseRegisterMessage);
	UnloadTexture(blankLogInButton);
	UnloadTexture(blankCreateOne);
	UnloadTexture(blankCreateAnAccount);
	UnloadTexture(blankFirstLastName);
	UnloadTexture(takenPleaseTryAgain);
	UnloadTexture(question1);
	UnloadTexture(question2);
	UnloadTexture(question3);
	UnloadTexture(question4);
	UnloadTexture(blankNext);
	UnloadTexture(dot);
	UnloadTexture(blankTypeHere);
	UnloadTexture(dashboard);
	UnloadTexture(blankPlusMinus);
	UnloadTexture(makeRequest);
	UnloadTexture(blankCancelSubmit);
	UnloadTexture(blankAmountDateDescription);
}

void Textures::drawLoginTextures(Textures* t)
{
	DrawTexture(t->logIn1, 0, 0, RAYWHITE); // Main screen print
	DrawTexture(t->blank, 759, 292, BLANK); // Username blank print
	DrawTexture(t->blank, 765, 370, BLANK); // Password blank print
	DrawTexture(t->blankLogInButton, 759, 595, BLANK); // login blank print
	DrawTexture(t->blankCreateOne, 913, 135, BLANK); // create one blank print
}
void Textures::drawSignUpTextures(Textures* t)
{
	DrawTexture(t->blankCreateAnAccount, 0, 0, RAYWHITE);
	DrawTexture(t->blankFirstLastName, 759, 255, BLANK); // first name blank
	DrawTexture(t->blankFirstLastName, 953, 255, BLANK); // last name blank
	DrawTexture(t->blank, 764, 335, BLANK); // Username blank print
	DrawTexture(t->blank, 770, 415, BLANK); // Password blank print
	DrawTexture(t->blankLogInButton, 759, 595, BLANK); // create an account blank print
	DrawTexture(t->blankCreateOne, 950, 132, BLANK); // log in blank print
}
void Textures::drawDashboardTextures(Textures* t, string firstName, string lastName, string balance,string avgI3,string avgS3)
{
	DrawTexture(t->dashboard, 0, 0, RAYWHITE); // main screen 
	DrawText(balance.c_str(), 308, 251, 50, BLACK); // balance show
	DrawText(firstName.c_str(), 330, 35, 30, BLACK); // first name next to the Hello ...

	DrawText(firstName.c_str(), 1110, 23, 20, BLACK); // first and last name in the right part
	DrawText(lastName.c_str(), 1110, 40, 20, BLACK);

	DrawTexture(t->blankPlusMinus, 598, 252, BLANK); // plus
	DrawTexture(t->blankPlusMinus, 670, 252, BLANK); // minus

	DrawText(lastFourTransactions[0][0].c_str(), 800, 250, 20, BLACK); // recent transactions data show
	DrawText(lastFourTransactions[0][1].c_str(), 945, 250, 20, BLACK);
	DrawText(lastFourTransactions[0][2].c_str(), 1103, 250, 20, BLACK);

	DrawText(lastFourTransactions[1][0].c_str(), 800, 380, 20, BLACK);
	DrawText(lastFourTransactions[1][1].c_str(), 945, 380, 20, BLACK);
	DrawText(lastFourTransactions[1][2].c_str(), 1103, 380, 20, BLACK);

	DrawText(lastFourTransactions[2][0].c_str(), 800, 510, 20, BLACK);
	DrawText(lastFourTransactions[2][1].c_str(), 945, 510, 20, BLACK);
	DrawText(lastFourTransactions[2][2].c_str(), 1103, 510, 20, BLACK);

	DrawText(lastFourTransactions[3][0].c_str(), 800, 640, 20, BLACK);
	DrawText(lastFourTransactions[3][1].c_str(), 945, 640, 20, BLACK);
	DrawText(lastFourTransactions[3][2].c_str(), 1103, 640, 20, BLACK);

	DrawText((avgI3 + "K").c_str(), 310, 523, 40, BLACK); //draw average income and spendings from last 3 months
	DrawText((avgS3 + "K").c_str(), 310, 630, 40, BLACK);
} 

 int avgIncomeLastThreeMonths; // declare avgIncome/Spendings values
 int avgSpendingsLastThreeMonths;
string avgIncome3, avgSpendings3;
bool flagAvgCalculated = 0;