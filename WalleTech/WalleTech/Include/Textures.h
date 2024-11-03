#pragma once
#include "raylib.h"
#include "pch.h"
class Textures
{
public:
	Texture2D logIn1;
	Texture2D blank;
	Texture2D blankUsernamePassword;
	Texture2D pleaseRegisterMessage;
	Texture2D blankLogInButton;
	Texture2D blankCreateOne;
	Texture2D blankCreateAnAccount;
	Texture2D blankFirstLastName;
	Texture2D takenPleaseTryAgain;
	Texture2D question1;
	Texture2D question2;
	Texture2D question3;
	Texture2D question4;
	Texture2D blankNext;
	Texture2D dot;
	Texture2D blankTypeHere;
	Texture2D dashboard;
	Texture2D blankPlusMinus;
	Texture2D makeRequest;
	Texture2D blankCancelSubmit;
	Texture2D blankAmountDateDescription;
	void load2DTextures(); // load our textures
	void unload2DTextures(); // unload our textues

	void drawLoginTextures(Textures*); // draw login page
	void drawSignUpTextures(Textures*); // draw sign up page

    void drawDashboardTextures(Textures* t, string firstName, string lastName, string balance, string avgI3, string avgS3); // draw dashboard page

};

extern int avgIncomeLastThreeMonths;
extern int avgSpendingsLastThreeMonths;
extern string avgIncome3,avgSpendings3;

extern bool flagAvgCalculated;
