#include "../Include/SQL.h"

string SQLGetBalance(string username)
{
	con->setSchema("accounts"); // set database to accounts
	pstmt = con->prepareStatement("SELECT Balance FROM Accounts WHERE Username = ?"); // get balance with a select query by mathcing our username parameter
	pstmt->setString(1, username); // set the string in the prepared statement
	res = pstmt->executeQuery(); // execute the query
	
	double balance;
	if (res->next())
		if (res->getDouble("Balance") == 0.00) // return null if there's no balance
			return "NULL";

		else
			balance = res->getDouble("Balance"); // assign Balance of our account to balance if there's such account
	
	stringstream conv; // using sstream to convert double to string 
	conv << balance;
	string convBalance;
	conv >> convBalance;
	return convBalance;
}
// DrawText works with const char*, we need to return a string and use it with .c_str() so it can work

/*

string SQLGetBalance(string username)
{
	con->setSchema("accounts"); // set database to accounts
	pstmt = con->prepareStatement("SELECT Balance FROM Accounts WHERE Username = ?"); // get balance with a select query by mathcing our username parameter
	pstmt->setString(1, username); // set the string in the prepared statement
	res = pstmt->executeQuery(); // execute the query

	double balance;
	if (res->next())
		balance = res->getDouble("Balance"); // assign Balance of our account to balance if there's such account
	else
		return "NULL"; // return null if there's no balance

	stringstream conv; // using sstream to convert double to string
	conv << balance;
	string convBalance;
	conv >> convBalance;
	return convBalance;
}
*/