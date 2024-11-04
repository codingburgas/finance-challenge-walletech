#include "../Include/SQL.h"

void SQLUpdateBalanceAfterRevenue(string username,string date,string amount)
{
	stringstream conv; // convert amount value into a double temp variable
	conv << amount;
	double convAmount;
	conv >> convAmount;

	con->setSchema("accounts"); //set db to accounts
	pstmt = con->prepareStatement("SELECT Balance FROM Accounts WHERE Username = ?"); // prepare a select statement
	pstmt->setString(1, username); // set value
	res = pstmt->executeQuery(); // execute the statement

	double tableBalance; // 
	if (res->next())
	{
		tableBalance = res->getDouble("Balance"); // get current balance of our account
	}
	tableBalance += convAmount; // calculate new balance
	pstmt = con->prepareStatement("UPDATE Accounts SET Balance = ? WHERE Username = ?"); // update our balance
	pstmt->setDouble(1,tableBalance);
	pstmt->setString(2, username);
	pstmt->executeUpdate();
}