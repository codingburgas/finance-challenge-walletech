#include "../Include/Dashboad.h"

bool flagPlus = 0, flagMinus = 0; // initialize flags for minus and plus buttons
string amount, date, description; // data from the make request tab
bool flagAmount = 0, flagDate = 0, flagDescription = 0; // flags for fields in make request tab
bool flagAmountEntered = 0, flagDescriptionEntered = 0, flagDateEntered = 0;
bool balanceChanged = 0;
string lastFourTransactions[4][3] = { {"NULL"},{"NULL"},{"NULL"},{"NULL"} };
int countI = 0, countJ = 0;