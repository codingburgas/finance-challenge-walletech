#include "../Include/SQL.h"

void SQLUpdateBalanceAfterExpense(string username, string date, string amount)
{
	stringstream conv; // convert amount from string into a double variable
	conv << amount;
	double convAmount;
	conv >> convAmount;

	con->setSchema("accounts"); // set database to accounts
	pstmt = con->prepareStatement("SELECT Balance FROM Accounts WHERE Username = ?"); // prepare a select statement
	pstmt->setString(1, username); // set username
	res = pstmt->executeQuery(); // get a result set with 1 or 0 possible rows

	double tableBalance;
	if (res->next())
	{
		tableBalance = res->getDouble("Balance"); // if there's a balanance asign it to another temp var
	}
	tableBalance -= convAmount; // calculate new balance for our account
	pstmt = con->prepareStatement("UPDATE Accounts SET Balance = ? WHERE Username = ?"); // prepare a set statement
	pstmt->setDouble(1, tableBalance); // set values
	pstmt->setString(2, username);
	pstmt->executeUpdate(); // execute the query
}