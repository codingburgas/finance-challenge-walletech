#include "../Include/Questions.h"
#include "../Include/SQL.h"
bool flagQuestion[4] = {1,0}; // initalize all values with 1
bool flagOptions[4] = {0}; // initialize all values with 0
bool flagTypeHere = 0;
bool flagQuestionOTT[3][3] = { {},{},{} }; // initialize all default values with 0
bool flagShowQuestionaire = 0;
string balance;
string getBalance; // used to show balance later in the dashboard