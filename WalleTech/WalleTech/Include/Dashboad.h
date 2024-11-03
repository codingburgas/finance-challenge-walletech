#pragma once
#include "Textures.h"
#include "pch.h"
void flagsDashboard(Textures*); // flags handling function for dashboard

extern bool flagPlus, flagMinus; // flags to know if a button is clicked or a tab is opened

void dashboardPlus(Textures* t); // dashboard plus button
void dashboardMinus(Textures* t); // dashboard minus button

extern string amount, date, description; // strings which will be entered in the make request tab and sent to the sql server

extern bool flagAmount, flagDate, flagDescription; // flags for each field in the make request tab

extern bool flagAmountEntered, flagDescriptionEntered, flagDateEntered; // flags to know if amount, description,date have been entered

extern bool balanceChanged; // flag to know if out balance has been changed

extern string lastFourTransactions[4][3]; // array to hold data about our four recent quries

extern int countI, countJ; // counters used to insert data in the lastFourTransactions array
